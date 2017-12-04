#include "Employee.h"

Employee::Employee()
{
    _name = "";
    _ssn = "";
    _salary = 0;
    _month = 0;
    _year = 0;
}

Employee::~Employee()
{
    //dtor
}

string Employee::get_name() {
    return _name;
}

string Employee::get_ssn() {
    return _ssn;
}

double Employee::get_salary() {
    return _salary;
}

int Employee::get_month() {
    return _month;
}

int Employee::get_year() {
    return _year;
}
