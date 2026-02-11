#ifndef LINKO_EXCEPTION_HPP
#define LINKO_EXCEPTION_HPP

#include <stdexcept>

class LinkoException : public std::runtime_error{
    public:
        explicit LinkoException(const std::string& message) : std::runtime_error(message){}
};

#endif