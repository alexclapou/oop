#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "ingredient.h"
#include "service.h"

/*
Service create_service()
{
    Repository new_repository;
    Service new_service;

    repository = create_repository();
    service.repository = new_repository;
    return new_service;
}
*/

Service create_service(Repository repository)
{
    Service new_service;
    new_service.repository = repository;
    return new_service;
}

int validate__add_ingredient(Service *service, int cataloging_number, char state[], char intended_use[], int potency)
{
    int ingredient_found, number_of_ingredients;
    Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_number_of_ingredients(service->repository);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients);
    if(ingredient_found == -1)
        return add_ingredient(&service->repository, cataloging_number, state, intended_use, potency);
    return -1;
}

int validate__delete_ingredient(Service *service, int cataloging_number)
{
    int ingredient_found, number_of_ingredients;
    Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_number_of_ingredients(service->repository);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients);
    if(ingredient_found != -1)
        return delete_ingredient(&service->repository, ingredient_found);
    return -1;
}

int validate__update_ingredient(Service *service, int cataloging_number, char new_state[], char new_intended_use[], int new_potency)
{
    int ingredient_found, number_of_ingredients;
    Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_number_of_ingredients(service->repository);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients); 
    if(ingredient_found != -1)
        return update_ingredient(&service->repository, ingredient_found, new_state, new_intended_use, new_potency);
    return -1;
}

int find_ingredient(Ingredient *ingredients, int cataloging_number, int number_of_ingredients)
{
    int ingredient_index;

    ingredient_index = 0;
    while(ingredient_index < number_of_ingredients){
        if(cataloging_number == get_cataloging_number(ingredients[ingredient_index]))
            return ingredient_index;
        ingredient_index++;
    }
    return -1;
}

Ingredient *service__get_ingredients(Service service)
{
    return get_ingredients(service.repository);
}

int service__get_number_of_ingredients(Service service)
{
    return get_number_of_ingredients(service.repository);
}
