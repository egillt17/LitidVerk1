#ifndef INVALIDNUMEXCEPTIONS_H
#define INVALIDNUMEXCEPTIONS_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

class InvalidNumExceptions
{
    public:
        InvalidNumExceptions(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDNUMEXCEPTIONS_H
