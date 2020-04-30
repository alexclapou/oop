#include "repository.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
Repository* create_repository()
{
    Repository* repo = (Repository*)malloc(sizeof(Repository));
    if(repo == NULL)
        return NULL;
    repo->length = 0;
    return repo;
}

void destroy_repository(Repository* repo)
{
    free(repo);
}

int find_planet(Repository *repo, Planet p)
{
    for(int i = 0; i < repo->length; i++)
        if(strcmp(get_name(&repo->elems[i]), get_name(&p)) == 0)
            return 1;
    return 0;
}

int add_planet(Repository* repo, Planet p)
{
    if(find_planet(repo, p))
        return 1;
    repo->elems[repo->length++] = p;
    return 0;
}

void test_test()
{
    Repository* repo = create_repository();
    Planet p = create_planet("Earth", "Terrestial", 0);
    assert(add_planet(repo, p) == 0);
    assert(add_planet(repo, p) == 1);
    printf("\n%d", 0);
}
