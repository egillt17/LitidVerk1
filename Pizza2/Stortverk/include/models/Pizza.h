#ifndef PIZZA_H
#define PIZZA_H

#include "Toppings.h"

class Pizza
{
    public:
        Pizza();
        ~Pizza();
        void set_person(string person);
        void set_price(int price);
        void set_size(string size_of);
        void set_sauce(string sauce);
        void set_cheese(string cheese);
        void set_crust(string crust);
        void set_status(char status);

    private:
        string _person;
        int _price;
        vector <Toppings> _topping;
        string _size;
        string _sauce;
        string _cheese;
        string _crust;
        char _status;

};

#endif // PIZZA_H
