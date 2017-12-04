#ifndef REPOSITORY_H
#define REPOSITORY_H

#include "Employee.h"
#include <fstream>

using namespace std;

class Repository
{
    public:
        Repository();
        ~Repository();
        void write_january(Employee employee);

    private:
};

#endif // REPOSITORY_H
