#include "service.h"
#include <iostream>

void Service::set_mode(char mode)
{
    if(mode == 'A'){
        mode_A = true;
        mode_B = false;
    }
    if(mode == 'B'){
        mode_B = true;
        mode_A = false;
    }
    if(mode != 'B' && mode != 'A'){
        mode_A = false;
        mode_B = false;
    }
}

int Service::get_mode()
{
    if(mode_A)
        return 1;
    if(mode_B)
        return -1;
    return 0;
}

std::vector<Task> Service::get_list_of_tasks()
{
    return repository.get_list_of_tasks();
}

std::vector<Task> Service::get_list_by_type_and_times_performed(std::string type, int times_performed)
{
    std::vector<Task> tasks_by_type_and_times_performed;
    std::vector<Task> all_tasks = repository.get_list_of_tasks();
    std::copy_if(all_tasks.begin(), 
            all_tasks.end(), 
            std::back_inserter(tasks_by_type_and_times_performed), 
            [type, times_performed](Task task){return type == task.get_type() && times_performed > task.get_times_performed();});
    return tasks_by_type_and_times_performed;
}

int Service::add_to_servant_list(Task current_task)
{
    Task task;
    if(mode_B == false)
        throw std::string("mode B not selected\n");
    if(current_task == task)
        throw RepositoryException(std::string("there s no task with the given title\n"));
    return repository.add_to_servant_list(current_task);
}

Task Service::current_task(std::string title)
{
    int task_index;

    task_index = repository.search_task_title(title);
    if(task_index != -1)
        return repository.get_task(task_index);
    else{
        Task task;
        return task;
    }
}
Task Service::next()
{
    std::vector<Task> all_tasks = repository.get_list_of_tasks();
    if(saved_tasks_index == all_tasks.size())
        saved_tasks_index = 0;
    return all_tasks.at(saved_tasks_index++);
}

void Service::undo(){
    if(!undo_stack.size())
        throw std::length_error("no more undos\n");
    else{
        std::unique_ptr<Action> last_action = std::move(undo_stack.back());
        last_action->undo();
        redo_stack.push_back(std::move(last_action));
        undo_stack.pop_back();
    }
}

void Service::redo(){
    if(!redo_stack.size())
        throw std::length_error("no more redos\n");
    else{
        std::unique_ptr<Action> last_action = std::move(redo_stack.back());
        last_action->redo();
        undo_stack.push_back(std::move(last_action));
        redo_stack.pop_back();
    }
}

int Service::add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision)
{
    if(task_duplicate(title))
        throw RepositoryException(std::string("there s already a task with this title\n"));
    if(mode_A != true)
        throw std::string("mode A not selected\n");
    Task task_to_add(title, type, last_performed_date, times_performed, vision);
    validator.validate_task(task_to_add);
    //if we re here then we re ok with adding the given task
    std::unique_ptr<ActionAdd> new_action = std::make_unique<ActionAdd>(repository, task_to_add);
    undo_stack.push_back(std::move(new_action));
    //we changed something, clear the redo stack, we will fill it again when undo
    redo_stack.clear();
    return repository.add_file_data(task_to_add);
}

int Service::update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision)
{
    if(!task_duplicate(title))
        throw RepositoryException(std::string("there is no task with the given title\n"));
    if(mode_A != true)
        throw std::string("mode A not selected\n");
    Task task_to_be_validated(title, new_type, new_last_performed_date, new_times_performed, new_vision);
    validator.validate_task(task_to_be_validated);
    Task old_task;

    old_task = repository.get_task(repository.search_task_title(title));
    Task new_task(title, new_type, new_last_performed_date, new_times_performed, new_vision);
    std::unique_ptr<ActionUpdate> new_action = std::make_unique<ActionUpdate>(repository, old_task, new_task);
    undo_stack.push_back(std::move(new_action));
    redo_stack.clear();
    return repository.update_file_data(title, new_type, new_last_performed_date, new_times_performed, new_vision);
}

int Service::remove(std::string task_title)
{
    if(!task_duplicate(task_title))
        throw RepositoryException(std::string("there is no task with the given title\n"));
    if(mode_A != true)
        throw std::string("mode A not selected\n");

    //search->get_task
    int removed_element_position;
    Task task_removed;

    removed_element_position = repository.search_task_title(task_title);
    task_removed = repository.get_task(removed_element_position);
    std::cout<<task_removed.get_title();

    std::unique_ptr<ActionRemove> new_action = std::make_unique<ActionRemove>(repository, task_removed);
    undo_stack.push_back(std::move(new_action));
    redo_stack.clear();
    return repository.remove_file_data(task_title);
}

bool Service::task_duplicate(std::string title)
{
    return repository.task_duplicate(title);
}

int Service::get_number_of_tasks()
{
    return repository.get_number_of_tasks();
}

int Service::get_number_of_saved_tasks()
{
    return repository.get_number_of_saved_tasks();
}

void Service::set_filepath(std::string new_filepath)
{
    repository.set_filepath(new_filepath);
}

void Service::set_mylistpath(std::string new_mylistpath)
{
    repository.set_mylistpath(new_mylistpath);
}

std::string Service::get_filepath()
{
    return repository.get_filepath();
}

std::string Service::get_mylistpath()
{
    return repository.get_mylistpath();
}
std::string Service::get_extension()
{
    return repository.get_extension();
}
