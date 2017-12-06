#include "InvalidYearExc.h"

InvalidYearExc::InvalidYearExc(string message)
{
    _message = message;
}

string InvalidYearExc::getMessage() {
    return _message;
}
