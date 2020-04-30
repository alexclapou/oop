#include "service.h"
#include <iostream>

void Service::set_mode(char mode)
{
    if(mode == 'A')
        mode_A = true;
    else
        mode_A = false;
}

bool Service::get_mode()
{
    return mode_A;
}

DynamicVector Service::get_list_of_tasks()const
{
    return repository.get_list_of_tasks();
}

int Service::add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision)
{
    if(task_duplicate(title) || !mode_A)
        return 0;
            //std::cout<<title<<" "<<type<<" "<<last_performed_date.tm_mon<<"-"<<last_performed_date.tm_mday<<"-"<<last_performed_date.tm_year<<" "<<times_performed<<" "<<vision<<"\n";
    Task task(title, type, last_performed_date, times_performed, vision);
    return repository.add(task);
}

int Service::update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision)
{
    if(!task_duplicate(title) || !mode_A)
        return 0;
    return repository.update(title, new_type, new_last_performed_date, new_times_performed, new_vision);
}

int Service::remove(std::string task_title)
{
    //std::cout<<task_title<<'\n'<<task_title<<'\n';
    if(!task_duplicate(task_title) || !mode_A){
        return 0;
    }
    return repository.remove(task_title);
}

bool Service::task_duplicate(std::string title)
{
    return repository.task_duplicate(title);
}

int Service::get_number_of_tasks()
{
    return repository.get_number_of_tasks();
}
