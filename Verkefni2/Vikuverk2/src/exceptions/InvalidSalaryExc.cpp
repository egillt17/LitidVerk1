#include "InvalidSalaryExc.h"

InvalidSalaryExc::InvalidSalaryExc(string message)
{
    _message = message;
}

string InvalidSalaryExc::getMessage() {
    return _message;
}
