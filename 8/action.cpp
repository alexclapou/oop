#include "action.h"

void ActionAdd::undo(){
    repository.remove_file_data(added_task.get_title());
}

void ActionAdd::redo(){
    repository.add_file_data(added_task);
}

void ActionRemove::undo(){
    repository.add_file_data(removed_task);
}

void ActionRemove::redo(){
    repository.remove_file_data(removed_task.get_title());
}

void ActionUpdate::undo(){
    repository.update_file_data(old_updated_task.get_title(), old_updated_task.get_type(), old_updated_task.get_last_performed_date(), old_updated_task.get_times_performed(), old_updated_task.get_vision());
}

void ActionUpdate::redo(){
    repository.update_file_data(new_updated_task.get_title(), new_updated_task.get_type(), new_updated_task.get_last_performed_date(), new_updated_task.get_times_performed(), new_updated_task.get_vision());
}
