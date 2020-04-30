#include "Planet.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

Planet create_planet(char name[], char type[], double distance)
{
    Planet p;
    strcpy(p.name, name);
    strcpy(p.type, type);
    p.distance_from_earth = distance;
    return p;
}

double get_distance(Planet p)
{
    return p.distance_from_earth;
}

char* get_name(Planet* p)
{
    return p->name;
}

void test()
{
    Planet p;
    p = create_planet("Earth", "Terrestial", 0);
    assert(get_distance(p) == 0);
    assert(strcmp(get_name(&p), "Earth") == 0);
    printf("%f", get_distance(p));
}
