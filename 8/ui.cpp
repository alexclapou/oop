#include "ui.h"
#include <cassert>
#include <fstream>
void UI::start()
{
    os = true;
    while(true){
        std::string function, function_arguments;
        char input_command[1001];
        read_command(input_command, function, function_arguments);
        if(function == "mode"){
            if(function_arguments.size() == 1){
                char mode;

                mode = function_arguments[0];
                service.set_mode(mode);
            }
            else
                service.set_mode('X');
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
            try{
                if(valid_arguments == 0)
                    throw 12;
                service.add(title, type, last_performed_date, times_performed, vision);
            }
            catch(std::string no_mode){
                std::cout<<no_mode;
            }
            catch(ValidateTask &exception){
                std::cout<<exception.what();
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
            catch(int){
                std::cout<<"invalid arguments\n";
            }
        }
        if(function == "next"){
            try{
                if(service.get_mode() == -1)
                    std::cout<<service.next().to_string()<<'\n';
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
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
            try{
                if(valid_arguments == 0)
                   throw 12;
                service.update(title, type, last_performed_date, times_performed, vision);
            }
            catch(std::string no_mode){
                std::cout<<no_mode;
            }
            catch(ValidateTask &exception){
                std::cout<<exception.what();
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
            catch(int){
                std::cout<<"invalid arguments\n";
            }
        }
        if(function == "delete"){
            for(char character:function_arguments)
                if(character == ' ')
                    function_arguments.erase(function_arguments.begin());
            try{
                service.remove(function_arguments);
            }
            catch(std::string no_mode){
                std::cout<<no_mode;
            }
            catch(ValidateTask &exception){
                std::cout<<exception.what();
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
        }
        if(function == "save"){
            for(char character:function_arguments)
                if(character == ' ')
                    function_arguments.erase(function_arguments.begin());
            erase_spaces_at_end(function_arguments);
            Task task_pointed_now;
            try{
                task_pointed_now = service.current_task(function_arguments);
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
            try{
                service.add_to_servant_list(task_pointed_now);
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
        }
        if(function == "mylist"){
            std::string what_to_print = "saved tasks";
            list(what_to_print);
        }
        if(function == "list"){
            if(function_arguments.size() == 0){
                std::string what_to_print = "tasks";
                try{
                    list(what_to_print);
                }
                catch(RepositoryException &exception){
                    std::cout<<exception.what();
                }
            }
            else{
                std::string type, what_to_print;
                int times_performed, index;
                bool type_ok, times_performed_ok;

                index = 0;
                times_performed = 0;
                what_to_print = "by type and times performed";
                type_ok = check_for_string(function_arguments, index, type);
                times_performed_ok = check_if_number(function_arguments, index, times_performed);
                if(type_ok && times_performed_ok)
                    try{
                        list(what_to_print, type, times_performed);
                    }
                catch(RepositoryException &exception){
                    std::cout<<exception.what();
                }
            }
        }
        if(function == "fileLocation"){
            function_arguments.erase(function_arguments.begin());
            try{
                service.set_filepath(function_arguments);
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
        }
        if(function == "mylistLocation"){
            function_arguments.erase(function_arguments.begin());
            try{
                service.set_mylistpath(function_arguments);
            }
            catch(RepositoryException &exception){
                std::cout<<exception.what();
            }
        }
        if(function == "exit")
            break;
        if (function == "changeos")
            os = !os;
    }
}

void UI::list(std::string what_to_print, std::string type, int times_performed)
{
    std::vector<Task> tasks;
    
   if(what_to_print == "tasks"){
       if(service.get_mode() != 1){
           std::cout<<"No!\n";
           return;
       }
       tasks = service.get_list_of_tasks();
   }
   if(what_to_print == "saved tasks"){
       if(service.get_mode() != -1){
           std::cout<<"No!\n";
           return;
       }
       std::string system_command;

       system_command = service.get_mylistpath();
       if(service.get_extension() == ".csv")
           if(os)
            system_command = "notepad \"" +  system_command +"\"";
           else
               system_command = "xed \"" + system_command + "\"";
       else
           if(os)
            system_command = "start chrome \"" + system_command + "\"";
           else
            system_command = "google-chrome \"" + system_command + "\"";
       system(system_command.c_str());
       return;
   }
   if(what_to_print == "by type and times performed"){
       if(service.get_mode() != -1 || (type == "No Type" && times_performed == -1)){
           std::cout<<"No!\n";
           return;
       }
       tasks = service.get_list_by_type_and_times_performed(type, times_performed);
   }
   for(Task task:tasks){
       std::string entire_task;
       
       entire_task = task.to_string();
       std::cout<<entire_task<<'\n';
   }
}
void UI::erase_spaces_at_end(std::string &string_with_spaces)
{
    int end;

    end = string_with_spaces.size();
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
    std::string times_performed = "";
    bool is_number;

    unsigned_index = index;
    if(unsigned_index == string_to_check.size())
        return false;
    while(string_to_check[index] == ' ' || string_to_check[index] == ',')
        index++;
    for(; string_to_check[index] != ',' && string_to_check[index] != '\0' && string_to_check[index] != ' '; index++)
        times_performed += string_to_check[index];
    while(string_to_check[index] == ' ')
        index++;
    index++;
    is_number =  !times_performed.empty() && std::find_if(times_performed.begin(),
            times_performed.end(), [](char c){return !std::isdigit(c);}) == times_performed.end();
    if(is_number){
        times_performed_copied = stoi(times_performed);
        return true;
    }
    return false;
}

bool UI::check_for_string(std::string string_to_check, int &index, std::string &string_copied)
{
    unsigned int unsigned_index;

    unsigned_index = index;
    if(unsigned_index == string_to_check.size())
        return false;
    while(string_to_check[index] == ' ')
        index++;
    for(; string_to_check[index] != ',' && string_to_check[index] != '\0'; index++)
        string_copied += string_to_check[index];
    index++;
    if(string_copied.empty())
        return false;
    return true;
}

bool UI::check_for_date(std::string string_to_check, int &index, tm &date)
{
    if(string_to_check.size() - index < 10)
        return false;
    std::string get_date_as_string = "";
    int digits;

    digits = 0;
    while(string_to_check[index] == ' '){
        index++;
    }
    while(string_to_check[index] != ' ' && string_to_check[index] != ','){
        if(string_to_check[index] == '-')
            if(digits == 2)
                digits = -1;
            else
                return false;
        get_date_as_string += string_to_check[index];
        index++;
        digits++;
    }
    while(string_to_check[index] != ',')
        index++;
    //strptime(get_date_as_string.c_str(), "%m-%d-%Y", &date);
    set_date_as_tm(get_date_as_string, date);
    if(date.tm_mday > 31 || date.tm_mon > 12 || date.tm_mday < 0 || date.tm_mon < 0)
        return false;
    return true;
}

void UI::read_command(char input_command[], std::string &function, std::string &function_arguments)
{
    int i, function_found;

    i = 0;
    function_found = 0;
    std::cin.getline(input_command, 1000);

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
