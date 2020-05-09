#include "ui.h"
#include <sstream>
#include <iostream>

void UI::start(){
    while(1){
        std::string function, function_arguments;
        char input_command[1001];
        read_command(input_command, function, function_arguments);
        if(function == "add"){
            function_arguments.erase(function_arguments.begin());
            std::vector<std::string> arg = tokenize(function_arguments);
            std::cout<<arg[0]<<" "<<arg[1]<<" "<<arg[2]<<" "<<arg[3]<<" "<<arg[4];
            int q = stoi(arg[1]);
            int p = stoi(arg[3]);
            int x = stoi(arg[4]);
            Helicopter h(q, arg[2], p, x);
            service.add(h);
        }
        if(function == "exit")
            return;
        if(function == "list"){
            auto q = service.get_list_of_aircrafts();
            for(Aircraft a:q)
                std::cout<<a.get_model()<<'\n';
        }
    }
}

std::vector<std::string> tokenize(std::string line)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(line);
    while (getline(ss, token, ' '))
        result.push_back(token);
    return result;
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

