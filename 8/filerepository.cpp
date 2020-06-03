#include "filerepository.h"
#include <iterator>
#include <fstream>

int FileRepository::add(Task task_to_add)
{
    std::ofstream fout(filepath, std::ios::app);
    if(filepath.empty() || !fout.good())
        throw RepositoryException(std::string("there s no path to repository\n"));
    fout<<task_to_add.to_string()<<'\n';
    fout.close();
    return 1;
}


int FileRepository::remove(std::string task_title)
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
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
    rename(path_directory.c_str(), filepath.c_str());
    return 1;
}

int FileRepository::update(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision)
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
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
    rename(path_directory.c_str(), filepath.c_str());
    return 1;
}

unsigned int FileRepository::get_number_of_tasks()
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int number_of_lines;
    std::string line;

    number_of_lines = 0;
    while(std::getline(fin, line))
        number_of_lines++;
    fin.close();
    return number_of_lines;
}

std::vector<Task> FileRepository::get_list_of_tasks()
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
        throw RepositoryException(std::string("there s no path to repository\n"));
    std::vector<Task> tasks;
    Task task;

    while(fin>>task)
        tasks.push_back(task);
    fin.close();
    return tasks;    
}

Task FileRepository::get_task(unsigned int position)
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int task_index;
    Task task;

    task_index = 0;
    while(fin>>task && task_index < position)
        task_index++;
    fin.close();
    return task;
}

int FileRepository::search_task_title(std::string title)
{
    std::ifstream fin(filepath);
    if(filepath.empty() || !fin.good())
        throw RepositoryException(std::string("there s no path to repository\n"));
    int task_index;
    Task task;

    task_index = 0;
    std::string line;
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

void FileRepository::set_filepath(std::string new_filepath){
    filepath = new_filepath;
}

std::string FileRepository::get_filepath(){
    return filepath;
}
