#pragma once
#include "repository.h"
#include "repositoryexception.h"
#include "task.h"
#include <vector>
#include <algorithm>

class FileRepository: public Repository{
    private:
        std::string filepath;
    public:
        FileRepository(std::string _filepath):filepath{_filepath}{}
        int add(Task task_to_add);
        int remove(std::string task_title);
        int update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision);
        unsigned int get_number_of_tasks();
        Task get_task(unsigned int position);
        std::vector<Task> get_list_of_tasks();
        int search_task_title(std::string title);
        void set_filepath(std::string new_filepath);
        std::string get_filepath();
};
