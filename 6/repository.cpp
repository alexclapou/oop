#include "repository.h"

int Repository::add(Task new_task)
{
    return dynamic_vector.add(new_task);
}

int Repository::add_to_servant_list(Task task)
{
    return servant_task_list.add(task);
}

int Repository::remove(std::string task_title)
{
    int task_index;

    task_index = search_task_title(task_title);
    return dynamic_vector.remove(task_index);
}

int Repository::update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision)
{
    int task_index;

    task_index = search_task_title(title);
    Task updated_task(title, new_type, new_last_performed, new_times_performed, new_vision);
    return dynamic_vector.update(updated_task, task_index);
}

int Repository::get_number_of_tasks()
{
    return dynamic_vector.length();
}

int Repository::get_number_of_saved_tasks()
{
    return servant_task_list.length();
}

Task Repository::operator[](int task_index)
{
    return dynamic_vector[task_index];
}

bool Repository::task_duplicate(std::string title)
{
    if(search_task_title(title) != -1)
        return true;
    return false;
}

DynamicVector<Task> Repository::get_list_of_tasks()const
{
    return dynamic_vector;    
}

DynamicVector<Task> Repository::get_list_of_saved_tasks()const
{
    return servant_task_list;
}

Task Repository::get_task(int position)
{
    return dynamic_vector.get_task(position);
}

int Repository::search_task_title(std::string title)
{
    DynamicVector<Task> tasks = get_list_of_tasks();
    for(int i = 0; i < tasks.length(); i++)
        if(title == tasks[i].get_title())
            return i;
    return -1;
}
