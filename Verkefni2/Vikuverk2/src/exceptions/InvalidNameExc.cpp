#include "InvalidNameExc.h"

InvalidNameExc::InvalidNameExc(string message)
{
    this->message = message;
}

string InvalidNameExc::getMessage() {
    return message;
}
