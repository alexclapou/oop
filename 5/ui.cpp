#include "ui.h"
void UI::start()
{
    while(true){
        std::string function, function_arguments;
        char input_command[100];
        read_command(input_command, function, function_arguments);
        if(function == "mode"){
            if(function_arguments.length() == 1){
                char mode;

                mode = function_arguments[0];
                service.set_mode(mode);
            }
        }
        if(function == "add"){
            std::string title, type, vision;
            int times_performed;
            tm last_performed_date;
            bool valid_arguments;

            times_performed = 0;
            valid_arguments = check_input_add_update_function(function_arguments, title, type, last_performed_date, times_performed, vision);
            erase_spaces_at_end(title);
            erase_spaces_at_end(type);
            erase_spaces_at_end(vision);
            //std::cout<<title<<" "<<type<<" "<<last_performed_date.tm_mon<<"-"<<last_performed_date.tm_mday<<"-"<<last_performed_date.tm_year<<" "<<vision;
            if(service.add(title, type, last_performed_date, times_performed, vision) == 0 || valid_arguments == 0)
                std::cout<<"No!\n";
        }
        if(function == "update"){
            std::string title, type, vision;
            tm last_performed_date;
            int times_performed;
            bool valid_arguments;

            times_performed = 0;
            valid_arguments = check_input_add_update_function(function_arguments, title, type, last_performed_date, times_performed, vision);
            erase_spaces_at_end(title);
            erase_spaces_at_end(type);
            erase_spaces_at_end(vision);
            if(service.update(title, type, last_performed_date, times_performed, vision) == 0 || valid_arguments == 0)
                std::cout<<"No!\n";
        }
        if(function == "delete"){
            for(int i = 0; function_arguments[i] == ' '; i++)
                function_arguments.erase(function_arguments.begin());
            if(service.remove(function_arguments) == 0)
                std::cout<<"No!\n";
        }
        if(function == "list")
            list();
        if(function == "exit")
            break;
    }
}

void UI::list()
{
    DynamicVector tasks;

   tasks = service.get_list_of_tasks();
   for(int i = 0; i < tasks.length(); i++){
       std::string entire_task;
       entire_task = tasks[i].to_string();
       std::cout<<entire_task<<'\n';
        //std::cout<<"TITLE: "<<tasks[i].get_title()<<" TYPE: "<<tasks[i].get_type()<<" LAST PERFORMED DATE: "<<tasks[i].get_last_performed_month()<<"-"<<tasks[i].get_last_performed_day()<<"-"<<tasks[i].get_last_performed_year()<<" TIMES PERFORMED: "<<tasks[i].get_times_performed()<<" VISION: "<<tasks[i].get_vision()<<'\n';
   }
}
void UI::erase_spaces_at_end(std::string &string_with_spaces)
{
    int end;

    end = string_with_spaces.length();
    end--;
    while(string_with_spaces[end] == ' '){
        string_with_spaces.erase(string_with_spaces.begin()+end);
        end--;
    }
}

bool UI::check_input_add_update_function(std::string function_arguments, std::string &title, std::string &type, tm &last_performed_date, int &times_performed, std::string &vision)
{
    int index;
    bool title_ok, type_ok, date_ok, times_performed_ok, vision_ok;

    index = 0;
    //check title
    title_ok = check_for_string(function_arguments, index, title);
    type_ok = check_for_string(function_arguments, index, type);
    date_ok = check_for_date(function_arguments, index, last_performed_date);
    times_performed_ok = check_if_number(function_arguments, index, times_performed);
    vision_ok = check_for_string(function_arguments, index, vision);
    if(title_ok && type_ok && date_ok && times_performed_ok && vision_ok)
        return true;
    return false;
}

bool UI::check_if_number(std::string string_to_check, int &index, int &times_performed_copied)
{
    unsigned int unsigned_index;

    unsigned_index = index;
    if(unsigned_index == string_to_check.length())
        return false;
    while(string_to_check[index] == ' ')
        index++;
    for(; string_to_check[index] != ',' && string_to_check[index] != '\0' && string_to_check[index] != ' '; index++)
            times_performed_copied = times_performed_copied * 10 + (string_to_check[index]-'0');
    while(string_to_check[index] == ' ')
        index++;
    index++;
    return true;
}


bool UI::check_for_string(std::string string_to_check, int &index, std::string &string_copied)
{
    unsigned int unsigned_index;

    unsigned_index = index;
    if(unsigned_index == string_to_check.length())
        return false;
    while(string_to_check[index] == ' ')
        index++;
    for(; string_to_check[index] != ',' && string_to_check[index] != '\0'; index++)
        string_copied += string_to_check[index];
    index++;
    return true;
}

bool UI::check_for_date(std::string string_to_check, int &index, tm &date)
{
    if(string_to_check.length() - index < 10)
        return false;
    int day_digit, month_digit, year_digit, index_for_separating;

    while(string_to_check[index] == ' ')
        index++;
    year_digit = 4;
    day_digit = month_digit = 2;
    index_for_separating = 0;
    date.tm_year = date.tm_mon = date.tm_mday = 0;
    for(; string_to_check[index] != ',' && string_to_check[index] != '\0'; index++){
        if(index_for_separating < 2)
            date.tm_mon = date.tm_mon * 10 + (string_to_check[index]-'0');
        else{
            if(index_for_separating > 2 && index_for_separating < 5)
                date.tm_mday = date.tm_mday * 10 + (string_to_check[index]-'0');
            else if(index_for_separating > 5)
                date.tm_year = date.tm_year * 10 + (string_to_check[index]-'0');
        }
        if(month_digit > 0){
            if(!isdigit(string_to_check[index]) && string_to_check[index] != '-')
                return false;
            month_digit--;
        }
        else{
            if(day_digit > 0){
                if(!isdigit(string_to_check[index]) && string_to_check[index] != '-')
                    return false;
                day_digit--;
            }
            else if(year_digit > 0){
                if(!isdigit(string_to_check[index]) && string_to_check[index] != '-')
                    return false;
                year_digit--;
            }
        }
        index_for_separating++;
    }
    index++;
    if(date.tm_mday > 31 || date.tm_mon > 12 || date.tm_mday < 0 || date.tm_mon < 0)
        return false;
    return true;
}

void UI::read_command(char input_command[], std::string &function, std::string &function_arguments)
{
    int i, function_found;

    i = 0;
    function_found = 0;
    std::cin.getline(input_command, 100);
    while(input_command[i] != '\0'){
        if(input_command[i] == ' ' && function == "mode"){
            function_found = 1;
            i++;
        }
        else if(input_command[i] == ' ')
            function_found = 1;
        if(function_found == 0)
            function += input_command[i];
        else
            function_arguments += input_command[i];
        i++;
    }
}
