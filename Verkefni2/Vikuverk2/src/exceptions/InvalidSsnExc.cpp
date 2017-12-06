#include "InvalidSsnExc.h"

InvalidSsnExc::InvalidSsnExc(string message)
{
    this->message = message;
}

string InvalidSsnExc::getMessage() {
    return message;
}
