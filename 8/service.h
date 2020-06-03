#pragma once
#include "action.h"
#include "validatetask.h"
#include "memoryrepository.h"
#include "filerepository.h"
#include "csvrepository.h"
#include "htmlrepository.h"

class Service{
    private:
        std::vector<std::unique_ptr<Action>> undo_stack;
        std::vector<std::unique_ptr<Action>> redo_stack;
        Repository *main_repository;
        Repository *second_repository;
        bool mode_A = false;
        bool mode_B = false;
        unsigned int saved_tasks_index = 0;
        ValidateTask validator;
    public:
        Service();
        void undo();
        void redo();
        void set_mode(char mode);
        int add(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision);
        int add_to_servant_list(Task current_task);
        int update(std::string title, std::string new_type, tm new_last_performed_date,  int new_times_performed, std::string new_vision);
        int remove(std::string task_title);
        int get_number_of_tasks();
        int get_number_of_saved_tasks();
        std::vector<Task> get_list_of_tasks();
        std::vector<Task> get_list_of_saved_tasks();
        std::vector<Task> get_list_by_type_and_times_performed(std::string type, int times_performed);
        Task next();
        Task current_task(std::string title);
        int get_mode();
};
