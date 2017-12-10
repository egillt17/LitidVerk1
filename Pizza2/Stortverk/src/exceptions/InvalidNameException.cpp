#include "InvalidNameException.h"

InvalidNameException::InvalidNameException(string message)
{
    _message = message;
}

string InvalidNameException::getMessage() {
    return _message;
}
