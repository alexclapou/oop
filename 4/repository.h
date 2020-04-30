#pragma once
#include "ingredient.h"
#include "dynamicarray.h"

typedef struct{
    DynamicArray *dynamic_array;
}Repository;

Repository *create_repository();
/*create a repository to store all the ingredients
 *parameters: -
 *output: a new repository returned
 */
void destroy_repository(Repository *repository);
void destroy_keep_ingredients(Repository *repository);
Ingredient *get_ingredients(Repository *repository);
/*get the list of ingredients from repository
 * parameters:repository - the repository of ingredients
 * output:the list of ingredients
 */
int get_number_of_ingredients(Repository *repository);
/*get the number of ingredients in the list
 * parameters:repository - the repository of the ingredients
 * output:the number of the ingredients in the list
 */
int add_ingredient(Repository *repository, int cataloging_number, char *state, char *intended_use, int potency);
/*add a new ingredient to the list
 * parameters:repository - pointer to the repository of ingredients
 *            cataloging_number - cataloging number of the ingredient
 *            state - the state of the ingredient
 *            intended_use - intendeed use of the ingredient
 *            potency - the potency of the ingredient
 *output: 1
 */
int update_ingredient(Repository *repository, int ingredient_index, char *new_state, char *new_intended_use, int new_potency);
/*update an ingredient details
 * parameters:repository - pointer to the repository of ingredients
 *            ingredient_index - index of the ingredient we want to update
 *            new_state - new state of the ingredient
 *            new_intended_use - new intended use of the ingredient
 *            new_potency - new potency of the ingredient
 *output:1
 */
int delete_ingredient(Repository *repository, int cataloging_number);
/*delete an ingredient by a given cataloging number
 * parameters:repository - pointer to the repository of ingredients
 *            cataloging_number - the cataloging number of the ingredient we want to delete
 *output:1
 */
int add_to_history_list(DynamicArray *history_list, int cataloging_number, char *state, char *intended_use, int potency);
