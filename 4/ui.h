#pragma once
#include "service.h"

typedef struct{
    Service *service;
}UI;

UI *create_UI(Service *service);
void destroy_UI(UI *ui);
void read_command(char *what_command, char *cmd_arguments);
/*read the command from keyboard
 * parameters: what_command - the command we want to execute(add, delete, update)
 *             cmd_arguments - arguments of the command(cataloging number/state/intended use/potency)
 *output:
 */
void list(UI *ui);
/*list all the ingredients with every specification
 * parameters:ui - UI structure
 */
void list_intended_use(UI *ui, char *intended_use);
/*list all the ingredients with a given intended use
 * parameters: intended_use - intended use of the ingredients we want to list
 */
int check_for_null_pointer(char *pointer);
/*check if a char pointer is null or not
 * parameters: a pointer
 * output:1 if it's null
 *        0 otherwise
 */
void start(UI *ui);
//start the application
void ui__add_ingredient(UI *ui, char *cmd_arguments);
int check_input_add_or_update(char *cmd_arguments);
/*check if the input is valid for add function or update function
 * parameters: cmd_arguments - arguments of the add function or update function
 * output:1 valid arguments
 *        0 otherwise
 */
void ui__update_ingredient(UI *ui, char *cmd_arguments);
int check_input_delete(char *cmd_arguments);
void ui__delete_ingredient(UI *ui, char *cmd_arguments);
void list_maximum_state(UI *ui, int given_maximum_potency);
