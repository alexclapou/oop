#pragma once
#include "repository.h"

class Service{
    private:
        Repository repository;
        bool mode_A = false;

    public:
        void set_mode(char mode);
        int add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision);
        int update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision);
        int remove(std::string task_title);
        bool task_duplicate(std::string title);
        int get_number_of_tasks();
        DynamicVector get_list_of_tasks()const;
        bool get_mode();
};
