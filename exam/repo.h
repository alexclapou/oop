#pragma once
#include "domain.h"
#include <vector>

std::vector<std::string> read_file(std::string read);
class Repository{
    private:
        std::vector<Astronomer> astronomers;
        std::vector<Star> stars;
        std::string astronomerfile, starfile;
    public:
        std::string get_astrofile(){
            return astronomerfile;
        }
        std::string get_starfile(){
            return starfile;
        }
        Repository(std::string _a, std::string _s):astronomerfile{_a}, starfile{_s}{init();}
        void init();
        std::vector<Star> get_stars()const;
        std::vector<Astronomer> get_astronomers();
        int stars_size()const;
        void add_star(Star new_star);
};
