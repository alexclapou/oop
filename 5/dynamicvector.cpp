#include "dynamicvector.h"
#include "task.h"

DynamicVector::DynamicVector()
{
    number_of_tasks = 0;
    capacity = 5;
    tasks = new Task[5];
}

int DynamicVector::add(Task new_task)
{
    if(is_full()){
        resize();
    }
    tasks[number_of_tasks] = new_task;
    tasks[number_of_tasks].set_last_performed_day(new_task.get_last_performed_day());
    tasks[number_of_tasks].set_last_performed_month(new_task.get_last_performed_month());
    tasks[number_of_tasks].set_last_performed_year(new_task.get_last_performed_year());
    //std::cout<<tasks[number_of_tasks].get_title()<<" "<<tasks[number_of_tasks].get_type()<<" "<<tasks[number_of_tasks].get_last_performed_month()<<"-"<<tasks[number_of_tasks].get_last_performed_day()<<"-"<<tasks[number_of_tasks].get_last_performed_year()<<" "<<tasks[number_of_tasks].get_times_performed()<<" "<<tasks[number_of_tasks].get_vision()<<"\n";
    number_of_tasks++;
    return 1;
}

DynamicVector::DynamicVector(const DynamicVector &copy_dynamic_vector)
{
    number_of_tasks = copy_dynamic_vector.number_of_tasks;
    capacity = copy_dynamic_vector.capacity;
    tasks = new Task[capacity];
    for(int i = 0; i < number_of_tasks; i++)
        tasks[i] = copy_dynamic_vector.tasks[i];
}

DynamicVector& DynamicVector::operator=(const DynamicVector& copy_dynamic_vector)
{
	if (this == &copy_dynamic_vector)
		return *this;
	this->number_of_tasks = copy_dynamic_vector.number_of_tasks;
	this->capacity = copy_dynamic_vector.capacity;

	delete[] this->tasks;
	this->tasks = new Task[capacity];
	for (int i = 0; i < number_of_tasks; i++)
		this->tasks[i] = copy_dynamic_vector.tasks[i];

	return *this;
}

int DynamicVector::remove(std::string task_title)
{
    int task_index;

    task_index = search(task_title);
    if(task_index != -1){
        for(; task_index < number_of_tasks-1; task_index++){
            tasks[task_index] = tasks[task_index+1];
        }
        number_of_tasks--;
    }
    return 1;
}

int DynamicVector::update(std::string title, std::string new_type, tm new_last_performed,  int new_times_performed, std::string new_vision)
{
    int task_index;

    task_index = search(title);
    tasks[task_index].set_type(new_type);
    tasks[task_index].set_last_performed_day(new_last_performed.tm_mday);
    tasks[task_index].set_last_performed_month(new_last_performed.tm_mon);
    tasks[task_index].set_last_performed_year(new_last_performed.tm_year);
    tasks[task_index].set_times_performed(new_times_performed);
    tasks[task_index].set_vision(new_vision);
    return 1;
}

int DynamicVector::search(std::string searching_title)
{
    for(int i = 0; i < number_of_tasks; i++)
        if(searching_title == tasks[i].get_title())
            return i;
    return -1;
}

bool DynamicVector::is_full()
{
    if(number_of_tasks == capacity)
        return true;
    return false;
}

int DynamicVector::length()
{
    return number_of_tasks;
}

void DynamicVector::resize()
{
    capacity += 5;
    Task *new_tasks = new Task[capacity];
    for(int i = 0; i < number_of_tasks; i++)
        new_tasks[i] = tasks[i];
    delete[] tasks;
    tasks = new_tasks;
}

Task DynamicVector::operator[](int task_index)
{
    return tasks[task_index];
}

DynamicVector::~DynamicVector()
{
    delete[] tasks;
}

Task DynamicVector::get_task(int position)
{
    return tasks[position];
}
