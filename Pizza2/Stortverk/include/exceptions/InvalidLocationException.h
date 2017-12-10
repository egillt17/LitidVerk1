#ifndef INVALIDLOCATIONEXCEPTION_H
#define INVALIDLOCATIONEXCEPTION_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

class InvalidLocationException
{
    public:
        InvalidLocationException(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDLOCATIONEXCEPTION_H
