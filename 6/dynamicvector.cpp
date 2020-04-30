#include "dynamicvector.h"
#include "task.h"

template <typename TElem>
DynamicVector<TElem>::DynamicVector()
{
    number_of_tasks = 0;
    capacity = 5;
    tasks = new TElem[5];
}

template <typename TElem>
DynamicVector<TElem>::DynamicVector(const DynamicVector &copy_dynamic_vector)
{
    number_of_tasks = copy_dynamic_vector.number_of_tasks;
    capacity = copy_dynamic_vector.capacity;
    tasks = new TElem[capacity];
    for(int i = 0; i < number_of_tasks; i++)
        tasks[i] = copy_dynamic_vector.tasks[i];
}

template <typename TElem>
DynamicVector<TElem>& DynamicVector<TElem>::operator=(const DynamicVector& copy_dynamic_vector)
{
	if (this == &copy_dynamic_vector)
		return *this;
	this->number_of_tasks = copy_dynamic_vector.number_of_tasks;
	this->capacity = copy_dynamic_vector.capacity;

	delete[] this->tasks;
	this->tasks = new TElem[capacity];
	for (int i = 0; i < number_of_tasks; i++)
		this->tasks[i] = copy_dynamic_vector.tasks[i];

	return *this;
}

template <typename TElem>
int DynamicVector<TElem>::add(TElem new_TElem)
{
    if(is_full()){
        resize();
    }
    tasks[number_of_tasks] = new_TElem;
    //std::cout<<tasks[number_of_tasks].get_title()<<" "<<tasks[number_of_tasks].get_type()<<" "<<tasks[number_of_tasks].get_last_performed_month()<<"-"<<tasks[number_of_tasks].get_last_performed_day()<<"-"<<tasks[number_of_tasks].get_last_performed_year()<<" "<<tasks[number_of_tasks].get_times_performed()<<" "<<tasks[number_of_tasks].get_vision()<<"\n";
    number_of_tasks++;
    return 1;
}

template <typename TElem>
int DynamicVector<TElem>::remove(int task_index)
{
    if(task_index != -1){
        for(; task_index < number_of_tasks-1; task_index++){
            tasks[task_index] = tasks[task_index+1];
        }
        number_of_tasks--;
    }
    return 1;
}

template <typename TElem>
int DynamicVector<TElem>::update(TElem updated_TElem, int task_index)
{
    tasks[task_index] = updated_TElem;
    /*
    tasks[task_index].set_type(new_type);
    tasks[task_index].set_last_performed_day(new_last_performed.tm_mday);
    tasks[task_index].set_last_performed_month(new_last_performed.tm_mon);
    tasks[task_index].set_last_performed_year(new_last_performed.tm_year);
    tasks[task_index].set_times_performed(new_times_performed);
    tasks[task_index].set_vision(new_vision);
    */
    return 1;
}

/*
template <typename TElem>
int DynamicVector<TElem>::search(std::string searching_title)
{
    for(int i = 0; i < number_of_tasks; i++)
        if(searching_title == tasks[i].get_title())
            return i;
    return -1;
}
*/

template <typename TElem>
bool DynamicVector<TElem>::is_full()
{
    if(number_of_tasks == capacity)
        return true;
    return false;
}

template <typename TElem>
int DynamicVector<TElem>::length()
{
    return number_of_tasks;
}

template <typename TElem>
void DynamicVector<TElem>::resize()
{
    capacity += 5;
    TElem *new_tasks = new TElem[capacity];
    for(int i = 0; i < number_of_tasks; i++)
        new_tasks[i] = tasks[i];
    delete[] tasks;
    tasks = new_tasks;
}

template <typename TElem>
TElem DynamicVector<TElem>::operator[](int task_index)
{
    return tasks[task_index];
}

template <typename TElem>
DynamicVector<TElem>::~DynamicVector()
{
    delete[] tasks;
}

template <typename TElem>
TElem DynamicVector<TElem>::get_task(int position)
{
    return tasks[position];
}
