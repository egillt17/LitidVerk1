#include "InvalidInputExc.h"

InvalidInputExc::InvalidInputExc(string message)
{
    _message = message;
}

string InvalidInputExc::getMessage() {
    return _message;
}
