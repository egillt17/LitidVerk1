#ifndef TOPSERVICE_H
#define TOPSERVICE_H

#include "Toppings.h"
#include "ToppingRepo.h"


class TopService
{
    public:
        vector <Toppings> getToppingList(int pick);
        void addTopping(string name, string price, int pick);
        bool removeTopping(string name, int pick);
        Toppings make_topping(string st, string price);


    private:
        bool toppingCheck(Toppings topping, int pick);
};

#endif // TOPSERVICE_H
