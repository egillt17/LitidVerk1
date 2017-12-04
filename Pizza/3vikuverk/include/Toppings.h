#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdlib.h>

using namespace std;

class Toppings
{
    public:
        Toppings();
        ~Toppings();
        void display_toppings(char input, int &price, string& topping);
        Toppings add_toppings(int pizza_amount, int& topping_amount, Toppings pizza_top);
        friend ostream& operator << (ostream& out, Toppings& top);

    private:
        vector<string> _name_of_topping;
};

#endif // TOPPINGS_H
