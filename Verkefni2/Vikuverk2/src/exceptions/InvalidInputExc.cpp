#include "InvalidInputExc.h"

InvalidInputExc::InvalidInputExc(string message) 
{
    this->message = message;
}

string InvalidInputExc::getMessage() {
    return message;
}
