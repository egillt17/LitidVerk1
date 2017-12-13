#ifndef INVALIDNAMEEXCEPTION_H
#define INVALIDNAMEEXCEPTION_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

/// Gets made whenever there is error thrown from validation class, validating name
class InvalidNameException
{
    public:
         /// the constructor take a string of message
        InvalidNameException(string message);
         /// function that returns the message thrown from validation
        string getMessage();

    private:
         /// holds the message to return
        string _message;
};

#endif // INVALIDNAMEEXCEPTION_H
