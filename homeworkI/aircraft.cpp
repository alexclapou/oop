#include "aircraft.h"

int Aircraft::get_maximum_altitute(){
    return maximum_altitude;
}

std::string Aircraft::get_model()
{
    return model;
}

std::vector<std::string> Aircraft::get_activities(){
    return activities;
}

