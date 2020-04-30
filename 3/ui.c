#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ingredient.h"
#include "repository.h"
#include "service.h"
#include "ui.h"

UI create_UI(Service Service)
{
    UI ui;
    ui.service = Service;
    return ui;
}

void read_command(char *what_command, char *command_arguments)
{
    char input_text[50];
    char *argument_of_command;

    gets(input_text);
    argument_of_command = strtok(input_text, ", ");
    strcpy(what_command, argument_of_command);
    argument_of_command = strtok(NULL, "\0");
    if(argument_of_command)
        strcpy(command_arguments, argument_of_command);
    else
        strcpy(command_arguments, "");
}

void list(UI ui)
{
    int ingredient_index, number_of_ingredients;
    Ingredient *ingredients;

    ingredient_index = 0;
    number_of_ingredients = service__get_number_of_ingredients(ui.service);
    ingredients = service__get_ingredients(ui.service);
    while(ingredient_index < number_of_ingredients){
       printf("Cataloging number:%d; State:%s; Intended use:%s; Potency:%d;\n", get_cataloging_number(ingredients[ingredient_index]), get_state(&ingredients[ingredient_index]), get_use(&ingredients[ingredient_index]), get_potency(ingredients[ingredient_index]));
        ingredient_index++;
    }
}

void list_intended_use(UI ui, char *command_arguments)
{
    int ingredient_index, number_of_ingredients;
    Ingredient *ingredients;

    ingredient_index = 0;
    number_of_ingredients = service__get_number_of_ingredients(ui.service);
    ingredients = service__get_ingredients(ui.service);
    while(ingredient_index < number_of_ingredients){
        if(strcmp(get_state(&ingredients[ingredient_index]), command_arguments) == 0)
           printf("Cataloging number:%d; State:%s; Intended use:%s; Potency:%d;\n", get_cataloging_number(ingredients[ingredient_index]), get_state(&ingredients[ingredient_index]), get_use(&ingredients[ingredient_index]), get_potency(ingredients[ingredient_index]));
        ingredient_index++;
    }
}

int check_input_add_or_update(char *command_arguments)
{
    char *cataloging_number, *state, *intended_use, *potency;

    cataloging_number = strtok(command_arguments, ", ");
    if(cataloging_number == NULL || atoi(cataloging_number) == 0)
        return 0;
    state = strtok(NULL, ", ");
    if(state == NULL || atoi(state) != 0)
        return 0;
    intended_use = strtok(NULL, ", ");
    if(intended_use == NULL || atoi(intended_use) != 0)
        return 0;
    potency = strtok(NULL, ", ");
    if(potency == NULL || atoi(potency) == 0)
        return 0;
    return 1;
}

void ui__add_ingredient(UI *ui, char *command_arguments)
{
    char *cataloging_number, *state, *intended_use, *potency, copy_command_arguments[50];
    int int_cataloging_number, int_potency, ingredient_found;

    strcpy(copy_command_arguments, command_arguments);
    if(check_input_add_or_update(copy_command_arguments) == 1){
        cataloging_number = strtok(command_arguments, ", ");
        state = strtok(NULL, ", ");
        intended_use = strtok(NULL, ", ");
        potency = strtok(NULL, ", ");
        int_cataloging_number = atoi(cataloging_number);
        int_potency = atoi(potency);
        ingredient_found = validate__add_ingredient(&ui->service, int_cataloging_number, state, intended_use, int_potency);
        if(ingredient_found == -1)
            printf("No!\n");
    }
    else
        printf("No!\n");
}

void ui__update_ingredient(UI *ui, char *command_arguments)
{
    char *cataloging_number, *state, *intended_use, *potency, copy_command_arguments[50];
    int int_cataloging_number, int_potency, ingredient_found;

    strcpy(copy_command_arguments, command_arguments);
    if(check_input_add_or_update(copy_command_arguments) == 1){
        cataloging_number = strtok(command_arguments, ", ");
        state = strtok(NULL, ", ");
        intended_use = strtok(NULL, ", ");
        potency = strtok(NULL, ", ");
        int_cataloging_number = atoi(cataloging_number);
        int_potency = atoi(potency);
        ingredient_found = validate__update_ingredient(&ui->service, int_cataloging_number, state, intended_use, int_potency);
        if(ingredient_found == -1)
            printf("No!\n");
    }
    else
        printf("No!\n");
}

int check_input_delete(char *command_arguments)
{
    if(atoi(command_arguments) == 0)
        return 0;
    return 1;
}

void ui__delete_ingredient(UI *ui, char *command_arguments)
{
    int cataloging_number, ingredient_found;
    char copy_command_arguments[50];

    strcpy(copy_command_arguments, command_arguments);
    if(check_input_delete(copy_command_arguments) == 1){
        cataloging_number = atoi(command_arguments);
        ingredient_found = validate__delete_ingredient(&ui->service, cataloging_number);
        if(ingredient_found == -1)
            printf("No!\n");
    }
    else
        printf("No!\n");
}

void start(UI ui)
{
    while(1){
        char what_command[50], command_arguments[50];
        read_command(what_command, command_arguments);
        if(strcmp(what_command, "add") == 0){
            ui__add_ingredient(&ui, command_arguments);
        }
        if(strcmp(what_command, "list") == 0){
            if(strlen(command_arguments) > 0)
                list_intended_use(ui, command_arguments);
            else
                list(ui);
        }
        if(strcmp(what_command, "update") == 0)
            ui__update_ingredient(&ui, command_arguments);
        if(strcmp(what_command, "delete") == 0)
            ui__delete_ingredient(&ui, command_arguments);
        if(strcmp(what_command, "exit") == 0)
            break;
    }
}
