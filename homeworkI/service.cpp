#include "service.h"

void Service::add(Aircraft aircraft)
{
    repository.add(aircraft);
}
std::vector<Aircraft> Service::get_list_of_aircrafts(){
    return repository.get_list_of_aircrafts();
}
