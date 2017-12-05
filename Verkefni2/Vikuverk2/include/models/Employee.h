#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Employee
{
    public:
        Employee();
        ~Employee();
        string get_name();
        string get_ssn();
        double get_salary();
        int get_month();
        int get_year();
        friend ostream& operator << (ostream& out, Employee& employee);
        friend istream& operator >> (istream& in, Employee& employee);

    private:
        string _name;
        string _ssn;
        double _salary;
        int _month;
        int _year;
};

#endif // EMPLOYEE_H
