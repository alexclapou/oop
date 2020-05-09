#pragma once
#include "repository.h"

class Service{
    private:
        Repository repository;
    public:
        void add(Aircraft aircraft);
        std::vector<Aircraft> get_list_of_aircrafts();
};
