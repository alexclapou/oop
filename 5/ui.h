#pragma once
#include <vector>
#include "service.h"

class UI{
    public:
        Service service;
        void start();
    private:
    void read_command(char input_command[], std::string &function, std::string &function_arguments);
    bool check_input_add_update_function(std::string function_arguments, std::string &title, std::string &type, tm &last_performed_date, int &times_performed, std::string &vision);
    bool check_for_string(std::string string_to_check, int &index, std::string &string_copied);
    bool check_for_date(std::string string_to_check, int &index, tm &last_performed_date);
    bool check_if_number(std::string string_to_check, int &index, int &times_performed_copied); 
    void erase_spaces_at_end(std::string &string_with_spaces);
    void list();
};
