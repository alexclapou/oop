#include "action.h"

void ActionAdd::undo(){
    repository->remove(added_task.get_title());
}

void ActionAdd::redo(){
    repository->add(added_task);
}

void ActionRemove::undo(){
    repository->add(removed_task);
}

void ActionRemove::redo(){
    repository->remove(removed_task.get_title());
}

void ActionUpdate::undo(){
    repository->update(old_updated_task.get_title(), old_updated_task.get_type(), old_updated_task.get_last_performed_date(), old_updated_task.get_times_performed(), old_updated_task.get_vision());
}

void ActionUpdate::redo(){
    repository->update(new_updated_task.get_title(), new_updated_task.get_type(), new_updated_task.get_last_performed_date(), new_updated_task.get_times_performed(), new_updated_task.get_vision());
}
