#include "TopService.h"

vector <Toppings> TopService::getToppingList(int pick) {
   vector <Toppings> toppingList;
   ToppingRepo get;
   toppingList = get.ReadToppings(pick);            ///Function that takes in an int pick which represents which extra you want to get, (extras are a part of the toppings class
                                                    ///because toppings only consist a name and price.
    return toppingList;
}

void TopService::addTopping(string name, string price, int pick) {
    Toppings topping;
    ToppingRepo get;
    topping = make_topping(name, price);            ///Function that is used when adding a new topping/extra

    if(!toppingCheck(topping, pick)) {              ///If the topping/extra is not on the list then it adds it to the list
        get.addToppingToList(topping, pick);

    }
}

bool TopService::removeTopping(string name, int pick) {
    vector <Toppings> toppingList;
    ToppingRepo get;                            ///Like above the pick represents the type of extra
    toppingList = getToppingList(pick);

    for(unsigned int i = 0; i < toppingList.size(); i++) {
        if(!name.compare(toppingList[i].getName())) {       ///If the name is found then the function removes that that extra from the .txt file
            toppingList.erase (toppingList.begin()+i);
            get.reWriteToppingList(toppingList, pick);      ///then rewrites the txt file
            return true;
        }
    }
    return false;
}

Toppings TopService::make_topping(string name, string price) {
    Toppings topping;
    int tempPrice = 0;
    stringstream sin(price);            ///stringstream that changes string price to an int tempPrice
    sin >> tempPrice;
    topping.setName(name);              ///Then sets the name and price of the topping the manager is making
    topping.setPrice(tempPrice);

    return topping;
}

bool TopService::toppingCheck(Toppings topping, int pick) {
    vector <Toppings> toppingList;
    ToppingRepo get;
    toppingList = getToppingList(pick);

    for(unsigned int i = 0; i < toppingList.size(); i++) {
        if(!topping.getName().compare(toppingList[i].getName())) {  ///Function that checks if the topping you are adding already exists, and if that is the case then
            toppingList[i] = topping;                               ///the file is rewritten
            get.reWriteToppingList(toppingList, pick);
            return true;
        }
    }

    return false;
}
