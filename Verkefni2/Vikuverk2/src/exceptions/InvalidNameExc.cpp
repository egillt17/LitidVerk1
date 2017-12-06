#include "InvalidNameExc.h"

InvalidNameExc::InvalidNameExc(string message)
{
    _message = message;
}

string InvalidNameExc::getMessage() {
    return _message;
}
