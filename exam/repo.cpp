#pragma once
#include "repo.h"
#include <sstream>
#include <fstream>
#include <QDebug>

std::vector<std::string> read_file(std::string read){
    std::vector<std::string> line;
    std::string token;
    std::stringstream ss(read);
    while (std::getline(ss, token, ','))
        line.push_back(token);
    return line;
}

/*
bool cond(Student a, Student b){
    if(a.get_year() == 2020 && b.get_year() != 2020)
        return true;
    if(b.get_year() == 2020 && a.get_year() != 2020)
        return false;
    return a.get_year() > b.get_year();
}
*/

std::vector<Star> Repository::get_stars()const{
    return stars;
}

void Repository::add_star(Star new_star){
    /*parameters: new_star - Star we want to add
     *add the new star to the stars list
     *output: new star is added
     * return if star has bad info or already exist;
     */
    if(new_star.get_name() == "" || new_star.get_ra() <= 0 || new_star.get_dec() <= 0)
        return;
    for(auto star:stars)
        if(star.get_name() == new_star.get_name())
            return;
    stars.push_back(new_star);
}

int Repository::stars_size()const{
    return stars.size();
}

std::vector<Astronomer> Repository::get_astronomers(){
    return astronomers;
}

void Repository::init(){
    std::ifstream read_stars(starfile);
    std::string line;
    while(std::getline(read_stars, line)){
       std::vector<std::string> all = read_file(line);
       Star new_star(all[0], all[1], stoi(all[2]), stoi(all[3]), stoi(all[4]));
       stars.push_back(new_star);
    }
    read_stars.close();

    std::ifstream read_astronomers(astronomerfile);
    while(std::getline(read_astronomers, line)){
       std::vector<std::string> all = read_file(line);
       Astronomer new_astronomer(all[0], all[1]);
       astronomers.push_back(new_astronomer);
    }
    read_astronomers.close();
}
