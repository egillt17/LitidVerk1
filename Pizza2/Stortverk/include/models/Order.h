#ifndef ORDER_H
#define ORDER_H
#include "Pizza.h"
#include "Toppings.h"


class Order
{
    public:
        Order();
        void clearOrder(Order& order);
        /// clears order when it gets commited
        vector<Pizza> getPizzas();
        ///Get function that return the variable pizzas
        vector<Toppings> getExtras();
        ///Get function that return the variable Extras
        string getPerson();
        ///Get function that return the variable Person
        string getLocation();
        ///Get function that return the variable Location
        string getComments();
        ///Get function that return the variable Comments
        char getProgress();
        ///Get function that return the variable Progress
        char getPickedOrSent();
        ///Get function that return the variable PickedUpOrSent
        char getDelivered();
        ///Get function that return the variable Delivered
        int getPrice();
        ///Get function that return the variable Price
        char getPaidFor();
        ///Get function that return the variable PaidFor
        int getPizzaTotalCost();
        ///Get function that return the variable PizzatotalCost
        int getExtrasTotalCost();
        ///Get function that return the variable ExtraTotalCost
        void addPizza(Pizza pizza);
        ///set function that adds the pizza that was sent to the function to the vector pizzas
        void setExtras(vector <Toppings> extras);
        /// takes a vector of extras and sets it as the extras in the order
        void setPizzas(vector <Pizza> pizzas);
        /// takes a vector of pizzas and sets it as the pizzas in the order
        void addExtras(Toppings extra);
        ///set function that adds the extra that was sent to the function to the vector extras
        void setPerson(string name);
        ///Set function that sets the Person varialbe with the string that was sent to the function
        void setLocationForOrder(string location);
        ///Set function that sets the location varialbe with the string that was sent to the function
        void setComments(string comments);
        ///Set function that sets the comments varialbe with the string that was sent to the function
        void setProgress(char inProgress);
        ///Set function that sets the progress varialbe with the char that was sent to the function
        void setPickedOrSent(char pickedOrSent);
        ///Set function that sets the PickedOrSent varialbe with the char that was sent to the function
        void setDelivered(char delivered);
        ///Set function that sets the Delivered varialbe with the char that was sent to the function
        void setPrice(int price);
        ///Set function that sets the Price varialbe with the int that was sent to the function
        void setPaidFor(char paidFor);
        ///Set function that sets the PaidFor varialbe with the chat that was sent to the function
        friend ostream& operator << (ostream& out, Order& order);
        ///Function that overleads the ostream operator
        friend ofstream& operator << (ofstream& out, Order& order);
        ///Function that overleads the ofstream operator

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
