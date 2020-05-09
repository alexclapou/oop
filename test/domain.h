#include <string>
#pragma once
#include <vector>
 std::vector<std::string> tokenize(std::string line, char delimiter);
class Book{
    private:
        std::string name;
        int pages;
    public:
        Book(std::string _name, int _pages);
        Book();
        std::string get_name();
        int get_pages();
        bool operator==(Book book);
        friend std::ostream& operator<<(std::ostream& os, Book &book);
        friend std::istream& operator>>(std::istream& is, Book &book);
};
