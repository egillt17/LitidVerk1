#include <iostream>

#include "Main_ui.h"
<<<<<<< HEAD
#include "Employee.h"
=======
#include "Service.h"
#include "Validate.h"
>>>>>>> 3d9935fa0a7242c57b8563bf9476021419109d71

using namespace std;

int main()
{
<<<<<<< HEAD
    Employee lala;
    cin >> lala;
    cout << endl << lala << endl;
=======
    string name = "Egill Aron";
    string ssn = "4273723684";
    double salary = 599.08;
    int month = 06;
    int year = 2017;

    Validate bla;
    cout << bla.validateAll(name, ssn, salary, month, year);
>>>>>>> 3d9935fa0a7242c57b8563bf9476021419109d71

    return 0;
}
