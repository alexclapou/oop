#pragma once
#include "repository.h"

typedef struct{
    Repository repository;
}Service;

Service create_service();
int find_ingredient(Ingredient *ingredients, int cataloging_number, int number_of_ingredients);

int validate__add_ingredient(Service *service, int cataloging_number, char state[], char intended_use[], int potency);

int validate__delete_ingredient(Service *service, int cataloging_number);
     
int validate__update_ingredient(Service *service, int cataloging_number, char new_state[], char new_intended_use[], int new_potency);

Ingredient *service__get_ingredients(Service service);
int service__get_number_of_ingredients(Service service);

