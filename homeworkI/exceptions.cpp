#include "exceptions.h"

AircraftException::AircraftException(std::string _error_message)
{
    error_message = _error_message;
}

const char* AircraftException::what()const noexcept
{
    return error_message.c_str();
}

