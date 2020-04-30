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

DynamicVector<Task> Service::get_list_of_saved_tasks()const
{
    return repository.get_list_of_saved_tasks();
}

DynamicVector<Task> Service::get_list_of_tasks()const
{
    return repository.get_list_of_tasks();
}

DynamicVector<Task> Service::get_list_by_type_and_times_performed(std::string type, int times_performed)const
{
    DynamicVector<Task> tasks_by_type_and_times_performed;
    DynamicVector<Task> all_tasks = repository.get_list_of_tasks();

    for(int i = 0; i < all_tasks.length(); i++)
        if(type == all_tasks[i].get_type() && times_performed > all_tasks[i].get_times_performed())
            tasks_by_type_and_times_performed.add(all_tasks[i]);
    return tasks_by_type_and_times_performed;
}

int Service::add_to_servant_list(Task current_task)
{
    if(mode_B == false)
        return 0;
    return repository.add_to_servant_list(current_task);
}

Task Service::current_task()
{
    DynamicVector<Task> all_tasks = repository.get_list_of_tasks();
    if(saved_tasks_index == all_tasks.length())
        saved_tasks_index = 0;
    return repository.get_task(saved_tasks_index);
}
Task Service::next()
{
    DynamicVector<Task> all_tasks = repository.get_list_of_tasks();
    if(saved_tasks_index == all_tasks.length())
        saved_tasks_index = 0;
    return all_tasks.get_task(saved_tasks_index++);
}

int Service::add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision)
{
    if(task_duplicate(title) || mode_A != 1)
          return 0;
            //std::cout<<title<<" "<<type<<" "<<last_performed_date.tm_mon<<"-"<<last_performed_date.tm_mday<<"-"<<last_performed_date.tm_year<<" "<<times_performed<<" "<<vision<<"\n";
    Task task(title, type, last_performed_date, times_performed, vision);
    return repository.add(task);
}

int Service::update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision)
{
    if(!task_duplicate(title) || mode_A != 1)
        return 0;
    return repository.update(title, new_type, new_last_performed_date, new_times_performed, new_vision);
}

int Service::remove(std::string task_title)
{
    //std::cout<<task_title<<'\n'<<task_title<<'\n';
    if(!task_duplicate(task_title) || mode_A != 1){
        return 0;
    }
    return repository.remove(task_title);
}

bool Service::task_duplicate(std::string title)
{
    return repository.task_duplicate(title);
}

int Service::get_number_of_saved_tasks()
{
    return repository.get_number_of_saved_tasks();
}

int Service::get_number_of_tasks()
{
    return repository.get_number_of_tasks();
}
