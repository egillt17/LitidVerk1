#include "Order.h"

Order::Order()
{
    _pizza.clear();
    _extras.clear();
    _person = "Unknown";
    _location = "Unknown";
    _comments = "No added comments";
    _Progress = 'n';
    _pickedOrSent = 'u';
    _delivered = 'n';
    _price = 0;
    _paidFor = 'n';
}

vector<Pizza> Order::getPizzas() {

    return _pizza;
}

vector<Toppings> Order::getExtras() {

    return _extras;
}

string Order::getPerson() {

    return _person;
}

string Order::getLocation() {

    return _location;
}

string Order::getComments() {

    return _comments;
}

char Order::getProgress() {

    return _Progress;
}

char Order::getPickedOrSent() {

    return _pickedOrSent;
}

char Order::getDelivered() {

    return _delivered;
}

char Order::getPrice() {

    return _price;
}

char Order::getPaidFor() {

    return _paidFor;
}

int Order::getPizzaTotalCost() {
    int totalCost = 0;
    for(unsigned int i = 0; i < _pizza.size(); i++) {
        totalCost += _pizza[i].getPrice();
    }

    return totalCost;
}
int Order::getExtrasTotalCost() {
    int totalCost = 0;
    for(unsigned int i = 0; i < _extras.size(); i++) {
        totalCost += _extras[i].getPrice();
    }

    return totalCost;
}

void Order::addPizza(Pizza pizza) {
    _pizza.push_back(pizza);
}
void Order::addExtras(Toppings extra) {
    _extras.push_back(extra);
}

void Order::setPerson(string person) {

    _person = person;
}

void Order::setLocationForOrder(string location) {

    _location = location;
}

void Order::setComments(string comments) {

    _comments = comments;
}

void Order::setProgress(char inProgress) {

    _Progress = inProgress;
}

void Order::setPickedOrSent(char pickedOrSent) {

    _pickedOrSent = pickedOrSent;
}

void Order::setDelivered(char delivered) {

    _delivered = delivered;
}

void Order::setPrice(int price) {

    _price = price;
}

void Order::setPaidFor(char paidFor) {

    _paidFor = paidFor;
}

ostream& operator << (ostream& out, Order& order) {

    out << "Order: " << endl;
    out << "  Name: " << order._person << endl;
    out << "  Location: " << order._location << endl;
    out << "  Comments: " << order._comments << endl;
    out << "  Price: " << order._price << endl;
    out << "  Order in progress?: ";
    if (order._Progress == 'n') {
        out << "No" << endl;
    }
    else if (order._Progress == 'w') {
        out << "Waiting" << endl;
    }
    else if (order._Progress == 'y') {
        out << "Yes" << endl;
    }
    else {
        out << "Unknown" << endl;
    }
    out << "  Order picked up or sent?: ";
    if (order._pickedOrSent == 'p') {
        out << "Picked up" << endl;
    }
    else if (order._pickedOrSent == 'd') {
        out << "sent" << endl;
    }
    else {
        out << "Unknown" << endl;
    }
    out << "  Order paid for?: ";
    if (order._paidFor == 'n') {
        out << "No" << endl;
    }
    else if (order._paidFor == 'p') {
        out << "Yes" << endl;
    }
    else {
        out << "Unknown" << endl;
    }
    out << "  Order delivered?: ";
    if (order._delivered == 'n') {
        out << "No" << endl;
    }
    else if (order._delivered == 'y') {
        out << "Yes" << endl;
    }
    else {
        out << "Unknown" << endl;
    }
    out << "  Extras: " << endl;
    for (unsigned int i = 0; i < order._extras.size(); i++) {
        out << order._extras.at(i);
    }
    out << "  Pizzas: " << endl;
    for (unsigned int i = 0; i < order._pizza.size(); i++) {
        out << order._pizza.at(i) << endl;
    }
    return out;
}

ofstream& operator << (ofstream& out, Order& order) {
    out << "^" << order._person;
    out << "^" << order._location;
    out << "^" << order._Progress;
    out << "^" << order._pickedOrSent;
    out << "^" << order._delivered;
    out << "^" << order._price;
    out << "^" << order._paidFor;
    out << "^" << order._comments << endl;
    for(unsigned int i = 0; i < order._extras.size(); i++) {
        out << "^" << order._extras[i].getName() << "^" << order._extras[i].getPrice();
    }
    for(unsigned int i = 0; i < order._extras.size(); i++) {
        out << "^" << order._extras[i].getName() << "^" << order._extras[i].getPrice();
    }


    return out;
}
