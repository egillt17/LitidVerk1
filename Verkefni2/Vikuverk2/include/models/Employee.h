#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <fstream>

using namespace std;

class Employee
{
    public:
        Employee();
        ///Default constructor
        Employee(string name, string ssn, string salary, int month, int year);
        ///Constructor that takes in the the parameters above
        string get_name();
        ///get function that gives you the name of an employee
        string get_ssn();
        ///get function that gives you the social security number of an employee
        string get_salary();
        ///get function that gives you the salary of an employee
        int get_month();
        ///get function that gives you the month of the salary record
        int get_year();
        ///get function that gives you the year of the salary record
        void set_salary(double salary);
        ///set function to set only the salary of a salary record
        void set_month(int month);
        ///set function to set only the month of a salary record
        friend ostream& operator << (ostream& out, Employee& employee);
        ///ostream cout overload function
        friend ofstream& operator << (ofstream& out, Employee& employee);
        ///ofstream overload function to write directly to a .txt file

    private:
        string _name;
        string _ssn;
        string _salary;
        int _month;
        int _year;
        ///Private member variables
};

#endif // EMPLOYEE_H
