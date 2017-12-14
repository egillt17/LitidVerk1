#include "Pizza.h"

Pizza::Pizza() {                            ///default constructor that resets the private variables of a pizza
    _price = 0;
    _topping.clear();
    _size = "Not picked";
    _sauce = "Pizza sauce";
    _crust = "Regular crust";
    _status = 'n';
}

void Pizza::setPrice(int price) {                   ///Get and set functions
    _price = price;
}

void Pizza::setSize(string size_of) {
    _size = size_of;
}

void Pizza::setSauce(string sauce) {
    _sauce = sauce;
}

void Pizza::setCrust(string crust) {
    _crust = crust;
}

void Pizza::setStatus(char status) {
    _status = status;
}

void Pizza::addTopping(Toppings topping) {
    _topping.push_back(topping);
}
void Pizza::clearTopping() {
    _topping.clear();
}

int Pizza::getToppingPrice() {                          ///for loop to count the price of each individual toppings, then adds it together and returns the total cost of toppings
    int totalPrice = 0;
    for(unsigned int i = 0; i < _topping.size(); i++) {
        totalPrice += _topping[i].getPrice();
    }
    return totalPrice;
}

int Pizza::getPrice() {
    return _price;
}

vector <Toppings> Pizza::getToppings() {
    return _topping;
}

string Pizza::getSize() {
    return _size;
}

string Pizza::getSauce() {
    return _sauce;
}

string Pizza::getCrust() {
    return _crust;
}

char Pizza::getStatus() {
    return _status;
}

ostream& operator << (ostream& out, Pizza& pizza) {
    out << "| Price: " << pizza._price << endl;
    out << "| Toppings: ";
    if(pizza._topping.empty()) {
        out << endl;
    }
    else {
        for(unsigned int i = 0; i < pizza._topping.size(); i++) {           ///Displays the toppings if any have been picked  and prints them to the screen
            if(i == (pizza._topping.size()-1)) {
                out << pizza._topping[i].getName() << endl;
            }
            else {
                out << pizza._topping[i].getName() << ", ";
            }
        }
    }
    out << "| Size: " << pizza._size << endl;
    out << "| Sauce: " << pizza._sauce << endl;
    out << "| Crust: " << pizza._crust << endl;
    out << "| Status: "; 
    if(pizza._status == 'n'){
        out << "Not Ready" << endl;
    }
    else if(pizza._status == 'i'){
        out << "In Progress" << endl;
    }
    else if(pizza._status == 'r'){
        out << "Ready" << endl;
    }
    return out;
}

ofstream& operator << (ofstream& out, Pizza& pizza) {
    out << "^" << pizza._price;
    out << "^" << pizza._size;
    out << "^" << pizza._sauce;
    out << "^" << pizza._status;
    out << "^" << pizza._crust << "^" << endl;                   ///Here we're using the '^' symbol as a delimiter to write to .txt files
    if(pizza._topping.empty()) {
        out << "^" << "No toppings";
    }
    else {
        for(unsigned int i = 0; i < pizza._topping.size(); i++) {
            out << "^" << pizza._topping[i].getName();
        }
    }
    out << "^" << endl;
    return out;
}
