#include "repo.h"
#include <fstream>

void FileRepository::add(Book book){
    std::ofstream fout(filename, std::ios::app);
    fout<<book;
    fout.close();
}

void HTMLRepository::save(Book book){
    std::ifstream fin(mylistpath);
    std::ofstream fout("temp_file.html");
    std::string line;
    while(std::getline(fin, line)){
        if(line == "</table>"){
            fout<<"<tr>\n";
            fout<<"<td>"<<book.get_name()<<"</td>\n";
            fout<<"<td>"<<book.get_pages()<<"</td>\n";
            fout<<"</tr>\n";
            fout<<"</table>\n";
        }
        else
            fout<<line<<'\n';
    }
    fin.close();
    fout.close();
    remove(mylistpath.c_str());
    rename("temp_file.html", mylistpath.c_str());
}

void HTMLRepository::init_html_file()
{
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

