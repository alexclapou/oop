#include "dynamicarray.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

DynamicArray *create_DynamicArray()
{
    DynamicArray *new_dynamic_array;

    new_dynamic_array = (DynamicArray*)malloc(sizeof(DynamicArray));
    new_dynamic_array->length = 0;
    new_dynamic_array->capacity = 0;
    new_dynamic_array->ingredients = (Ingredient*)malloc(sizeof(Ingredient));
    return new_dynamic_array;
}

void destroy_DynamicArray(DynamicArray *dynamic_array)
{
    for(int i = 0; i < dynamic_array->length; i++){
        free(dynamic_array->ingredients[i].state);
        free(dynamic_array->ingredients[i].intended_use);
    }
    free(dynamic_array->ingredients);
    free(dynamic_array);
}

int check_Dynamicarray_full(DynamicArray *dynamic_array)
{
    if(dynamic_array->capacity == dynamic_array->length){
        return 1;
    }
    return 0;
}

void update_DynamicArray_capacity(DynamicArray *dynamic_array)
{
    Ingredient *new_dynamic_array;

    new_dynamic_array = (Ingredient*)malloc(sizeof(Ingredient) * (dynamic_array->capacity+5));
    for(int i = 0; i < dynamic_array->length; i++)
        new_dynamic_array[i] = dynamic_array->ingredients[i];
    free(dynamic_array->ingredients);
    dynamic_array->ingredients = new_dynamic_array;
    dynamic_array->capacity += 5;
}

int add_to_DynamicArray(DynamicArray *dynamic_array, Ingredient *new_ingredient)
{
    if(check_Dynamicarray_full(dynamic_array) == 1)
        update_DynamicArray_capacity(dynamic_array);
    dynamic_array->ingredients[dynamic_array->length] = *new_ingredient;
    //strcpy(dynamic_array->ingredients[dynamic_array->length].state, new_ingredient->state);
    memmove(dynamic_array->ingredients[dynamic_array->length].state, new_ingredient->state, strlen(new_ingredient->state));
    memmove(dynamic_array->ingredients[dynamic_array->length].intended_use, new_ingredient->intended_use, strlen(new_ingredient->intended_use));
    //strcpy(dynamic_array->ingredients[dynamic_array->length].intended_use, new_ingredient->intended_use);
    dynamic_array->length++;
    new_ingredient->state = NULL;
    new_ingredient->intended_use = NULL;
    new_ingredient = NULL;
    return 1;
}

int get_length_DynamicArray(DynamicArray *dynamic_array)
{
    return dynamic_array->length;
}

int update_element_DynamicArray(DynamicArray *dynamic_array, int ingredient_index, char *new_state, char *new_intended_use, int new_potency)
{
    strcpy(dynamic_array->ingredients[ingredient_index].state, new_state);
    strcpy(dynamic_array->ingredients[ingredient_index].intended_use, new_intended_use);
    dynamic_array->ingredients[ingredient_index].potency = new_potency;
    return 1;
}

int delete_element_DynamicArray(DynamicArray *dynamic_array, int element_index)
{
    while(element_index < dynamic_array->length-1){
        dynamic_array->ingredients[element_index] = dynamic_array->ingredients[element_index+1];
        memmove(dynamic_array->ingredients[element_index].state, dynamic_array->ingredients[element_index+1].state, strlen(dynamic_array->ingredients[element_index+1].state));
        memmove(dynamic_array->ingredients[element_index].intended_use, dynamic_array->ingredients[element_index+1].intended_use, strlen(dynamic_array->ingredients[element_index+1].intended_use));
        element_index++;
        dynamic_array->ingredients[element_index].state = NULL;
        dynamic_array->ingredients[element_index].intended_use = NULL;
    }
    dynamic_array->length--;
    free(dynamic_array->ingredients[dynamic_array->length].state);
    free(dynamic_array->ingredients[dynamic_array->length].intended_use);
    return 1;
}
