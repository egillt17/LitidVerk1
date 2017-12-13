#include "InvalidNameException.h"

/// constructor, takes the message and puts in private variablea
InvalidNameException::InvalidNameException(string message)
{
    _message = message;
}

/// getMessage returns the message stored in the private message variable
string InvalidNameException::getMessage() {
    return _message;
}
