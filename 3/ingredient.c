#include "ingredient.h"
#include <stdio.h>
#include <string.h>

Ingredient create_ingredient(int cataloging_number, char state[], char intended_use[], int potency)
{
    Ingredient new_ingredient;

    new_ingredient.cataloging_number = cataloging_number;
    strcpy(new_ingredient.state, state);
    strcpy(new_ingredient.intended_use, intended_use);
    new_ingredient.potency = potency;
    return new_ingredient;
}

int get_cataloging_number(Ingredient ingredient)
{
    return ingredient.cataloging_number;
}

char *get_state(Ingredient *ingredient)
{
    return ingredient->state;
}
void set_state(Ingredient *ingredient, char *new_state)
{
    strcpy(ingredient->state, new_state);
}

char *get_use(Ingredient *ingredient)
{
    return ingredient->intended_use;
}
void set_use(Ingredient *ingredient, char *new_intended_use)
{
    strcpy(ingredient->intended_use, new_intended_use);
}

int get_potency(Ingredient ingredient)
{
    return ingredient.potency;
}
void set_potency(Ingredient *ingredient, int new_potency)
{
    ingredient->potency = new_potency;
}
