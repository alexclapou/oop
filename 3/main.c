#include <stdio.h>
#include "ingredient.h"
#include "repository.h"
#include "service.h"
#include "ui.h"

int main()
{
    Repository repo;
    Service service;
    UI ui;

    repo = create_repository();
    service = create_service(repo);
    ui = create_UI(service);
    start(ui);
}
