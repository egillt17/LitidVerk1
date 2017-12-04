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
        void display_toppings(char input, int price, string& topping);
        Toppings add_toppings();
        friend ostream& operator << (ostream& out, Toppings top);
        int get_amount(Toppings amount);

    private:
        vector<string> _name_of_topping;
        int _amount;
};

#endif // TOPPINGS_H
