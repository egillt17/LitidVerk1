#ifndef INVALIDNAMEEXC_H
#define INVALIDNAMEEXC_H

#include "Employee.h"

class InvalidNameExc
{
    public:
        InvalidNameExc(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDNAMEEXC_H
