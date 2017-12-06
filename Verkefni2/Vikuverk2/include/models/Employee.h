#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

class Employee
{
    public:
        Employee();
        Employee(string name, string ssn, int salary, int month, int year);
        ~Employee();
        string get_name();
        string get_ssn();
        int get_salary();
        int get_month();
        int get_year();
        void set_salary(int salary);
        void set_month(int month);
        friend ostream& operator << (ostream& out, Employee& employee);
        friend istream& operator >> (istream& in, Employee& employee);
        friend ofstream& operator << (ofstream& out, Employee& employee);

    private:
        string _name;
        string _ssn;
        int _salary;
        int _month;
        int _year;
};

#endif // EMPLOYEE_H
