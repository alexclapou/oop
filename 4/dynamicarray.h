#pragma once
#include "ingredient.h"

typedef struct{
    int length;
    int capacity;
    Ingredient *ingredients;
    int action;
}DynamicArray;

DynamicArray *create_DynamicArray();
//create a new dynamic array
void destroy_DynamicArray(DynamicArray *dynamic_array);
//destroy a dynamic array
int add_to_DynamicArray(DynamicArray *dynamic_array, Ingredient *new_ingredient);
/*add an element to a dynamic array
 * parameters:*dynamic_array - pointer to the dynamic array
 *            new_ingredient - the new ingredient we want to add
 * output:1
 */
int delete_element_DynamicArray(DynamicArray *dynamic_array, int element_index);
/*delete an element from a dynamic array
 * parameters:*dynamic_array - a pointer to the dynamic array
 *             element_index - the index of element we want to delete
 * output:1
 */
int update_element_DynamicArray(DynamicArray *dynamic_array, int ingredient_index, char new_state[], char new_intended_use[], int new_potency);
/*update an element from a dynamic array
 * parameters:*dynamic_array - pointer to the dynamic array
 *            ingredient_index - the index of the ingredient in dynamic array
 * output:1
 */
void update_DynamicArray_capacity(DynamicArray *dynamic_array);
/*update the size of a dynamic array
 * parameters: *dynamic_array - pointer to the dynamic array
 */
int check_Dynamicarray_full(DynamicArray *dynamic_array);
/*check if the dynamic array has memory left
 * parameters: *dynamic_array - pointer to the dynamic array
 * output:1 if it's full
 *        0 otherwise
 */
int get_length_DynamicArray(DynamicArray *dynamic_array);
/*get length of the dynamic array
 * parameters: *dynamic_array - pointer of the dynamic array
 * output: the length of given dynamic array
 */
