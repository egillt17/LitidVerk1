#include "InvalidNumExceptions.h"

/// constructor, takes the message and puts in private variable
InvalidNumExceptions::InvalidNumExceptions(string message)
{
    _message = message;
}

/// getMessage returns the message stored in the private message variable
string InvalidNumExceptions::getMessage(){
    return _message;
}
