#ifndef INVALIDNUMEXCEPTIONS_H
#define INVALIDNUMEXCEPTIONS_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

/// Gets made whenever there is error thrown from validation class, validating numbers
class InvalidNumExceptions
{
    public:
         /// the constructor take a string of message
        InvalidNumExceptions(string message);
         /// function that returns the message thrown from validation
        string getMessage();

    private:
         /// holds the message to return
        string _message;
};

#endif // INVALIDNUMEXCEPTIONS_H
