#include "task.h"
#include <string>
#include <ctime>

Task::Task(std::string title, std::string type, tm last_performed_date,  int times_performed, std::string vision)
{
    this->title = title;
    this->type = type;
    this->last_performed_date.tm_mday = last_performed_date.tm_mday;
    this->last_performed_date.tm_mon= last_performed_date.tm_mon;
    this->last_performed_date.tm_year = last_performed_date.tm_year;
    this->times_performed = times_performed;
    this->vision = vision;
}

std::string Task::to_string()
{
    std::string day, month, year;
    year = std::to_string(last_performed_date.tm_year);
    day = "0";
    month = "0";
    if(last_performed_date.tm_mday < 10)
        day += std::to_string(last_performed_date.tm_mday);
    else
        day = std::to_string(last_performed_date.tm_mday);
    if(last_performed_date.tm_mon < 10)
        month += std::to_string(last_performed_date.tm_mon);
    else
        month = std::to_string(last_performed_date.tm_mon);
    std::string date = "";
    date = month + "-" + day + "-" + year;
    return "TITLE: " + get_title() + " TYPE: " + get_type() + " LAST PERFORMED DATE: " + date + " TIME PERFORMED: " + std::to_string(get_times_performed()) + " VISION: " + get_vision();
}

Task::Task()
{
    times_performed = 0;
}
std::string Task::get_title()const{
    return title;
}

std::string Task::get_type()const{
    return type;
}

int Task::get_last_performed_day()const{
    return last_performed_date.tm_mday;
}

int Task::get_last_performed_month()const{
    return last_performed_date.tm_mon;
}

int Task::get_last_performed_year()const{
    return last_performed_date.tm_year;
}

 int Task::get_times_performed()const{
    return times_performed;
}

std::string Task::get_vision()const{
    return vision;
}

void Task::set_title(std::string new_title){
    title = new_title;
}

void Task::set_type(std::string new_type){
    type = new_type;
}

void Task::set_last_performed_day(int day){
    last_performed_date.tm_mday = day;
}

void Task::set_last_performed_month(int month){
    last_performed_date.tm_mon = month;
}

void Task::set_last_performed_year(int year){
    last_performed_date.tm_year = year;
}

void Task::set_times_performed( int new_times_performed){
    times_performed = new_times_performed;
}

void Task::set_vision(std::string new_vision){
        vision = new_vision;
}

bool Task::operator==(const Task first_task)
{
    if(first_task.get_title() != title)
        return false;
    if(first_task.get_type() != type)
        return false;
    if(first_task.get_last_performed_day() != last_performed_date.tm_mday)
        return false;
    if(first_task.get_last_performed_month() != last_performed_date.tm_mon)
        return false;
    if(first_task.get_last_performed_year() != last_performed_date.tm_year)
        return false;
    if(first_task.get_times_performed() != times_performed)
        return false;
    if(first_task.get_vision() != vision)
        return false;
    return true;
}


void Task::operator=(const Task task)
{
    title = task.get_title();
    type = task.get_type();
    last_performed_date.tm_mday = task.get_last_performed_day();
    last_performed_date.tm_mon = task.get_last_performed_month();
    last_performed_date.tm_year = task.get_last_performed_year();
    times_performed = task.get_times_performed();
    vision = task.get_vision();
}
