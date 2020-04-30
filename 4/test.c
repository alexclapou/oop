#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "test.h"

void get_cataloging_number__valid_input__get_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(12345, "a", "b", 2);
    assert(get_cataloging_number(test_ingredient) == 12345);
    destroy_ingredient(test_ingredient);
}

void get_state__valid_input__get_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "test state", "b", 2);
    assert(strcmp(get_state(test_ingredient), "test state") == 0);
    destroy_ingredient(test_ingredient);
}

void get_intended_use__valid_input__get_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "a", "test intended use", 2);
    assert(strcmp(get_intended_use(test_ingredient), "test intended use") == 0);
    destroy_ingredient(test_ingredient);

}

void get_potency__valid_input__get_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "a", "b", 12345);
    assert(get_potency(test_ingredient) == 12345);
    destroy_ingredient(test_ingredient);

}

void test__getters()
{
    get_cataloging_number__valid_input__get_value();
    get_state__valid_input__get_value();
    get_intended_use__valid_input__get_value();
    get_potency__valid_input__get_value();

}

void set_state__valid_input__set_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "old state", "b", 2);
    set_state(test_ingredient, "new state");
    assert(strcmp(get_state(test_ingredient), "new state") == 0);
    destroy_ingredient(test_ingredient);

}

void set_intended_use__valid_input__set_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "a", "old intended use", 2);
    set_intended_use(test_ingredient, "new intended use");
    assert(strcmp(get_intended_use(test_ingredient), "new intended use") == 0);
    destroy_ingredient(test_ingredient);
}

void set_potency__valid_input__set_value()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "a", "b", 2);
    set_potency(test_ingredient, 12345);
    assert(get_potency(test_ingredient) == 12345);
    destroy_ingredient(test_ingredient);

}

void create_ingredient__valid_input__ingredient_created()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(9876, "random state", "random intended use", 1234);
    assert(get_cataloging_number(test_ingredient) == 9876);
    assert(strcmp(get_state(test_ingredient), "random state") == 0);
    assert(strcmp(get_intended_use(test_ingredient), "random intended use") == 0);
    assert(get_potency(test_ingredient) == 1234);
    destroy_ingredient(test_ingredient);
}

void destroy_ingredient__valid_input__ingredient_destroyed()
{
    Ingredient *test_ingredient;

    test_ingredient = create_ingredient(1, "a", "b", 2);
    destroy_ingredient(test_ingredient);
}

void test__setters()
{
    set_state__valid_input__set_value();
    set_intended_use__valid_input__set_value();
    set_potency__valid_input__set_value();
}

void test__Ingredient()
{
    test__getters();
    test__setters();
    create_ingredient__valid_input__ingredient_created();
    destroy_ingredient__valid_input__ingredient_destroyed();
}

void create_DynamicArray__valid_input__DynamicArray_created()
{
    DynamicArray *test_dynamic_array;

    test_dynamic_array = create_DynamicArray();
    assert(test_dynamic_array->length == 0);
    assert(test_dynamic_array->capacity == 0);
    destroy_DynamicArray(test_dynamic_array);
}

void destroy_DynamicArray__valid_input__DynamicArray_destroyed()
{
    DynamicArray *test_dynamic_array;

    test_dynamic_array = create_DynamicArray();
    destroy_DynamicArray(test_dynamic_array);
}

void check_Dynamicarray_full__valid_input__return_0()
{
    DynamicArray *test_dynamic_array;

    test_dynamic_array = create_DynamicArray();
    test_dynamic_array->capacity = test_dynamic_array->length+1;
    assert(check_Dynamicarray_full(test_dynamic_array) == 0);
    destroy_DynamicArray(test_dynamic_array);
}

void check_Dynamicarray_full__valid_input__return_1()
{
    DynamicArray *test_dynamic_array;

    test_dynamic_array = create_DynamicArray();
    assert(check_Dynamicarray_full(test_dynamic_array) == 1);
    test_dynamic_array->length--;
    destroy_DynamicArray(test_dynamic_array);
}

