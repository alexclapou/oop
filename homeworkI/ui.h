#include "service.h"

std::vector<std::string> tokenize(std::string arguments);
class UI{
    public:
        void start();
    private:
        Service service;
        void read_command(char input_command[], std::string &function, std::string &function_arguments);
};
