#ifndef VALIDATE_H
#define VALIDATE_H
#include <string>
#include <iostream>
#include "InvalidNameException.h"
#include "InvalidNumExceptions.h"
#include "InvalidLocationException.h"

#include "Toppings.h"

using namespace std;

class Validate
{
    public:
        /// bool function to validate the name string from Manager UI
        bool validateName(string name);
        /// bool function to validate the number string from Manager UI
        bool validateNum(string number);
        /// bool function to validate the location string from Manager UI
        bool validateLocation(string location);
        
    private:
};

#endif // VALIDATE_H
