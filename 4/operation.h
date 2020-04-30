#pragma once
#include "ingredient.h"

typedef struct
{
    Ingredient *ingredient;
	char* operation_type;
}Operation;

Operation* create_operation(Ingredient* ingredient, char* operation_type);
/*create a new operation
 * parameters:ingredient- the ingredient we want to add/update/delete
 *            operation - the operation we performed
 *output : a new oepration
 */
void destroy_operation(Operation* operation);
//destroy an operation
char* get_operation_type(Operation* operation);
/*get the type of an operation
 * parameters:operation - the operation
 * output: the type of operation
 */
Ingredient* get_operation_ingredient(Operation* operation);
/*get the ingredient of an operation
 * parameters:operation - the operation
 * output: the ingredient of operation
 */
