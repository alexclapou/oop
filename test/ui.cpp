#include "ui.h"

void UI::start(){
    while(1){
        std::string function, function_arguments;
        char input_command[1001];
        read_command(input_command, function, function_arguments);
        if(function_arguments.size() != 0)
            function_arguments.erase(function_arguments.begin());
        if(function == "add"){
            std::vector<std::string> arg = tokenize(function_arguments, ',');
            Book book{arg[0], stoi(arg[1])};
            service.add(book);
        }
        if(function == "save"){
            std::vector<std::string> arg = tokenize(function_arguments, ',');
            Book book{arg[0], stoi(arg[1])};
            service.save(book);
        }
        if(function == "exit")
            return;
    }
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

