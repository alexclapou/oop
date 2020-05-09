#include <iostream>
#include <fstream>
#include "ui.h"

void read_command(char input_command[], std::string &function, std::string &function_arguments)
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
    function_arguments.erase(function_arguments.begin());
}

int main()
{
    std::string filelocation, filepath;
    char input_command1[1001];
    read_command(input_command1, filelocation, filepath);
    std::string mylistlocation, mylistpath;
    char input_command2[1001];
    read_command(input_command2, mylistlocation, mylistpath);
    if(mylistpath.substr(mylistpath.find_last_of(".")+1) == "csv"){
        CSVRepository r{filepath, mylistpath};
        Service s{r};
        UI ui{s};
        ui.start();
    }
    else{
        HTMLRepository r{filepath, mylistpath};
        Service s{r};
        UI ui{s};
        ui.start();
    }
}
