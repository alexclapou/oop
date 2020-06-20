#include "domain.h"

std::string Astronomer::get_name(){
    return name;
}

std::string Astronomer::get_constellation(){
    return constellation;
}

std::string Star::get_name(){
    return name;
}

std::string Star::get_constellation(){
    return constellation;
}

int Star::get_ra(){
    return ra;
}

int Star::get_dec(){
    return dec;
}
std::ostream& operator<<(std::ostream& os, Star &star_to_add)
{
    std::string DELIM = ",";
    std::string final_line;
    final_line += star_to_add.get_name();
    final_line+= DELIM;
    final_line += star_to_add.get_constellation();
    final_line+= DELIM;
    final_line += std::to_string(star_to_add.get_ra());
    final_line+= DELIM;
    final_line += std::to_string(star_to_add.get_dec());
    final_line+= DELIM;
    final_line += std::to_string(star_to_add.get_diameter());
    final_line += '\n';
    os<<final_line;
    return os;
}

