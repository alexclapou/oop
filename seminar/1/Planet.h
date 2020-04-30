#pragma once

typedef struct{
    char name[50];
    char type[50];
    double distance_from_earth;
}Planet;

Planet create_planet(char name[], char type[], double distance);
double get_distance(Planet p);
char* get_name(Planet* p);
void test();
