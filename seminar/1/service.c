#pragma once

#include "repository.h"

typedef struct{
    Repository* repo;
}Service;

Service* create_service(Repository* repo);
void destroy_service(Service* service);
void add_planet(Service* service, char* name, char *type, double eeeeeeeeeee);
