#pragma once
#include "repository.h"

class Service{
    private:
        Repository repository;
        bool mode_A = false;
        bool mode_B = false;
        int saved_tasks_index = 0;

    public:
        void set_mode(char mode);
        int add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision);
        int add_to_servant_list(Task current_task);
        int update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision);
        int remove(std::string task_title);
        bool task_duplicate(std::string title);
        int get_number_of_tasks();
        int get_number_of_saved_tasks();
        DynamicVector<Task> get_list_of_tasks()const;
        DynamicVector<Task> get_list_of_saved_tasks()const;
        DynamicVector<Task> get_list_by_type_and_times_performed(std::string type, int times_performed)const;
        Task next();
        Task current_task();
        int get_mode();
};
