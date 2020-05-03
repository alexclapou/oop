#include <iostream>
#include "shape.h"

int main()
{
    Square sq;
    Rectangle re;

    Shape sh = sq;
    sh.form();
}
