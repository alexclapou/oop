#pragma once
#include "task.h"

template <typename TElem>
class DynamicVector{
    private:
       TElem *tasks;
       int capacity;
       int number_of_tasks;
    
    public:
       DynamicVector();
       DynamicVector(const DynamicVector &copy_dynamic_vector);
       int add(TElem new_TElem);
       int remove(int task_index);
       int update(TElem updated_TElem, int index);
       bool is_full();
       int length();
       void resize();
       TElem get_task(int position);
       TElem operator[](int task_index);
       DynamicVector& operator=(const DynamicVector &copy_dynamic_vector);
       ~DynamicVector();
};
