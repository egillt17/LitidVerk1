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
        void writeInFile(Employee& employee);
        ///Function to write directly to a .txt file
        void reWriteInFile(vector <Employee> employee);
        ///Function to rewrite the whole .txt file, will explain better in the .cpp file
        void getInfoInFile(vector <Employee>& employee);


    private:
};

#endif // REPOSITORY_H
