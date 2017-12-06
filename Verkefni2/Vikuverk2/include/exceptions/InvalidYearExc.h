#ifndef INVALIDYEAREXC_H
#define INVALIDYEAREXC_H

#include "Employee.h"

class InvalidYearExc
{
    public:
        InvalidYearExc(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDYEAREXC_H
