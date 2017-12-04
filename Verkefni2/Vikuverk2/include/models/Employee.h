#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>

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

    private:
        string _name;
        string _ssn;
        double _salary;
        int _month;
        int _year;
};

#endif // EMPLOYEE_H
