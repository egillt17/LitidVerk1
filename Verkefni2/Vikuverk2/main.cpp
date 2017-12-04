#include <iostream>

#include "Main_ui.h"
#include "Service.h"
#include "Validate.h"

using namespace std;

int main()
{
    string name = "Egill Aron";
    string ssn = "4273723684";
    double salary = 599.08;
    int month = 06;
    int year = 2017;

    Validate bla;
    cout << bla.validateAll(name, ssn, salary, month, year);

    return 0;
}
