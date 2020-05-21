#pragma once
#include "repositoryexception.h"
#include "task.h"
#include <vector>
#include <algorithm>

class Repository{
    private:
        std::string filepath;
        std::string mylistpath;
        std::string mylist_extension;

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
        int search_task_title(std::string title);
        void set_filepath(std::string new_filepath);
        void set_mylistpath(std::string new_mylistpath);
        bool filepath_exist();
        bool mylistpath_exist();
        std::string get_mylistpath();
        std::string get_filepath();
        std::string get_extension();
        void write_to_html(Task task_to_add);
        void init_html_file();
};
