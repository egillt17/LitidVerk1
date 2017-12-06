#ifndef INVALIDSSNEXC_H
#define INVALIDSSNEXC_H

#include "Employee.h"

class InvalidSsnExc
{
    public:
        InvalidSsnExc(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDSSNEXC_H
