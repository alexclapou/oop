#include "repository.h"
#include <iostream>
#include <fstream>

void Repository::add(Aircraft aircraft){
    aircrafts.push_back(aircraft);
}

std::vector<Aircraft> Repository::get_list_of_aircrafts(){
    return aircrafts;
}
