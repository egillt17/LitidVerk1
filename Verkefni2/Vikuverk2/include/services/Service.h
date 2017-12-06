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
        Service();
        ~Service();
        void writeEmployeeInFile(string name, string ssn, string salary, string month, string year);
        Employee makeEmployee(string name, string ssn, string salary, string month, string year);
        Employee findEmployeeMonth(string ssn, string month, string year);
        Employee findEmployeeYearlySalary(string ssn, string year);
        Employee findHighestEmployeeYearly(string year);

    private:
        bool employeeCheck(Employee employeeTest);
};

#endif // SERVICE_H
