#pragma once
#include "operation.h"
#include "ingredient.h"
#include "dynamicarray.h"
#include <string.h>

typedef struct
{
	Operation* operations[1000];
	int length;
} OperationStack;

OperationStack* create_stack();
// create an operation stack
void destroy_stack(OperationStack* operation_stack);
//destroy an operation stack
void push(OperationStack* operation_stack, Operation* operation);
/* push an operation to the stack
 * parameters:operation_stack - the stack of operations
 *           operation - the operation we want to add
 */
Operation* pop(OperationStack* operation_stack);
/*pop an operation from the stack
 * parameters:operation_stack - the stack of operations
 *           operation - the operation we want to add
 */
int stack_is_empty(OperationStack* operation_stack);
/*check if the stack is empty
 * parameters: operation_stack - the stack of operations
 *output:1 if it s empty
 *       0 otherwise
 */
int stack_is_full(OperationStack* operation_stack);
/*check if the stack is full
 * parameters: operation_stack - the stack of operations
 *output:1 if it s full
 *       0 otherwise
 */
