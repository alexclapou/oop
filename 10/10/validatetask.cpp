#include "validatetask.h"

ValidateTask::ValidateTask(std::string _error_message)
{
    error_message = _error_message;
}

ValidateTask::ValidateTask()
{
    error_message = "";
}

const char* ValidateTask::what()const noexcept
{
    return error_message.c_str();
}

void ValidateTask::validate_task(Task task_to_validate)
{
    std::string all_error_messages;

    if(task_to_validate.get_type().size() < 3)
        all_error_messages += "type has must have at least 3 characters\n";
    if(task_to_validate.get_last_performed_day() < 1 || task_to_validate.get_last_performed_day() > 31)
        all_error_messages += "day have to be between [1,31]\n";
    if(task_to_validate.get_last_performed_month() < 1 || task_to_validate.get_last_performed_month() > 12)
        all_error_messages += "month have to be between [1,12]\n";
    if(task_to_validate.get_last_performed_day() < 0)
        all_error_messages += "year can't be negative\n";
    if(task_to_validate.get_times_performed() < 0)
        all_error_messages += "times performed can't be negative\n";
    if(task_to_validate.get_vision().size() < 3)
        all_error_messages += "vision must have at least 3 characters\n";
    if(!all_error_messages.empty())
        throw ValidateTask(all_error_messages);
}
