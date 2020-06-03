#pragma once
#include "repository.h"

class MemoryRepository: public Repository{
    private:
        std::vector<Task> task_list;
    public:
        int add(Task task);
        int remove(std::string title);
        int update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision);
        unsigned int get_number_of_tasks();
        Task get_task(unsigned int position);
        std::vector<Task> get_list_of_tasks();
        int search_task_title(std::string title);
};
