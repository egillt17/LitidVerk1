#include "InvalidSsnExc.h"

InvalidSsnExc::InvalidSsnExc(string message)
{
    _message = message;
}

string InvalidSsnExc::getMessage() {
    return _message;
}
