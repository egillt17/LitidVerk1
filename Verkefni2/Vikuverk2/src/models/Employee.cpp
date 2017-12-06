#include "Employee.h"

Employee::Employee() {
    _name = "";
    _ssn = "";
    _salary = "";
    _month = 0;
    _year = 0;  ///Setting all member variables to either 0 or the empty string
}

Employee::Employee(string name, string ssn, string salary, int month, int year) {
    _name = name;
    _ssn = ssn;
    _salary = salary;
    _month = month;
    _year = year;   ///Setting the member variables to the parameters sent into the constructor
}

string Employee::get_name() {
    return _name;   ///Get function that returns the name of the Employee
}

string Employee::get_ssn() {
    return _ssn;    ///Get function that returns the social security number of the Employee
}

string Employee::get_salary() {
    return _salary; ///Get function that returns the monthly salary of the Employee
}

int Employee::get_month() {
    return _month;  ///Get function that returns the month of the salary record
}

int Employee::get_year() {
    return _year;   ///Get function that returns the year of the salary record
}

void Employee::set_salary(int salary) {
    stringstream sin;  ///Converts the int into a string so it can be added to the salary variable
    sin << salary;
    sin >> _salary;   ///Set function that sets only the salary of the salary record
}
void Employee::set_month(int month) {
    _month =month;  ///Set function that sets only the month of the salary record
}

ostream& operator << (ostream& out, Employee& employee) {
    out << "Name: " << employee._name << endl;
    out << "Social Security Number: " << employee._ssn << endl;
    out << "Salary: " << employee._salary << ".kr" << endl;

    if(employee._month < 10 && employee._month > 0) {       ///If the month is between the number 0 and 10 then adds a zero before the number of the month for readability

        out << "Date: " << "0" << employee._month << "/";
    }
    else if(employee._month > 9) {                          ///Else just print out the regular number
        out << "Date: " << employee._month << "/";
    }

    if(employee._month == 0) {                              ///If the month of the record is not set then the function only prints out the year
        out << "Date: " << employee._year << endl;
    }
    else {
        out << employee._year << endl;
    }

    return out;             ///ostream overload function
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

    return in;              ///istream overload function
}

ofstream& operator << (ofstream& out, Employee& employee) {
    out << ":" << employee._name << ":" << employee._ssn << ":" << employee._salary << ":" << employee._month << ":" << employee._year << endl;
    return out;
}                           ///ofstream overload fuction that writes to a .txt file
