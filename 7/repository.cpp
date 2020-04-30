#include "repository.h"
#include <iterator>
#include <fstream>

int Repository::add_file_data(Task task_to_add)
{
    std::ofstream fout(filepath, std::ios::app);
    fout<<task_to_add;
    fout.close();
    return 1;
}

int Repository::add_to_servant_list(Task task)
{
    servant_task_list.push_back(task);
    return 1;
}

int Repository::remove_file_data(std::string task_title)
{
    int line_index;
    int line_to_delete_index;
    std::ifstream fin(filepath);
    std::ofstream fout("temp_file.txt");
    std::string line;

    line_index = 0;
    line_to_delete_index= search_task_title(task_title);
    Task task;
    while(fin>>task){
        if(line_index != line_to_delete_index)
            fout<<task;
        line_index++;
    }
    fin.close();
    fout.close();
    remove(filepath.c_str());
    rename("temp_file.txt", filepath.c_str());
    if(get_number_of_tasks() == 0)
        remove(filepath.c_str());
    return 1;
}

int Repository::update_file_data(std::string title, std::string new_type, tm new_last_performed, int new_times_performed, std::string new_vision)
{
    std::ifstream fin(filepath);
    std::ofstream fout("temp_file.txt");
    int index_to_update, index_line;
    std::string line;

    index_line = 0;
    index_to_update = search_task_title(title);
    Task task_updated(title, new_type, new_last_performed, new_times_performed, new_vision);
    Task task;
    while(fin>>task){
        if(index_to_update == index_line)
            fout<<task_updated;
        else
            fout<<task;
        index_line++;
    }
    fin.close();
    fout.close();
    remove(filepath.c_str());
    rename("temp_file.txt", filepath.c_str());
    return 1;
}

int Repository::get_number_of_tasks()
{
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
    return servant_task_list.size();
}

bool Repository::task_duplicate(std::string title)
{
    if(search_task_title(title) != -1)
        return true;
    return false;

}

std::vector<Task> Repository::get_list_of_tasks()
{
    std::vector<Task> tasks;
    std::ifstream fin(filepath);
    Task task_read;
    while(fin>>task_read)
        tasks.push_back(task_read);
    return tasks;    
}

std::vector<Task> Repository::get_list_of_saved_tasks()const
{
    return servant_task_list;
}

Task Repository::get_task(int position)
{
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
    std::string path_directory;
    bool path_exist;

    path_directory = new_filepath;
    //assume we give the txt file /home/alexclapou/fac/oop/7/file.txt
    if(path_directory.find_last_of('/'))
      path_directory.erase(path_directory.begin()+path_directory.find_last_of('/'), path_directory.end());
  else
    path_directory.erase(path_directory.begin()+path_directory.find_last_of('\\'), path_directory.end());
    std::ifstream fin(path_directory);
    path_exist = fin.good();
    if(path_exist)
        filepath = new_filepath;
    else{
        filepath.clear(); 
    }
    fin.close();
}

std::string Repository::get_filepath()
{
    if(filepath_exist())
        return filepath;
    return "path is empty";
}

bool Repository::filepath_exist()
{
    if(filepath.empty()){
        return false;
    }
    return true;
}
