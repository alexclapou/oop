#pragma once
#include <algorithm>
#include <vector>
#include "repositoryexception.h"
#include "task.h"
class Repository{
    public:
        virtual int add(Task task) = 0;
        virtual int remove(std::string title) = 0;
        virtual int update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision) = 0;
        virtual unsigned int get_number_of_tasks() = 0;
        virtual Task get_task(unsigned int position) = 0;
        virtual std::vector<Task> get_list_of_tasks() = 0;
        virtual int search_task_title(std::string title) = 0;
};
