#include <string>

class Shape{
    protected:
    public:
        virtual void form(){std::cout<<"UNKNOWN FORM";}
};

class Square:public Shape{
    public:
        void form(){std::cout<<"SQUARE\n";} // if comment this we have an unknown class ( not pure virtual function )
};

class Rectangle:public Shape{
    public:
        void form(){std::cout<<"RECTANGLE\n";} // if comment this and we have a pure virtual class = > compile error( we must have the function for every pure virtual function)
};
