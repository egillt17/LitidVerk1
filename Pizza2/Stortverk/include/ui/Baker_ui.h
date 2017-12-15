#ifndef BAKER_H
#define BAKER_H
#include "Main_ui.h"


class Baker_ui
{
    public:
        void bakerMainUI();
        ///Main UI for the baker
        void locationMenu(string location);
        ///Menu that pops up after the location is selected, and that location is the ran throught the function
        void changeStatus(vector <Pizza>& pizzas);
        ///Function that is used to change the status of pizzas, takes in a vector of pizzas

    private:
};

#endif // BAKER_H
