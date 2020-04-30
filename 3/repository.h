#pragma once
#include "ingredient.h"
#define MAX_DIM 100

typedef struct{
    Ingredient ingredients[MAX_DIM];
    int number_of_ingredients;
}Repository;

Repository create_repository();

Ingredient *get_ingredients(Repository repository);

int get_number_of_ingredients(Repository repository);

int add_ingredient(Repository *repository, int cataloging_number, char state[], char intended_use[], int potency);

int update_ingredient(Repository *repository, int ingredient_index, char new_state[], char new_intended_use[], int new_potency);

int delete_ingredient(Repository *repository, int cataloging_number);
