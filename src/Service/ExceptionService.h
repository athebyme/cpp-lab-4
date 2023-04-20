#ifndef CPP_SQUARE_LAB3_EXCEPTIONSERVICE_H
#define CPP_SQUARE_LAB3_EXCEPTIONSERVICE_H


#include <exception>
namespace CustomExceptions {
    class NotEnoughArgumentsException : public std::exception {
    public:
        const char* what() const noexcept override {
            return "Not enough arguments";
        }
    };
}

#endif
