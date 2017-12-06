#ifndef INVALIDINPUTEXC_H
#define INVALIDINPUTEXC_H

#include "Employee.h"

class InvalidInputExc
{
    public:
        InvalidInputExc(string message);
        string getMessage();

    private:
        string message;
};

#endif // INVALIDINPUTEXC_H
