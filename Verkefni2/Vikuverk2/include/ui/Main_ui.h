#ifndef MAIN_UI_H
#define MAIN_UI_H

#include "Service.h"
#include "Validate.h"
#include <string>
#include <stdlib.h>
#include <iostream>

using namespace std;

class Main_ui
{
    public:
        Main_ui();
        // main menu
        void main_menu();
        // goto menu for a salary record from a ssn
        void getRcrdMenu();
        // goto menu to add a new employee to the registry
        void addEmplMenu();
        //goto menu for the highest paid employee by year
        void getHiPayMenu();
        //goto menu for a yearly salary for a specific ssn
        void getYrPayMenu();


    private:
};

#endif // MAIN_UI_H
