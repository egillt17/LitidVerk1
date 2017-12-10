#ifndef INVALIDNAMEEXCEPTION_H
#define INVALIDNAMEEXCEPTION_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

class InvalidNameException
{
    public:
        InvalidNameException(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDNAMEEXCEPTION_H
