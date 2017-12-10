#ifndef PIZZA_H
#define PIZZA_H

#include "Toppings.h"

class Pizza
{
    public:
        Pizza();
        ~Pizza();
        void setPerson(string person);
        void setPrice(int price);
        void setSize(string size_of);
        void setSauce(string sauce);
        void setCheese(string cheese);
        void setCrust(string crust);
        void setStatus(char status);
        string getPerson();
        int getPrice();
        vector <Toppings> getToppings();
        string getSize();
        string getSauce();
        string getCheese();
        string getCrust();
        char getStatus();
        friend ostream& operator << (ostream& out, const Pizza& pizza);
        friend ofstream& operator << (ofstream& out, const Pizza& pizza);

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
