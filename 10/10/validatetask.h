#include "task.h"
class ValidateTask {
    private:
        std::string error_message;
    public:
        ValidateTask();
        ValidateTask(std::string _error_message);
        const char* what()const noexcept;
        void validate_task(Task task_to_validate);
};
