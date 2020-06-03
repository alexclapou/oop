#include "filerepository.h"

class HTMLRepository:public FileRepository{
    private:
        std::string mylistpath;
    public:
        HTMLRepository(std::string filename, std::string mylist):FileRepository(filename), mylistpath{mylist}{init_html_file();}
        int add(Task task)override;
        void write_to_html(Task task_to_add);
        void init_html_file();
};
