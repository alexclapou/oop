#include "htmlrepository.h"
#include <fstream>

int HTMLRepository::add(Task task_to_add)
{
    std::ifstream fin(mylistpath);
    if(mylistpath.empty() || !fin.good())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    std::string path_directory = mylistpath;
    size_t what_kind_of_path;
    what_kind_of_path = path_directory.find("\\");
    if (what_kind_of_path == std::string::npos) {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('/'), path_directory.end());
        path_directory += "/temp_file.html";
    }
    else {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('\\'), path_directory.end());
        path_directory += "\\temp_file.html";
    }
    std::ofstream fout(path_directory);
    std::string line;

    while(std::getline(fin, line)){
        if(line == "</table>"){
            fout<<"<tr>\n";
            fout<<"<td>"<<task_to_add.get_title()<<"</td>\n";
            fout<<"<td>"<<task_to_add.get_type()<<"</td>\n";
            fout<<"<td>"<<task_to_add.get_last_performed_month()<<"-"<<task_to_add.get_last_performed_day()<<"-"<<task_to_add.get_last_performed_year()<<"</td>\n";
            fout<<"<td>"<<task_to_add.get_times_performed()<<"</td>\n";
            fout<<"<td>"<<task_to_add.get_vision()<<"</td>\n";
            fout<<"</tr>\n";
            fout<<"</table>\n";
        }
        else
            fout<<line<<'\n';
    }
    fin.close();
    fout.close();
    rename(path_directory.c_str() , mylistpath.c_str());
    return 1;
}

void HTMLRepository::init_html_file()
{
    std::ofstream fout(mylistpath);
    if(mylistpath.empty() || !fout.good())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    fout<<"<!DOCTYPE html>\n";
    fout<<"<html>\n";
    fout<<"<head>\n";
    fout<<"<title>Saved Tasks</title>\n";
    fout<<"</head>\n";
    fout<<"<body>\n";
    fout<<"<table border='1'>\n";
    fout<<"<tr>\n";
    fout<<"<td>Title</td>\n";
    fout<<"<td>Type</td>\n";
    fout<<"<td>Last performed date</td>\n";
    fout<<"<td>Times performed</td>\n";
    fout<<"<td>Vision</td>\n";
    fout<<"</tr>\n";
    fout<<"</table>\n";
    fout<<"</body>\n";
    fout<<"</html>";
    fout.close();
}
