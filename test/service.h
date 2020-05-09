#include "repo.h"
#pragma once

class Service{
    private:
        FileRepository &repo;

    public:
        Service(FileRepository &repository):repo {repository}{}
        void add(Book book);
        void save(Book book);

};
