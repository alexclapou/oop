#include "domain.h"
#include <iostream>
#include <sstream>

Book::Book(std::string _name, int _pages):name{_name}, pages{_pages}{
}

Book::Book(){
}

std::string Book::get_name(){
    return name;
}

int Book::get_pages(){
    return pages;
}

std::ostream& operator<<(std::ostream& os, Book &book){
    os<<book.get_name()<<","<<book.get_pages()<<'\n';
    return os;
}

std::vector<std::string> tokenize(std::string line, char delimiter)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(line);
	while(getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::istream& operator>>(std::istream& is, Book &book){
    std::string line;
    std::getline(is, line);
    std::vector<std::string> result = tokenize(line, ',');
    book.name = result[0];
    book.pages = stoi(result[1]);
    return is;
}
bool Book::operator==(Book a_book){
    return a_book.get_name() == name;
}