void update_DynamicArray_capacity__valid_input__capacity_increased()
{
    DynamicArray *test_dynamic_array;

    test_dynamic_array = create_DynamicArray();
    assert(test_dynamic_array->capacity == 0);
    update_DynamicArray_capacity(test_dynamic_array);
    assert(test_dynamic_array->capacity == 5);
    destroy_DynamicArray(test_dynamic_array);
}

void add_to_DynamicArray__valid_input__ingredient_added()
{
    DynamicArray *test_dynamic_array;
    Ingredient *test_ingredient;

    test_dynamic_array = create_DynamicArray();
    test_ingredient = create_ingredient(1, "a", "b", 2);
    assert(test_dynamic_array->length == 0);
    add_to_DynamicArray(test_dynamic_array, test_ingredient);
    assert(test_dynamic_array->length == 1);
    destroy_ingredient(test_ingredient);
    destroy_DynamicArray(test_dynamic_array);
}

void get_length_DynamicArray__valid__input__get_length()
{
    DynamicArray *test_dynamic_array;
    Ingredient *test_ingredient;

    test_dynamic_array = create_DynamicArray();
    test_ingredient = create_ingredient(1, "a", "b", 2);
    assert(get_length_DynamicArray(test_dynamic_array) == 0);
    add_to_DynamicArray(test_dynamic_array, test_ingredient);
    assert(get_length_DynamicArray(test_dynamic_array) == 1);
    destroy_ingredient(test_ingredient);
    destroy_DynamicArray(test_dynamic_array);
}

void update_element_DynamicArray__valid_input__element_updated()
{
    DynamicArray *test_dynamic_array;
    Ingredient *test_ingredient;

    test_dynamic_array = create_DynamicArray();
    test_ingredient = create_ingredient(1, "a", "b", 2);
    add_to_DynamicArray(test_dynamic_array, test_ingredient);
    update_element_DynamicArray(test_dynamic_array, 0, "b", "a", 1);
    assert(strcmp(get_state(&test_dynamic_array->ingredients[0]), "b") == 0);
    assert(strcmp(get_intended_use(&test_dynamic_array->ingredients[0]), "a") == 0);
    assert(get_potency(&test_dynamic_array->ingredients[0]) == 1);
    destroy_ingredient(test_ingredient);
    destroy_DynamicArray(test_dynamic_array);
}

void delete_element_DynamicArray__valid_input__element_deleted()
{
    DynamicArray *test_dynamic_array;
    Ingredient *test_ingredient;

    test_dynamic_array = create_DynamicArray();
    test_ingredient = create_ingredient(1, "a", "b", 2);
    add_to_DynamicArray(test_dynamic_array, test_ingredient);
    assert(get_length_DynamicArray(test_dynamic_array) == 1);
    delete_element_DynamicArray(test_dynamic_array, 0);
    assert(get_length_DynamicArray(test_dynamic_array) == 0);
    destroy_ingredient(test_ingredient);
    destroy_DynamicArray(test_dynamic_array);
}

void test__DynamicArray()
{
    create_DynamicArray__valid_input__DynamicArray_created();
    destroy_DynamicArray__valid_input__DynamicArray_destroyed();
    check_Dynamicarray_full__valid_input__return_0();
    check_Dynamicarray_full__valid_input__return_1();
    update_DynamicArray_capacity__valid_input__capacity_increased();
    add_to_DynamicArray__valid_input__ingredient_added();
    get_length_DynamicArray__valid__input__get_length();
    update_element_DynamicArray__valid_input__element_updated();
    delete_element_DynamicArray__valid_input__element_deleted();
}

void create_delete_repository__valid__repository_created_destroyed()
{
    Repository *test_repository;
    
    test_repository = create_repository();
    destroy_repository(test_repository);
}

void get_ingredients__valid_input__return_ingredients()
{
    Ingredient *test_list_ingredients;
    Repository *test_repository;

    test_repository = create_repository();
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 3, "a", "b", 4);
    add_ingredient(test_repository, 5, "a", "b", 6);
    add_ingredient(test_repository, 7, "a", "b", 8);
    test_list_ingredients = get_ingredients(test_repository);
    for(int i = 0; i < 3; i++){
        assert(get_cataloging_number(&test_repository->dynamic_array->ingredients[i]) == get_cataloging_number(&test_list_ingredients[i]));
        assert(strcmp(get_state(&test_repository->dynamic_array->ingredients[i]), get_state(&test_list_ingredients[i])) == 0);
        assert(strcmp(get_intended_use(&test_repository->dynamic_array->ingredients[i]), get_intended_use(&test_list_ingredients[i])) == 0);
        assert(get_potency(&test_repository->dynamic_array->ingredients[i]) == get_potency(&test_list_ingredients[i]));
    }
    destroy_repository(test_repository);
}

