#include "service.h"

void Service::add(Book book){
    repo.add(book);
}

void Service::save(Book book){
    repo.save(book);
}
