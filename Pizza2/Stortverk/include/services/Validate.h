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
        bool validateName(string name);
        bool validateNum(string number);
        bool validateLocation(string location);
        
    private:
};

#endif // VALIDATE_H
