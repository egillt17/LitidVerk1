#ifndef VALIDATE_H
#define VALIDATE_H
#include "Service.h"


class Validate
{
    public:
        Validate();
        bool validateSalary(double salary);
        bool validateSSN(string ssn);
        bool validateMonth(int month);
        bool validateName(string name);
        bool validateYear(int year);
        bool validateAll(string name, string ssn, double salary, int month, int year);

    protected:

    private:
};

#endif // VALIDATE_H
