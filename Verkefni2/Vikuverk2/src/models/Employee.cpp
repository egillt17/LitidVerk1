#include "Employee.h"

Employee::Employee() {
    _name = "";
    _ssn = "";
    _salary = 0;
    _month = 0;
    _year = 0;
}

Employee::~Employee() {
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

ostream& operator << (ostream& out, Employee& employee) {
    out << employee._name << ", " << employee._ssn << ", " << employee._salary << ", ";
    if(employee._month < 10) {
        out << "0" << employee._month << ", ";
    }
    else {
        out << employee._month << ", ";
    }
    out << employee._year;

    return out;
}

istream& operator >> (istream& in, Employee& employee) {
    cout << "Name: ";
    in >> employee._name;
    cout << "Social Security Number: ";
    in >> employee._ssn;
    cout << "Salary: ";
    in >> employee._salary;
    cout << "Month: ";
    in >> employee._month;
    cout << "Year: ";
    in >> employee._year;

    return in;
}
