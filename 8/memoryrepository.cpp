#include "memoryrepository.h"

int MemoryRepository::add(Task task){
    task_list.push_back(task);
}

int MemoryRepository::remove(std::string title){
    int index = search_task_title(title);
    task_list.erase(task_list.begin()+index);
}

int MemoryRepository::update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision){
    int task_to_update_index;
    Task new_task(title, new_type, new_last_performed, new_times_performed, new_vision);

    task_to_update_index = search_task_title(title);
    task_list[task_to_update_index] = new_task;
}

unsigned int MemoryRepository::get_number_of_tasks(){
    return task_list.size();
}

Task MemoryRepository::get_task(unsigned int position){
    return task_list[position];
}

std::vector<Task> MemoryRepository::get_list_of_tasks(){
    return task_list;
}

int MemoryRepository::search_task_title(std::string title){
    for(int i = 0; i < task_list.size(); i++)
        if(task_list[i].get_title() == title)
            return i;
    return -1;
}
