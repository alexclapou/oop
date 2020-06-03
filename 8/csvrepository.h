#include "filerepository.h"

class CSVRepository: public FileRepository{
    private:
        std::string mylistpath;
    public:
        CSVRepository(std::string filename, std::string _mylist):FileRepository{filename}, mylistpath{_mylist}{}
        int add(Task task)override;
};
