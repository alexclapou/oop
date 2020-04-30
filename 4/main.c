#include <stdio.h>
#include "ingredient.h"
#include "dynamicarray.h"
#include "operation.h"
#include "operationstack.h"
#include "repository.h"
#include "service.h"
#include "ui.h"
#include "test.h"
#include <string.h>

int main()
{
    test__Ingredient();
    test__DynamicArray();
    test__repository();
    test__service();
    test__operation();
    test__OperationStack();
    Repository *repository;
    Service *service;
    UI *ui;
    OperationStack *undo= create_stack();
    OperationStack *redo = create_stack();

    repository = create_repository();
    service = create_service(repository, undo, redo);
    ui = create_UI(service);
    start(ui);
    destroy_UI(ui);
    return 0;
}
