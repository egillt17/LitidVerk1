#include "Employee.h"

Employee::Employee() {
    _name = "";
    _ssn = "";
    _salary = 0;
    _month = 0;
    _year = 0;
}

Employee::Employee(string name, string ssn, int salary, int month, int year) {
    _name = name;
    _ssn = ssn;
    _salary = salary;
    _month = month;
    _year = year;
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

int Employee::get_salary() {
    return _salary;
}

int Employee::get_month() {
    return _month;
}

int Employee::get_year() {
    return _year;
}

void Employee::set_salary(int salary) {
    _salary = salary;
}
void Employee::set_month(int month) {
    _month =month;
}

ostream& operator << (ostream& out, Employee& employee) {
    out << "Name: " << employee._name << endl;
    out << "Social Security Number: " << employee._ssn << endl;
    out << std::fixed << setprecision(2) << "Salary: " << employee._salary << ".kr" << endl;
    if(employee._month < 10 && employee._month > 0) {
        out << "Date: " << "0" << employee._month << "/";
    }
    else if(employee._month > 9) {
        out << "Date: " << employee._month << "/";
    }
    if(employee._month == 0) {
        out << "Date: " << employee._year << endl;
    }
    else {
        out << employee._year << endl;
    }

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

ofstream& operator << (ofstream& out, Employee& employee) {
    out << ":" << employee._name << ":" << employee._ssn << ":" << employee._salary << ":" << employee._month << ":" << employee._year << endl;
    return out;
}
