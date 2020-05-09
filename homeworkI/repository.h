#pragma once
#include "aircraft.h"

class Repository{
    private:
        std::vector<Aircraft> aircrafts;
        std::string filename;
    public:
        void add(Aircraft aircraft);
        std::vector<Aircraft> get_list_of_aircrafts();
};
