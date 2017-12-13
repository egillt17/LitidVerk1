#ifndef INVALIDLOCATIONEXCEPTION_H
#define INVALIDLOCATIONEXCEPTION_H

#include "Validate.h"
#include <string>
#include <iostream>
using namespace std;

/// Gets made whenever there is error thrown from validation class, validating location
class InvalidLocationException
{
    public:
        /// the constructor take a string of message
        InvalidLocationException(string message);
        /// function that returns the message thrown from validation
        string getMessage();

    private:
        /// holds the message to return
        string _message;
};

#endif // INVALIDLOCATIONEXCEPTION_H
