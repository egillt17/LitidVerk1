#ifndef DISPLAY_H
#define DISPLAY_H

#include <iostream>
using namespace std;

class Display
{
    public:
        Display();
        void displayMainUI();
        void managerUI();
        void bakerUI();
        void cashierUI();

        virtual ~Display();

    protected:

    private:

};

#endif // DISPLAY_H
