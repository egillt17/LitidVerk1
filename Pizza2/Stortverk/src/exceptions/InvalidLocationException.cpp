#include "InvalidLocationException.h"

InvalidLocationException::InvalidLocationException(string message)
{
    _message = message;
}

string InvalidLocationException::getMessage() {
    return _message;
}
