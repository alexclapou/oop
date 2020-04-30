#include "task.h"
#include <time.h>
#include <sstream>
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
    return "TITLE: " + get_title() + ", TYPE: " + get_type() + ", LAST PERFORMED DATE: " + date + ", TIMES PERFORMED: " + std::to_string(get_times_performed()) + ", VISION: " + get_vision();
}

Task::Task()
{
    this->times_performed = 0;
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
    return first_task.get_title() == title;
}

bool Task::operator!=(const Task first_task)
{
    return first_task.get_title() != title;
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

std::ostream& operator<<(std::ostream& os, Task task_to_add)
{
    os<<task_to_add.to_string()<<'\n';
    return os;
}
std::vector<std::string> tokenize(std::string line, char delimiter)
{
    std::vector<std::string> result;
    std::string token;
    std::stringstream ss(line);
	while (getline(ss, token, delimiter))
		result.push_back(token);
	return result;
}

std::string Task::remove_not_needed_strings(std::string entire_line)
    {
    std::vector<std::string> result_string;
    std::vector<std::string> not_needed_strings = {"TITLE: ", " TYPE: ", " LAST PERFORMED DATE: ", " TIMES PERFORMED: ", " TYPE: ", " VISION: "};
    for(std::string attribute:not_needed_strings){
        auto position = entire_line.find(attribute);
        if(position != std::string::npos)
            entire_line.erase(position, attribute.length());
    }
    return entire_line;
}

std::istream& operator>>(std::istream& is, Task &task_to_add)
{
    std::string line;
    std::getline(is, line);
    std::string result_line = task_to_add.remove_not_needed_strings(line);
    std::vector<std::string> result = tokenize(result_line, ',');
    if(result.size() != 5)
        return is;
    task_to_add.set_title(result[0]);
    task_to_add.set_type(result[1]);
    tm last_performed_date;
    strptime(result[2].c_str(), "%m-%d-%Y", &last_performed_date);                
    task_to_add.set_last_performed_month(last_performed_date.tm_mon+1);
    task_to_add.set_last_performed_year(last_performed_date.tm_year+1900);
    task_to_add.set_last_performed_day(last_performed_date.tm_mday);
    task_to_add.set_times_performed(stoi(result[3]));
    task_to_add.set_vision(result[4]);
    return is;
}


