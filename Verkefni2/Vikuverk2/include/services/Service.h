#ifndef SERVICE_H
#define SERVICE_H

#include <iostream>
#include <string>
#include <stdio.h>
#include <sstream>
#include "Employee.h"
#include "Repository.h"

using namespace std;



class Service
{
    public:
        void writeEmployeeInFile(string name, string ssn, string salary, string month, string year);
        /// this void function is the connection between the ui and the repository class for writing in new employees
        Employee makeEmployee(string name, string ssn, string salary, string month, string year);
        /// this function takes in all the needed variables and turns them into the right variables so the can be made into an employee
        Employee findEmployeeMonth(string ssn, string month, string year);
        /// this function finds an employees salary in a particular month
        Employee findEmployeeYearlySalary(string ssn, string year);
        /// this function finds an employees yearly salary
        Employee findHighestEmployeeYearly(string year);
        /// this function finds what employee had the highest salary in a particular year

    private:
        bool employeeCheck(Employee employeeTest);
        /// this function checks if the employee that is about to be added has already been added to that month and year
};

#endif // SERVICE_H
