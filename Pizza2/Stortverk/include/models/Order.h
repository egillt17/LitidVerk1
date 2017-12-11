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
        string getLocation();
        string getComments();
        char getProgress();
        char getPickedOrSent();
        char getDelivered();
        char getPrice();
        char getPaidFor();
        int getPizzaTotalCost();
        int getExtrasTotalCost();
        void addPizza(Pizza pizza);
        void addExtras(Toppings extra);
        void setPerson(string name);
        void setLocationForOrder(string location);
        void setComments(string comments);
        void setProgress(char inProgress);
        void setPickedOrSent(char pickedOrSent);
        void setDelivered(char delivered);
        void setPrice(int price);
        void setPaidFor(char paidFor);
        friend ostream& operator << (ostream& out, Order& order);
        friend ofstream& operator << (ofstream& out, Order& order);

    private:
        vector<Pizza> _pizza;
        vector<Toppings> _extras;
        string _person;
        string _location;
        string _comments;
        char _Progress;
        char _pickedOrSent;
        char _delivered;
        int _price;
        char _paidFor;

};

#endif // ORDER_H
