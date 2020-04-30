#include <string>
class RepositoryException { 
    private:
        std::string error_message;
    public:
        RepositoryException(std::string _error_message);
        const char* what()const noexcept;
};
