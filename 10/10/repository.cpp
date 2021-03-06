#include "repository.h"
#include <iterator>
#include <fstream>

int Repository::add_file_data(Task task_to_add)
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    std::ofstream fout(filepath, std::ios::app);
    fout<<task_to_add.to_string()<<'\n';
    fout.close();
    return 1;
}

int Repository::add_to_servant_list(Task task)
{
    if(!mylistpath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    if (get_extension() == ".csv") {
        std::ofstream fout(mylistpath, std::ios::app);
        fout << task.remove_not_needed_strings(task.to_string()) << '\n';
        fout.close();
    }
    else
        write_to_html(task);
    return 1;
}

int Repository::remove_file_data(std::string task_title)
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int line_index;
    std::string path_directory = filepath;
    size_t what_kind_of_path;
    what_kind_of_path = path_directory.find("\\");
    if (what_kind_of_path == std::string::npos) {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('/'), path_directory.end());
        path_directory += "/temp_file.txt";
    }
    else {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('\\'), path_directory.end());
        path_directory += "\\temp_file.txt";
    }
    int line_to_delete_index;
    std::ifstream fin(filepath);
    std::ofstream fout(path_directory);
    std::string line;

    line_index = 0;
    line_to_delete_index= search_task_title(task_title);
    Task task;
    while(fin>>task){
        if(line_index != line_to_delete_index)
            fout<<task.to_string()<<'\n';
        line_index++;
    }
    fin.close();
    fout.close();
    remove(filepath.c_str());
    rename(path_directory.c_str(), filepath.c_str());
    return 1;
}

int Repository::update_file_data(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision)
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    std::string path_directory = filepath;
    size_t what_kind_of_path;
    what_kind_of_path = path_directory.find("\\");
    if (what_kind_of_path == std::string::npos) {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('/'), path_directory.end());
        path_directory += "/temp_file.txt";
    }
    else {
        path_directory.erase(path_directory.begin() + path_directory.find_last_of('\\'), path_directory.end());
        path_directory += "\\temp_file.txt";
    }
    std::ifstream fin(filepath);
    std::ofstream fout(path_directory);
    int index_to_update, index_line;
    std::string line;

    index_line = 0;
    index_to_update = search_task_title(title);
    Task task_updated(title, new_type, new_last_performed, new_times_performed, new_vision);
    Task task;
    while(fin>>task){
        if(index_to_update == index_line)
            fout<<task_updated.to_string()<<'\n';
        else
            fout<<task.to_string()<<'\n';
        index_line++;
    }
    fin.close();
    fout.close();
    remove(filepath.c_str());
    rename(path_directory.c_str(), filepath.c_str());
    return 1;
}

int Repository::get_number_of_tasks()
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int number_of_lines;
    std::string line;
    std::ifstream fin(filepath);

    number_of_lines = 0;
    while(std::getline(fin, line))
        number_of_lines++;
    fin.close();
    return number_of_lines;
}

int Repository::get_number_of_saved_tasks()
{
    if(!mylistpath_exist())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    int number_of_lines;
    std::string line;
    std::ifstream fin(mylistpath);

    if(get_extension() == ".csv"){
        number_of_lines = 0;
        while(std::getline(fin, line))
            number_of_lines++;
        fin.close();
    }
    else{
        number_of_lines = 0;
        while(std::getline(fin, line))
            if(line == "</tr>")
                number_of_lines++;
        fin.close();
        number_of_lines -= 1;
    }
    return number_of_lines;
}

bool Repository::task_duplicate(std::string title)
{
    if(search_task_title(title) != -1)
        return true;
    return false;

}

std::vector<Task> Repository::get_list_of_tasks()
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    std::vector<Task> tasks;
    std::ifstream fin(filepath);
    Task task;
    while(fin>>task)
        tasks.push_back(task);
    fin.close();
    return tasks;    
}

Task Repository::get_task(int position)
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int task_index;
    Task task;

    task_index = 0;
    std::ifstream fin(filepath);
    while(fin>>task && task_index < position)
        task_index++;
    fin.close();
    return task;
}

int Repository::search_task_title(std::string title)
{
    if(!filepath_exist())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int task_index;
    Task task;

    task_index = 0;
    std::string line;
    std::ifstream fin(filepath);
    while(fin>>task){
        if(task.get_title() == title){
            fin.close();
            return task_index;
        }
        else
            task_index++;
    }
    fin.close();
    return -1;
}

void Repository::set_filepath(std::string new_filepath)
{
    std::string path_directory, extension;
    size_t file_exist;

    path_directory = new_filepath;
    file_exist = new_filepath.find(".");
    if(file_exist == std::string::npos)
        throw RepositoryException(std::string("there is no extension for the repository file\n"));
    extension = new_filepath.substr(file_exist, new_filepath.size());
    if(extension != ".txt")
        throw RepositoryException(std::string("bad extension for repository\n"));
    //we already have the txt file /home/alexclapou/fac/oop/7/file.txt

    
    filepath = new_filepath;
}

void Repository::set_mylistpath(std::string new_mylistpath)
{
    std::string path_directory;
    size_t file_exist;

    path_directory = new_mylistpath;
    file_exist = new_mylistpath.find(".");
    if(file_exist == std::string::npos)
        throw RepositoryException(std::string("there is no extension for the repository file\n"));
    mylist_extension = new_mylistpath.substr(file_exist, new_mylistpath.size());
    if(mylist_extension != ".html" && mylist_extension != ".csv"){
        mylist_extension.clear();
        throw RepositoryException(std::string("bad extension for mylist\n"));
    }
    size_t what_kind_of_path;
    what_kind_of_path = path_directory.find("\\");
    if(what_kind_of_path == std::string::npos)
        path_directory.erase(path_directory.begin()+path_directory.find_last_of('/'), path_directory.end());
    else
        path_directory.erase(path_directory.begin()+path_directory.find_last_of('\\'), path_directory.end());
    mylistpath = new_mylistpath;
    if(mylist_extension == ".html" && !mylistpath.empty()){
        std::ifstream fin(mylistpath);
        if(!fin.good())
            init_html_file();
        fin.close();
    }
}

std::string Repository::get_filepath()
{
    if(filepath_exist())
        return filepath;
    return "path is empty";
}

std::string Repository::get_mylistpath()
{
    if(mylistpath_exist())
        return mylistpath;
    return "path is empty";
}

bool Repository::filepath_exist()
{
    if(filepath.empty())
        return false;
    return true;
}

bool Repository::mylistpath_exist()
{
    if(mylistpath.empty())
        return false;
    return  true;
}
std::string Repository::get_extension()
{
    return mylist_extension;
}

void Repository::write_to_html(Task task_to_add)
{
    if(!mylistpath_exist())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    std::string path_directory = filepath;
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
    std::ifstream fin(mylistpath);
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
    remove(mylistpath.c_str());
    rename(path_directory.c_str() , mylistpath.c_str());

}

void Repository::init_html_file()
{
    if(!mylistpath_exist())
        throw RepositoryException(std::string("there s no path to mylist\n"));
    std::ofstream fout(mylistpath);
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
