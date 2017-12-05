#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Employee.h"
#include "Service.h"
#include <fstream>
#include <vector>

using namespace std;

class Repository
{
    public:
        Repository();
        ~Repository();
        void writeInFile(Employee& employee);
        void infoInFile(vector <Employee>& employee);

    private:
};

#endif // REPOSITORY_H
