#ifndef PIZZA_H
#define PIZZA_H
#include "Toppings.h"
#include <iostream>

using namespace std;

class Pizza
{
    public:
        Pizza();
        ~Pizza();
        Pizza make_pizza();
        void display_sizes(string& add,int& amount);
        void display_sauce(string& add);
        void display_crust(string& add);
        friend ostream& operator << (ostream& out, Pizza& pizza);

    private:
        Toppings _topping_on_pizza;
        string _size_of_pizza;
        string _sauce;
        string _crust;
        int _amount;

};

#endif // PIZZA_H
