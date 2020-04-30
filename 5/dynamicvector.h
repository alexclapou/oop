#pragma once
#include "task.h"

class DynamicVector{
    private:
        Task *tasks;
         int capacity;
         int number_of_tasks;
    
    public:
        DynamicVector();
        DynamicVector(const DynamicVector &copy_dynamic_vector);
        int add(Task new_task);
        int remove(std::string task_title);
        int update(std::string title, std::string new_type, tm new_last_performed,  int new_times_performed, std::string new_vision);
        int search(std::string searching_title);
        bool is_full();
        int length();
        void resize();
        Task get_task(int position);
        Task operator[](int task_index);
        DynamicVector& operator=(const DynamicVector &copy_dynamic_vector);
        ~DynamicVector();
};
