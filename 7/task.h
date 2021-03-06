#pragma once
#include <string>
#include <vector>
#include <iostream>

class Task{
    private:
        std::string title;
        std::string type;
        tm last_performed_date;
         int times_performed;
        std::string vision;

    public:
        Task(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision);
        Task();

        std::string get_title()const;
        std::string get_type()const;
        int get_last_performed_day()const;
        int get_last_performed_month()const;
        int get_last_performed_year()const;
        int get_times_performed()const;
        std::string get_vision()const;
        void set_last_performed_day(int day);
        void set_last_performed_month(int month);
        void set_last_performed_year(int year);
        void set_title(std::string new_title);
        void set_type(std::string new_type);
        void set_times_performed( int new_times_performed);
        void set_vision(std::string new_vision);
        std::string to_string();
        bool operator==(const Task first_task);
        bool operator!=(const Task first_task);
        void operator=(const Task task);
        std::string remove_not_needed_strings(std::string entire_line);
        friend std::ostream& operator<<(std::ostream& os, Task task_to_add);
        friend std::istream& operator>>(std::istream& is, Task &task_to_add);
};
