#include "Order.h"

Order::Order()
{
    _pizza.clear();
    _extras.clear();
    _person = "Unknown";
    _location = "Unknown";
    _comments = "No added comments";
    _inProgress = 'n';
    _isReady = 'n';
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

void Order::setPerson(string person) {

    _person = person;
}

void Order::setLocationForOrder(string location) {

    _location = location;
}

ostream& operator << (ostream& out, const Order& order) {

    out << "Order: " << endl;
    out << "  Name: " << order._person << endl;
    out << "  Location: " << order._location << endl;
    out << "  Comments: " << order._comments << endl;
    out << "  Price: " << order._price << endl;
    out << "  Order in progress?: ";
    if (order._inProgress == 'n') {
        out << "No" << endl;
    }
    else if (order._inProgress == 'y') {
        out << "Yes" << endl;
    }
    else {
        out << "Unknown" << endl;
    }
    out << "  Order ready?: ";
    if (order._isReady == 'n') {
        out << "No" << endl;
    }
    else if (order._isReady == 'y') {
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
        out << "  " << order._extras.at(i) << endl;
    }
    out << "  Pizzas: " << endl;
    for (unsigned int i = 0; i < order._pizza.size(); i++) {
        out << "  " << order._pizza.at(i) << endl;
    }
    return out;
}
