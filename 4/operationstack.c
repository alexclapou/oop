#include "operationstack.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>

OperationStack* create_stack()
{
	OperationStack* operation_stack = (OperationStack*)malloc(sizeof(OperationStack));
	operation_stack->length = 0;

	return operation_stack;
}

void destroy_stack(OperationStack* operation_stack)
{
	for (int i = 0; i < operation_stack->length; i++)
		destroy_operation(operation_stack->operations[i]);
	free(operation_stack);
}

void push(OperationStack* operation_stack, Operation* operation)
{
    operation_stack->operations[operation_stack->length] = operation;
    operation_stack->length++;
}

Operation* pop(OperationStack* operation_stack)
{
    Operation *operation;

    operation_stack->length--;
    return operation_stack->operations[operation_stack->length];
}

int stack_is_empty(OperationStack* operation_stack)
{
    if(operation_stack->length == 0)
        return 1;
    return 0;
}

int stack_is_full(OperationStack* operation_stack)
{
    if(operation_stack->length == 100)
        return 1;
    return 0;
}
