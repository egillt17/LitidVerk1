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
        char getInProgress();
        char getIsReady();
        char getPickedOrSent();
        char getDelivered();
        char getPrice();
        char getPaidFor();
        void setPerson(string name);
        void setLocationForOrder(string location);
        void setComments(string comments);
        void setInProgress(char inProgress);
        void setIsReady(char isReady);
        void setPickedOrSent(char pickedOrSent);
        void setDelivered(char delivered);
        void setPrice(char price);
        void setPaidFor(char paidFor);
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
