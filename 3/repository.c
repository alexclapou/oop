#include <stdio.h>
#include <string.h>
#include "repository.h"
#include "ingredient.h"

Repository create_repository()
{
    Repository new_repository;
    new_repository.number_of_ingredients = 0;
    return new_repository;
}

Ingredient *get_ingredients(Repository repository)
{
    static Ingredient list[100];
    int ingredient_index, number_of_ingredients;;

    ingredient_index = 0;
    number_of_ingredients = get_number_of_ingredients(repository);
    while(ingredient_index < number_of_ingredients){
        list[ingredient_index] = repository.ingredients[ingredient_index];
        ingredient_index++;
    }
    return list;
}

int get_number_of_ingredients(Repository repository)
{
    return repository.number_of_ingredients;
}

int add_ingredient(Repository *repository, int cataloging_number, char state[], char intended_use[], int potency)
{
    repository->ingredients[repository->number_of_ingredients] = create_ingredient(cataloging_number, state, intended_use, potency);
    repository->number_of_ingredients++;
    return 1;
}

int update_ingredient(Repository *repository, int ingredient_index, char new_state[], char new_intended_use[], int new_potency)
{
    set_state(&repository->ingredients[ingredient_index], new_state);
    set_use(&repository->ingredients[ingredient_index], new_intended_use);
    set_potency(&repository->ingredients[ingredient_index], new_potency);
    return 1;
}

int delete_ingredient(Repository *repository, int cataloging_number)
{
    if(cataloging_number == repository->number_of_ingredients-1)
        repository->number_of_ingredients--;
    else{
        while(cataloging_number < repository->number_of_ingredients-1){
            repository->ingredients[cataloging_number] = repository->ingredients[cataloging_number+1];
            cataloging_number++;
        }
        repository->number_of_ingredients--;
    }
    return 1;
}