void get_number_of_ingredients__valid_input__return_number_of_ingredients()
{
    Repository *test_repository;
    int number_of_ingredients;

    test_repository = create_repository();
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 1, "a", "b", 2);
    number_of_ingredients = get_number_of_ingredients(test_repository);
    assert(number_of_ingredients == 4);
    destroy_repository(test_repository);
}

void add_ingredient__valid_input__ingredient_added()
{
    Repository *test_repository;

    test_repository = create_repository();
    add_ingredient(test_repository, 1, "one", "ONE", 1);
    assert(get_cataloging_number(&test_repository->dynamic_array->ingredients[0]) == 1);
    assert(strcmp(get_state(&test_repository->dynamic_array->ingredients[0]), "one") == 0);
    assert(strcmp(get_intended_use(&test_repository->dynamic_array->ingredients[0]), "ONE") == 0);
    assert(get_potency(&test_repository->dynamic_array->ingredients[0]) == 1);
    destroy_repository(test_repository);
}

void update_ingredient__valid_input__ingredient_updated()
{
    Repository *test_repository;

    test_repository = create_repository();
    add_ingredient(test_repository, 1, "one", "ONE", 1);
    update_ingredient(test_repository, 0, "ONE", "one", -1);
    assert(get_cataloging_number(&test_repository->dynamic_array->ingredients[0]) == 1);
    assert(strcmp(get_state(&test_repository->dynamic_array->ingredients[0]), "ONE") == 0);
    assert(strcmp(get_intended_use(&test_repository->dynamic_array->ingredients[0]), "one") == 0);
    assert(get_potency(&test_repository->dynamic_array->ingredients[0]) == -1);
    destroy_repository(test_repository);
}

void delete_ingredient__valid_input__ingredient_deleted()
{
    Repository *test_repository;

    test_repository = create_repository();
    add_ingredient(test_repository, 1, "one", "ONE", 1);
    delete_ingredient(test_repository, 1);
    assert(get_number_of_ingredients(test_repository) == 0);
    destroy_repository(test_repository);
}

void test__repository()
{
    create_delete_repository__valid__repository_created_destroyed();
    get_ingredients__valid_input__return_ingredients();
    get_number_of_ingredients__valid_input__return_number_of_ingredients();
    add_ingredient__valid_input__ingredient_added();
    update_ingredient__valid_input__ingredient_updated();
    delete_ingredient__valid_input__ingredient_deleted();
}

void create_delete_service__valid__service_created_destroyed()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    destroy_service(test_service);
}
void find_ingredient__ingredient_found__return_index()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 2, "a", "b", 2);
    add_ingredient(test_repository, 3, "a", "b", 2);
    assert(find_ingredient(test_repository->dynamic_array->ingredients, 2, 3) == 1);
    destroy_service(test_service);
}

void find_ingredient__ingredient_not_found__return_minus_1()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    add_ingredient(test_repository, 1, "a", "b", 2);
    add_ingredient(test_repository, 2, "a", "b", 2);
    add_ingredient(test_repository, 3, "a", "b", 2);
    assert(find_ingredient(test_repository->dynamic_array->ingredients, 123, 3) == -1);
    destroy_service(test_service);
}

void validate__add_ingredient__valid_input__ingredient_added()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    assert(validate__add_ingredient(test_service, 1, "a", "b", 2) == 1);
    assert(validate__add_ingredient(test_service, 2, "a", "b", 2) == 1);
    destroy_service(test_service);
}

void validate__add_ingredient__invalid_input__return_minus_1()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    assert(validate__add_ingredient(test_service, 1, "a", "b", 2) == 1);
    assert(validate__add_ingredient(test_service, 1, "a", "b", 2) == -1);
    destroy_service(test_service);
}

