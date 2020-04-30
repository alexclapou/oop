#pragma once
#include "dynamicvector.cpp"

class Repository{
    private:
        DynamicVector<Task> dynamic_vector;
        DynamicVector<Task> servant_task_list;

    public:
        int add(Task new_task);
        int add_to_servant_list(Task task);
        int remove(std::string task_title);
        int update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision);
        int get_number_of_tasks();
        int get_number_of_saved_tasks();
        bool task_duplicate(std::string title);
        Task get_task(int position);
        DynamicVector<Task> get_list_of_tasks()const;
        DynamicVector<Task> get_list_of_saved_tasks()const;
        Task operator[](int task_index);
        int search_task_title(std::string title);
};
