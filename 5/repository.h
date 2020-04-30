#pragma once
#include "dynamicvector.h"

class Repository{
    private:
        DynamicVector dynamic_vector;

    public:
        int add(Task new_task);
        int remove(std::string task_title);
        int update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision);
        int get_number_of_tasks();
        bool task_duplicate(std::string title);
        Task get_task(int position);
        DynamicVector get_list_of_tasks()const;
        Task operator[](int task_index);
};
