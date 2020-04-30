#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "repository.h"
#include "ingredient.h"

Repository *create_repository()
{
    Repository *new_repository;

    new_repository = (Repository*)malloc(sizeof(Repository));
    new_repository->dynamic_array = create_DynamicArray();
    return new_repository;
}

void destroy_repository(Repository *repository)
{
    destroy_DynamicArray(repository->dynamic_array);
    free(repository);
}

Ingredient *get_ingredients(Repository *repository)
{
    static Ingredient *list;

    list = repository->dynamic_array->ingredients;
    return list;
}

int get_number_of_ingredients(Repository *repository)
{
    return repository->dynamic_array->length;
}

int add_ingredient(Repository *repository, int cataloging_number, char *state, char *intended_use, int potency)
{
    Ingredient *ingredient;

    ingredient = create_ingredient(cataloging_number, state, intended_use, potency);
    add_to_DynamicArray(repository->dynamic_array, ingredient);
    destroy_ingredient(ingredient);
    return 1;
}
int update_ingredient(Repository *repository, int ingredient_index, char new_state[], char new_intended_use[], int new_potency)
{
    return update_element_DynamicArray(repository->dynamic_array, ingredient_index, new_state, new_intended_use, new_potency);
}

int delete_ingredient(Repository *repository, int cataloging_number)
{
    return delete_element_DynamicArray(repository->dynamic_array, cataloging_number);
}
