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

    private:
};

#endif // SERVICE_H
