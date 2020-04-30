#include "operation.h"
#include "operationstack.h"
#include <stdlib.h>

Operation* create_operation(Ingredient* ingredient, char* operation_type)
{
	Operation* operation;
    
    operation = (Operation*)malloc(sizeof(Operation));
    operation->operation_type = (char*)malloc(sizeof(char) * (strlen(operation_type) + 1));
	operation->ingredient = ingredient;
    strcpy(operation->operation_type, operation_type);
	return operation;
}

void destroy_operation(Operation* operation)
{
	destroy_ingredient(operation->ingredient);
	free(operation->operation_type);
	free(operation);
}

char* get_operation_type(Operation* operation)
{
	return operation->operation_type;
}

Ingredient* get_operation_ingredient(Operation* operation)
{
	return operation->ingredient;
}
