#pragma once
#include "service.h"

typedef struct{
    Service service;
}UI;

UI create_UI();
void read_command(char *what_command, char *command_arguments);

void list(UI ui);

void list_intended_use(UI ui, char *intended_use);


void start(UI ui);
void ui__add_ingredient(UI *ui, char *command_arguments);
int check_input_add_or_update(char *command_arguments);

void ui__update_ingredient(UI *ui, char *command_arguments);
int check_input_delete(char *command_arguments);
void ui__delete_ingredient(UI *ui, char *command_arguments);
