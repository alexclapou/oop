#include "ingredient.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

Ingredient *create_ingredient(int cataloging_number, char *state, char *intended_use, int potency)
{
    Ingredient *new_ingredient;

    new_ingredient = (Ingredient*)malloc(sizeof(Ingredient));
    new_ingredient->cataloging_number = cataloging_number;
    new_ingredient->state = (char*)malloc(sizeof(char) * (strlen(state)+1));
    strcpy(new_ingredient->state, state);
    new_ingredient->intended_use = (char*)malloc(sizeof(char) * (strlen(intended_use)+1));
    strcpy(new_ingredient->intended_use, intended_use);
    new_ingredient->potency = potency;
    return new_ingredient;
}

void destroy_ingredient(Ingredient *ingredient)
{
    free(ingredient->state);
    free(ingredient->intended_use);
    free(ingredient);
}

int get_cataloging_number(Ingredient *ingredient)
{
    return ingredient->cataloging_number;
}

char *get_state(Ingredient *ingredient)
{
    return ingredient->state;
}
void set_state(Ingredient *ingredient, char *new_state)
{
    strcpy(ingredient->state, new_state);
}

char *get_intended_use(Ingredient *ingredient)
{
    return ingredient->intended_use;
}
void set_intended_use(Ingredient *ingredient, char *new_intended_use)
{
    strcpy(ingredient->intended_use, new_intended_use);
}

int get_potency(Ingredient *ingredient)
{
    return ingredient->potency;
}
void set_potency(Ingredient *ingredient, int new_potency)
{
    ingredient->potency = new_potency;
}

Ingredient* copy_ingredient(Ingredient* ingredient)
{
	if (ingredient == NULL)
		return NULL;

	Ingredient* new_ingredient = create_ingredient(get_cataloging_number(ingredient), get_state(ingredient), get_intended_use(ingredient), get_potency(ingredient));
	return new_ingredient;
}
