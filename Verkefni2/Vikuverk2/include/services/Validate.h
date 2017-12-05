#ifndef VALIDATE_H
#define VALIDATE_H
#include "Service.h"
#include <sstream>


class Validate
{
    public:
        Validate();
        bool validateSalary(string salary);
        bool validateSSN(string ssn);
        bool validateMonth(string month);
        bool validateName(string name);
        bool validateYear(string year);
        bool validateAll(string name, string ssn, string salary, string month, string year);

    protected:

    private:
};

#endif // VALIDATE_H
