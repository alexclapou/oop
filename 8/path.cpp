/*
#include <fstream>
#include <iostream>
#include <string>

std::string get_directories_path(std::string path)
{
    int last_directory;

    last_directory = path.find_last_of('/');
    std::cout<<path<<'\n';
    path.erase(path.begin()+last_directory, path.end());
    std::cout<<path<<'\n';
    return path;
}

bool exist(std::string path)
{
    std::ifstream fin(path);
    return fin.good();
}
int main()
{
    std::string path = "/home/alexclapou/fac/oop/folder cu spatii/fisier.txt";
    path = get_directories_path(path);
    std::cout<<exist(path);
}
*/
