#ifndef TOPSERVICE_H
#define TOPSERVICE_H

#include "Toppings.h"
#include "ToppingRepo.h"


class TopService
{
    public:
        vector <Toppings> getToppingList(int pick);
        ///A function that returns the list of the extra that was picked
        void addTopping(string name, string price, int pick);
        ///A function that takes in a name, price and type of extra and adds that to the appropriate .txt file
        bool removeTopping(string name, int pick);
        ///A function that takes in a name and type of an extra, and removes that extra from the appropriate .txt file
        Toppings make_topping(string st, string price);
        ///A function that is used when making a new extra, a name and a price is taken in

    private:
        bool toppingCheck(Toppings topping, int pick);
        /// checks if topping has already been added to the list
};

#endif // TOPSERVICE_H