void validate__delete_ingredient__valid_input__ingredient_deleted()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    assert(validate__add_ingredient(test_service, 1, "a", "b", 2) == 1);
    validate__add_ingredient(test_service, 1, "a", "b", 2);
    assert(validate__delete_ingredient(test_service, 1) == 1);
    destroy_service(test_service);
}

void validate__delete_ingredient__invalid_input__return_minus_1()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    validate__add_ingredient(test_service, 1, "a", "b", 2);
    assert(validate__delete_ingredient(test_service, 2) == -1);
    destroy_service(test_service);
}

void validate__update_ingredient__valid_input__ingredient_updated()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    validate__add_ingredient(test_service, 1, "a", "b", 2);
    assert(validate__update_ingredient(test_service, 1, "A", "B", -2) == 1);
    destroy_service(test_service);
}

void validate__update_ingredient__invalid_input__return_minus_1()
{
    Service *test_service;
    Repository *test_repository;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    validate__add_ingredient(test_service, 1, "a", "b", 2);
    assert(validate__update_ingredient(test_service, 2, "A", "B", -2) == -1);
    destroy_service(test_service);
}

void swap_ingredients__valid_input__ingredients_swapped()
{
    Ingredient *ingredient1, *ingredient2;

    ingredient1 = create_ingredient(1, "a", "A", 1);
    ingredient2 = create_ingredient(2, "b", "B", 2);
    assert(get_cataloging_number(ingredient1) == 1);
    assert(get_cataloging_number(ingredient2) == 2);
    assert(strcmp(get_state(ingredient1), "a") == 0);
    assert(strcmp(get_state(ingredient2), "b") == 0);
    assert(strcmp(get_intended_use(ingredient1), "A") == 0);
    assert(strcmp(get_intended_use(ingredient2), "B") == 0);
    assert(get_potency(ingredient1) == 1);
    assert(get_potency(ingredient2) == 2);
    swap_ingredients(ingredient1, ingredient2);
    assert(get_cataloging_number(ingredient1) == 2);
    assert(get_cataloging_number(ingredient2) == 1);
    assert(strcmp(get_state(ingredient1), "b") == 0);
    assert(strcmp(get_state(ingredient2), "a") == 0);
    assert(strcmp(get_intended_use(ingredient1), "B") == 0);
    assert(strcmp(get_intended_use(ingredient2), "A") == 0);
    assert(get_potency(ingredient1) == 2);
    assert(get_potency(ingredient2) == 1);
    destroy_ingredient(ingredient1);
    destroy_ingredient(ingredient2);
}

void sort_by_state__valid_input__ingredients_sorted_by_state()
{
    Repository *test_repository;
    Service *test_service;
    OperationStack *undo, *redo;

    test_repository = create_repository();
    undo = create_stack();
    redo = create_stack();
    test_service = create_service(test_repository, undo, redo);
    validate__add_ingredient(test_service, 1, "d", "b", 1);
    validate__add_ingredient(test_service, 2, "b", "b", 1);
    validate__add_ingredient(test_service, 3, "c", "b", 1);
    validate__add_ingredient(test_service, 4, "a", "b", 1);
    sort_by_state(test_service->repository->dynamic_array->ingredients, test_service->repository->dynamic_array->length);
    for(int i = 0; i < 3; i++)
        for(int j = i+1; j < 4; j++)
            assert(strcmp(get_state(&test_service->repository->dynamic_array->ingredients[i]), get_state(&test_service->repository->dynamic_array->ingredients[j])) < 0);
    destroy_service(test_service);
}

void test__service()
{
    create_delete_service__valid__service_created_destroyed();
    find_ingredient__ingredient_found__return_index();
    find_ingredient__ingredient_not_found__return_minus_1();
    validate__add_ingredient__valid_input__ingredient_added();
    validate__add_ingredient__invalid_input__return_minus_1();
    validate__delete_ingredient__valid_input__ingredient_deleted();
    validate__delete_ingredient__invalid_input__return_minus_1();
    validate__update_ingredient__valid_input__ingredient_updated();
    validate__update_ingredient__invalid_input__return_minus_1();
    swap_ingredients__valid_input__ingredients_swapped();
    sort_by_state__valid_input__ingredients_sorted_by_state();
}

