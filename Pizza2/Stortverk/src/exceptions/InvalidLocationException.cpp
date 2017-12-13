#include "InvalidLocationException.h"

/// constructor, takes the message and puts in private variable
InvalidLocationException::InvalidLocationException(string message)
{
    _message = message;
}

/// getMessage returns the message stored in the private message variable
string InvalidLocationException::getMessage() {
    return _message;
}
