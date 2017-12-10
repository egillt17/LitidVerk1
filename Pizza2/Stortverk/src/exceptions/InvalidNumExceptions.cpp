#include "InvalidNumExceptions.h"

InvalidNumExceptions::InvalidNumExceptions(string message)
{
    _message = message;
}

string InvalidNumExceptions::getMessage(){
    return _message;
}
