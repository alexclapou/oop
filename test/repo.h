#include "domain.h"
#pragma once



class FileRepository{
    private:
        std::string filename;
    public:
        FileRepository(std::string name):filename{name}{}
        void add(Book book);
        void update(Book new_book){};
        void remove(std::string title){};
        virtual void save(Book book){};
};

class HTMLRepository:public FileRepository{
    private:
        std::string mylistpath;
        void init_html_file();
    public:
        void save(Book book)override;
        HTMLRepository(std::string file, std::string mylist):FileRepository{file}, mylistpath{mylist}{init_html_file();}
};

class CSVRepository:public FileRepository{
    private:
        std::string mylistpath;
    public:
        void save(Book book){};
        CSVRepository(std::string file, std::string mylist):FileRepository{file}, mylistpath{mylist}{}
};
