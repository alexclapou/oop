#include "csvrepository.h"
#include <fstream>

int CSVRepository::add(Task task)
{
    std::ofstream fout(mylistpath, std::ios::app);
    if(mylistpath.empty() || !fout.good())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    fout << task.remove_not_needed_strings(task.to_string()) << '\n';
    fout.close();
    return 1;
}
