#pragma once
#include "Planet.h"

#define MAX_DIM 100

typedef struct{
    Planet elems[MAX_DIM];
    int length;
}Repository;

Repository* create_repository();
void destroy_repository(Repository* repo);
/*
 * search for planet in the repository
 * input:repo - pointer to repo
 *       p - planet
 * output: 1 if planet was found
          0 otherwise
 */
int find_planet(Repository* repo, Planet p);
/*
 * adds a planet to the repository
 * input: repo - pointer to repository
 *        p - Planet
 * output: 1 if the playet was not added
 *         0 otherwise
 */
int add_planet(Repository* repo, Planet p);
void test_test();
