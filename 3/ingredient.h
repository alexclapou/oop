#pragma once

typedef struct{
    int cataloging_number;
    char state[50];
    char intended_use[50];
    int potency;
}Ingredient;

Ingredient create_ingredient(int cataloging_number, char state[], char intended_use[], int potency);

int get_cataloging_number(Ingredient ingredient);

char *get_state(Ingredient *ingredient);

void set_state(Ingredient *ingredient, char *new_state);


char *get_use(Ingredient *ingredient);

void set_use(Ingredient *ingredient, char *new_intended_use);


int  get_potency(Ingredient ingredient);

void set_potency(Ingredient *ingredient, int new_potency);

	