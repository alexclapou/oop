#pragma once

typedef struct{
    int cataloging_number;
    char *state;
    char *intended_use;
    int potency;
}Ingredient;

Ingredient *create_ingredient(int cataloging_number, char state[], char intended_use[], int potency);
/*create a new ingredient
 * parameters:cataloging_number - the cataloging number for the new ingredient
 *            state - state for the new ingredient
 *            intended_use - use for the ingredient
 *            potency - potency for the ingredient
 *output: a new ingredient
 */

void destroy_ingredient(Ingredient *ingredient);
/*destroy an ingredient
 * parameters: ingredient - the ingredient we want to destroy
 */

int get_cataloging_number(Ingredient *ingredient);
/*get the cataloging_number of a given ingredient
 *parameters:ingredient - the ingredient
 *output: the cataloging number of the ingredient
 */

char *get_state(Ingredient *ingredient);
/*get the state of a given ingredient
 *parameters:ingredient - the ingredient
 *output: the state of the ingredient
 */
void set_state(Ingredient *ingredient, char *new_state);
/*set the state of a given ingredient
 * parameters:ingredient - given ingredient
 *            new_state - new state we want to set
 * output:
 */

char *get_intended_use(Ingredient *ingredient);
/*get the use of a given ingredient
 *parameters:ingredient - the ingredient
 *output: the use of the ingredient
 */
void set_intended_use(Ingredient *ingredient, char *new_intended_use);
/*set the intended use for a given ingredient
 * parameters:ingredient - given ingredient
 *            new_intended_use - new intended use to set  
 * output:
 */

int  get_potency(Ingredient *ingredient);
/*get the potency of a given ingredient
 *parameters:ingredient - the ingredient
 *output: the potency of the ingredient
 */
void set_potency(Ingredient *ingredient, int new_potency);
/*set the potency of a given ingredient
 * parameters:ingredient - the ingredient
 *            new_potency - new potency we want to add
 * output:
 */

void test__Ingredient();
//all tests here
Ingredient* copy_ingredient(Ingredient* ingredient);
