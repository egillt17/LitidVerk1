#include "InvalidSalaryExc.h"

InvalidSalaryExc::InvalidSalaryExc(string message)
{
    this->message = message;
}

string InvalidSalaryExc::getMessage() {
    return message;
}
