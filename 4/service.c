#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "repository.h"
#include "ingredient.h"
#include "operationstack.h"
#include "service.h"

Service *create_service(Repository *used_repository, OperationStack *undo, OperationStack *redo)
{
    Service *new_service;
    
    new_service = (Service*)malloc(sizeof(Service));
    new_service->repository = used_repository;
    new_service->undo_stack = undo;
    new_service->redo_stack = redo;
    return new_service;
}

void destroy_service(Service *service)
{
    destroy_repository(service->repository);
    destroy_stack(service->undo_stack);
    destroy_stack(service->redo_stack);
    free(service);
}

int find_ingredient(Ingredient *ingredients, int cataloging_number, int number_of_ingredients)
{
    int ingredient_index;

    ingredient_index = 0;
    while(ingredient_index < number_of_ingredients){
        if(cataloging_number == get_cataloging_number(&ingredients[ingredient_index]))
            return ingredient_index;
        ingredient_index++;
    }
    return -1;
}


int validate__add_ingredient(Service *service, int cataloging_number, char state[], char intended_use[], int potency)
{
    int ingredient_found, number_of_ingredients;
    Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_length_DynamicArray(service->repository->dynamic_array);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients);
    if(ingredient_found == -1){
        Operation *new_operation;
        Ingredient *new_ingredient;

        new_ingredient = create_ingredient(cataloging_number, state, intended_use, potency);
        new_operation = create_operation(new_ingredient, "add");
        push(service->undo_stack, new_operation);
        return add_ingredient(service->repository, cataloging_number, state, intended_use, potency);
    }
    return -1;
}

int validate__delete_ingredient(Service *service, int cataloging_number)
{
    int ingredient_found, number_of_ingredients;
  Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_length_DynamicArray(service->repository->dynamic_array);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients);
    if(ingredient_found != -1){
        Operation *new_operation;
        Ingredient *new_ingredient;

        new_ingredient = create_ingredient(get_cataloging_number(&ingredients[ingredient_found]), get_state(&ingredients[ingredient_found]), get_intended_use(&ingredients[ingredient_found]), get_potency(&ingredients[ingredient_found]));
        new_operation = create_operation(new_ingredient, "delete");
        push(service->undo_stack, new_operation);
        delete_ingredient(service->repository, ingredient_found);
        return 1;
    }
    return -1;
}

int validate__update_ingredient(Service *service, int cataloging_number, char new_state[], char new_intended_use[], int new_potency)
{
    int ingredient_found, number_of_ingredients;
    Ingredient *ingredients;

    ingredients = get_ingredients(service->repository);
    number_of_ingredients = get_length_DynamicArray(service->repository->dynamic_array);
    ingredient_found = find_ingredient(ingredients, cataloging_number, number_of_ingredients); 
    if(ingredient_found != -1){
        Operation *new_operation;
        Ingredient *new_ingredient;

        new_ingredient = create_ingredient(cataloging_number, ingredients[ingredient_found].state, ingredients[ingredient_found].intended_use, ingredients[ingredient_found].potency);
        new_operation = create_operation(new_ingredient, "update");
        push(service->undo_stack, new_operation);
        return update_ingredient(service->repository, ingredient_found, new_state, new_intended_use, new_potency);
    }
    return -1;
}

void swap_ingredients(Ingredient *ingredient1, Ingredient *ingredient2)
{
    Ingredient temp_ingredient;

    temp_ingredient = *ingredient1;
    *ingredient1 = *ingredient2;
    *ingredient2 = temp_ingredient;
}

void sort_by_state(Ingredient *ingredients, int length)                
{                                                                      
    for(int i = 0; i < length-1; i++)                                  
        for(int j = i+1; j < length; j++)                              
            if(strcmp(ingredients[i].state, ingredients[j].state) > 0) 
                swap_ingredients(&ingredients[i], &ingredients[j]);    
}                                                                      

Ingredient *service__get_ingredients(Service *service)
{
    return get_ingredients(service->repository);
}

int service__get_number_of_ingredients(Service *service)
{
    return get_number_of_ingredients(service->repository);
}

int undo(Service *service)
{
    if(stack_is_empty(service->undo_stack) || stack_is_full(service->undo_stack)){
        printf("No more undos!\n");
        return 0;
    }
    Operation *operation;

    operation = pop(service->undo_stack);
    if(strcmp(operation->operation_type, "add") == 0){
        Operation *new_operation;
        Ingredient *ingredient;

        ingredient = get_operation_ingredient(operation);
        new_operation = create_operation(get_operation_ingredient(operation), "add");
		push(service->redo_stack, new_operation);
		delete_ingredient(service->repository, ingredient->cataloging_number);
        free(operation->operation_type);
        free(operation);
        return 1;
    }
    if(strcmp(operation->operation_type, "update") == 0){
        Ingredient *ingredient, *ingredients, *new_ingredient;
        int ingredient_index, number_of_ingredients;
        Operation *new_operation;

        ingredient = get_operation_ingredient(operation);
        ingredients = get_ingredients(service->repository);
        number_of_ingredients = get_number_of_ingredients(service->repository);
        ingredient_index = find_ingredient(ingredients, ingredient->cataloging_number, number_of_ingredients);
        new_ingredient = create_ingredient(ingredients[ingredient_index].cataloging_number, ingredients[ingredient_index].state, ingredients[ingredient_index].intended_use, ingredients[ingredient_index].potency);
        new_operation = create_operation(new_ingredient, "update");
		push(service->redo_stack, new_operation);
		update_ingredient(service->repository, ingredient_index, operation->ingredient->state, operation->ingredient->intended_use, operation->ingredient->potency);
        destroy_operation(operation);
        return 1;
    }
     if(strcmp(operation->operation_type, "delete") == 0){
        Ingredient *ingredient;
        Operation *new_operation;

        new_operation = create_operation(get_operation_ingredient(operation), "delete");
		push(service->redo_stack, new_operation);
        ingredient = get_operation_ingredient(new_operation);
		add_ingredient(service->repository, ingredient->cataloging_number, ingredient->state, ingredient->intended_use, ingredient->potency);
        free(operation->operation_type);
        free(operation);
        return 1;
    }
}

int redo(Service *service)
{
    if(stack_is_empty(service->redo_stack) || stack_is_full(service->redo_stack)){
        printf("No more redos!\n");
        return 0;
    }
    Operation *operation;

    operation = pop(service->redo_stack);
    if(strcmp(operation->operation_type, "add") == 0){
        Ingredient *ingredient;

        ingredient = operation->ingredient;
        validate__add_ingredient(service, ingredient->cataloging_number, ingredient->state, ingredient->intended_use, ingredient->potency);
    }
    if(strcmp(operation->operation_type, "update") == 0){
        Ingredient *ingredient;

        ingredient = operation->ingredient;
		validate__update_ingredient(service, ingredient->cataloging_number, ingredient->state, ingredient->intended_use, ingredient->potency);
    }
    if(strcmp(operation->operation_type, "delete") == 0){
        Ingredient *ingredient;

        ingredient = operation->ingredient;
        validate__delete_ingredient(service, ingredient->cataloging_number);
    }
    destroy_operation(operation);
    return 1;
}
