#pragma once
#include "task.h"
#include <vector>
#include <algorithm>

class Repository{
    private:
        std::vector<Task> servant_task_list;
        std::string filepath;

    public:
        int add_file_data(Task task_to_add);
        int add_to_servant_list(Task task);
        int remove_file_data(std::string task_title);
        int update_file_data(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision);
        int get_number_of_tasks();
        int get_number_of_saved_tasks();
        bool task_duplicate(std::string title);
        Task get_task(int position);
        std::vector<Task> get_list_of_tasks();
        std::vector<Task> get_list_of_saved_tasks()const;
        int search_task_title(std::string title);
        void set_filepath(std::string new_filepath);
        bool filepath_exist();
        std::string get_filepath();
};
