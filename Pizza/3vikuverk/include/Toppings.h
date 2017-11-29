#ifndef TOPPINGS_H
#define TOPPINGS_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class Toppings
{
    public:
        Toppings();
        ~Toppings();
        void display_toppings();
        Toppings add_toppings();

    private:
        vector<string> name_of_topping;
        int _price;
};

#endif // TOPPINGS_H
