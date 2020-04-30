#include "repositoryexception.h"

RepositoryException::RepositoryException(std::string _error_message)
{
    error_message = _error_message;
}

const char* RepositoryException::what()const noexcept
{
    return error_message.c_str();
}
