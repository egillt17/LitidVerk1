#include "InvalidYearExc.h"

InvalidYearExc::InvalidYearExc(string message)
{
    this->message = message;
}

string InvalidYearExc::getMessage() {
    return message;
}
