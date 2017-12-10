#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Toppings.h"


class Order
{
    public:
        Order();
        vector<Pizza> getPizzas();
        vector<Toppings> getExtras();
        string getPerson();
        void setPerson(string name);
        void setLocationForOrder(string location);
        friend ostream& operator << (ostream& out, const Order& order);


    private:
        vector<Pizza> _pizza;
        vector<Toppings> _extras;
        string _person;
        string _location;
        string _comments;
        char _inProgress;
        char _isReady;
        char _pickedOrSent;
        char _delivered;
        int _price;
        char _paidFor;

};

#endif // ORDER_H