void create_destroy_operation__valid__operation_created_destroyed()
{
    Operation *test_operation;;
    Ingredient *test_ingredient;
    char test_type[50];

    strcpy(test_type, "operation type");
    test_ingredient = create_ingredient(1, "state", "intended use", 1);
    test_operation = create_operation(test_ingredient, test_type);
    assert(strcmp(test_operation->operation_type, "operation type") == 0);
    assert(test_operation->ingredient->cataloging_number == test_ingredient->cataloging_number);
    assert(strcmp(test_operation->ingredient->state, test_ingredient->state) == 0);
    assert(strcmp(test_operation->ingredient->intended_use, test_ingredient->intended_use) == 0);
    assert(test_operation->ingredient->potency == test_ingredient->potency);
    destroy_operation(test_operation);
}

void get_operation_type__valid__return_type()
{
    Operation *test_operation;;
    Ingredient *test_ingredient;
    char test_type[50];

    strcpy(test_type, "operation type");
    test_ingredient = create_ingredient(1, "state", "intended use", 1);
    test_operation = create_operation(test_ingredient, test_type);
    assert(strcmp(test_operation->operation_type, test_type) == 0);
    destroy_operation(test_operation);
}

void get_operation_ingredient__valid__return_ingredient()
{
    Operation *test_operation;;
    Ingredient *test_ingredient;
    char test_type[50];

    strcpy(test_type, "operation type");
    test_ingredient = create_ingredient(1, "state", "intended use", 1);
    test_operation = create_operation(test_ingredient, test_type);
    assert(get_cataloging_number(get_operation_ingredient(test_operation)) == get_cataloging_number(test_ingredient));
    assert(strcmp(get_state(get_operation_ingredient(test_operation)), get_state(test_ingredient)) == 0);
    assert(strcmp(get_intended_use(get_operation_ingredient(test_operation)), get_intended_use(test_ingredient)) == 0);
    assert(get_potency(get_operation_ingredient(test_operation)) == get_potency(test_ingredient));
    destroy_operation(test_operation);
}

void test__operation()
{
    create_destroy_operation__valid__operation_created_destroyed();
    get_operation_type__valid__return_type();
    get_operation_ingredient__valid__return_ingredient();
}

void create_destroy_OperationStack__valid__OperationStack_created_destroyed()
{
    Ingredient *ingredient;
    OperationStack *stack;
    Operation *operation; 

    stack = create_stack();
    ingredient = create_ingredient(1, "a", "a", 1);
    operation = create_operation(ingredient, "add");
    push(stack, operation);
    assert(stack->length == 1);
    destroy_stack(stack);
}

void push__valid__operation_pushed()
{
    Ingredient *ingredient;
    OperationStack *stack;
    Operation *operation; 

    stack = create_stack();
    ingredient = create_ingredient(1, "a", "a", 1);
    operation = create_operation(ingredient, "add");
    push(stack, operation);
    assert(stack->length == 1);
    destroy_stack(stack);
}

void stack_is_full__stack_not_full__returned_0()
{
    OperationStack *stack;

    stack = create_stack();
    assert(stack_is_full(stack) == 0);
    destroy_stack(stack);
}

void stack_is_empty__stack_empty__returned_1()
{
    OperationStack *stack;

    stack = create_stack();
    assert(stack_is_empty(stack) == 1);
    destroy_stack(stack);
}

void stack_is_empty__stack_not_empty__returned_0()
{
    OperationStack *stack;
    Ingredient *ingredient;
    Operation *operation;

    ingredient = create_ingredient(1, "a", "a", 2);
    operation = create_operation(ingredient, "add");
    stack = create_stack();
    push(stack, operation);
    assert(stack_is_empty(stack) == 0);
    destroy_stack(stack);
}

void test__OperationStack()
{
    create_destroy_OperationStack__valid__OperationStack_created_destroyed();
    push__valid__operation_pushed();
    stack_is_full__stack_not_full__returned_0();
    stack_is_empty__stack_empty__returned_1();
    stack_is_empty__stack_not_empty__returned_0();
}
