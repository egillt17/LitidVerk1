#ifndef INVALIDSALARYEXC_H
#define INVALIDSALARYEXC_H

#include "Employee.h"

class InvalidSalaryExc
{
    public:
        InvalidSalaryExc(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDSALARYEXC_H
