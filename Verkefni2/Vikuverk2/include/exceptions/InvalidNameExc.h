#ifndef INVALIDNAMEEXC_H
#define INVALIDNAMEEXC_H

#include "Employee.h"

class InvalidNameExc
{
    public:
        InvalidNameExc(string message);             ///The constructor takes in a string and the string and sets the private variable of the class to that string
        string getMessage();
                                                    ///The getMessage function returns the message that is stored in the private variable _message


    private:
        string _message;
};

#endif // INVALIDNAMEEXC_H
