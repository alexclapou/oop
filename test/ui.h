#pragma once
#include "service.h"
#include "domain.h"
#include <iostream>

class UI{
    private:
        Service &service;
        void read_command(char input_command[], std::string &function, std::string &function_arguments);
    public:
        UI(Service &serv):service{serv}{}
        void start();
};
