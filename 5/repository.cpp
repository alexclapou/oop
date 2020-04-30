#include "repository.h"

int Repository::add(Task new_task)
{
    return dynamic_vector.add(new_task);
}

int Repository::remove(std::string task_title)
{
    return dynamic_vector.remove(task_title);
}

int Repository::update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision)
{
    return dynamic_vector.update(title, new_type, new_last_performed, new_times_performed, new_vision);
}

int Repository::get_number_of_tasks()
{
    return dynamic_vector.length();
}

Task Repository::operator[](int task_index)
{
    return dynamic_vector[task_index];
}

bool Repository::task_duplicate(std::string title)
{
    if(dynamic_vector.search(title) != -1)
        return true;
    return false;
}

DynamicVector Repository::get_list_of_tasks()const
{
    return dynamic_vector;    
}

Task Repository::get_task(int position)
{
    return dynamic_vector.get_task(position);
}
