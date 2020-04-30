#pragma once
#include "repository.h"
#include "operationstack.h"

typedef struct{
    Repository *repository;
    OperationStack *undo_stack;
    OperationStack *redo_stack;
}Service;

Service *create_service(Repository *repository, OperationStack *undo, OperationStack *redo);
//create a service struct to handle validations/duplications/ and working with data
void destroy_service(Service *service);
//destroy the service/repo/dynamic_array
int find_ingredient(Ingredient *ingredients, int cataloging_number, int number_of_ingredients);
/*find a ingredient with a given cataloging number
 * parameters:repository - ingredient repository
 *            cataloging_number - cataloging number of the ingredient we're finding
 * output:the position of the ingredient, it it does exist and it's found
         -1 otherwise
 */
int validate__add_ingredient(Service *service, int cataloging_number, char state[], char intended_use[], int potency);
/*validate input and add ingredient if it doesn't exist
 * parameters:service
 *            cataloging_number - cataloging number of the ingredient given by input
 *            state - state of the ingredient given by input
 *            intended_use - intended use of the ingredient given by input
 *            potency - potency of the ingredient given by input
 * output:1 if the ingredient is added and doesn't exist in the list
         -1 otherwise
 */
int validate__delete_ingredient(Service *service, int cataloging_number);
/*validate input, check for correct data and delete ingredient if it exists
 * parameters:service
 *            cataloging_number - cataloging number of the ingredient we want to delete given by input
 * output:1 if the ingredient is deleted
 *       -1 otherwise
 */             
int validate__update_ingredient(Service *service, int cataloging_number, char new_state[], char new_intended_use[], int new_potency);
/*validate input, check for correct data and update an ingredient if exists
 * parameters:service
 *            cataloging_number - cataloging number of the ingredient we want to update, given as input
 *            new_state - new state of the ingredient
 *            intended_use - new intended use for the ingredient
 *            new_potency - new potency for the ingredient
 * output:1 if the ingredient exists and it's updated
 *        -1 otherwise
 */
void swap_ingredients(Ingredient *ingredient1, Ingredient *ingredient2);
void sort_by_state(Ingredient *ingredients, int length);
Ingredient *service__get_ingredients(Service *service);
int service__get_number_of_ingredients(Service *service);
int undo(Service *service);
int redo(Service *service);
