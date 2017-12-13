#include "PizzaService.h"

vector <string> PizzaService::getLocation() {
    vector <string> locations;
    PizzaRepo get;
    locations = get.readLocations();

    return locations;
}

void PizzaService::addLocation(string location) {
    PizzaRepo get;
    if(!locationCheck(location)) {
        get.addLocationToList(location);
    }
}

bool PizzaService::removeLocation(string location) {
    vector <string> locations = getLocation();
    PizzaRepo get;
    for(unsigned int i = 0; i < locations.size(); i++) {
        if(!location.compare(locations[i])) {
            locations.erase (locations.begin()+i);
            get.reWriteLocationList(locations);
            return true;
        }
    }

    return false;
}

bool PizzaService::locationCheck(string location) {
    PizzaRepo get;

    vector <string> locations = getLocation();

    for(unsigned int i = 0; i < locations.size(); i++) {
        if(!location.compare(locations[i])) {
            locations[i] = location;
            get.reWriteLocationList(locations);
            return true;
        }
    }

    return false;
}

vector<Order> PizzaService::getOrders() {
    vector <Order> orders;

    return orders;
}

void PizzaService::addOrder(Order order) {
    PizzaRepo get;
    get.addOrderToList(order);
    system("pause");
}

Order PizzaService::fixOrderInfo(vector <string> info) {
    Order order;
    Toppings tempTop;
    string name;
    vector <string> costumerInfo;
    vector <string> extras;
    vector <string> pizzaInfo;
    vector <Toppings> pizzaToppings;
    string delimiter = "^";
    unsigned int place = 0;
    while((place = info[0].find(delimiter)) != string::npos) {
        name = info[0].substr(0, place);
        if(name.compare("")) {
            costumerInfo.push_back(name);
        }
        info[0].erase(0, place + delimiter.length());
    }
    while((place = info[1].find(delimiter)) != string::npos) {
        name = info[1].substr(0, place);
        if(name.compare("")) {
            extras.push_back(name);
        }
        info[1].erase(0, place + delimiter.length());
    }
    for(unsigned int i = 2; i < info.size(); i++) {
        if( i % 2 == 0) {
            while((place = info[i].find(delimiter)) != string::npos) {
            name = info[i].substr(0, place);
            if(name.compare("")) {
                pizzaInfo.push_back(name);
            }
                info[i].erase(0, place + delimiter.length());
            }
        }
        else {
            while((place = info[i].find(delimiter)) != string::npos) {
            name = info[i].substr(0, place);
            if(name.compare("")) {
                tempTop.setName(name);
                pizzaToppings.push_back(tempTop);
            }
                info[i].erase(0, place + delimiter.length());
            }
            order.addPizza(makePizzaFromVector(pizzaInfo, pizzaToppings));
            pizzaInfo.clear();
            pizzaToppings.clear();
        }
    }
    char tempProg = '0';
    char tempPick = '0';
    char tempDeliv = '0';
    char tempPaidFor = '0';
    int tempPrice = 0;
    stringstream sin(costumerInfo[5]);
    sin >> tempPrice;
    stringstream sin2(costumerInfo[2]);
    sin2 >> tempProg;
    stringstream sin3(costumerInfo[3]);
    sin3 >> tempPick;
    stringstream sin4(costumerInfo[4]);
    sin4 >> tempDeliv;
    stringstream sin5(costumerInfo[6]);
    sin5 >> tempPaidFor;
    order.setExtras(makeToppingFromVector(extras));
    order.setPerson(costumerInfo[0]);
    order.setLocationForOrder(costumerInfo[1]);
    order.setProgress(tempProg);
    order.setPickedOrSent(tempPick);
    order.setDelivered(tempDeliv);
    order.setPrice(tempPrice);
    order.setPaidFor(tempPaidFor);
    order.setComments(costumerInfo[7]);

    return order;
}

vector <Toppings> PizzaService::makeToppingFromVector(vector <string> extras) {
    vector <Toppings> readyExtras;
    int tempPrice = 0;
    string tempName;
    Toppings topping;

    for(unsigned int i = 0; i < extras.size(); i++) {
        if(i % 2 == 0) {
            tempName = extras[i];
        }
        else {
            stringstream sin(extras[i]);
            sin >> tempPrice;
            topping.setName(tempName);
            topping.setPrice(tempPrice);
            readyExtras.push_back(topping);
        }
    }

    return readyExtras;
}

Pizza PizzaService::makePizzaFromVector(vector <string> pizzaInfo, vector <Toppings> pizzaToppings) {
    Pizza readyPizzas;
    int tempPrice = 0;
    char tempStatus = '0';
    stringstream sin(pizzaInfo[0]);
    sin >> tempPrice;
    stringstream sin2(pizzaInfo[4]);
    sin2 >> tempStatus;
    readyPizzas.setPrice(tempPrice);
    readyPizzas.setSize(pizzaInfo[1]);
    readyPizzas.setSauce(pizzaInfo[2]);
    readyPizzas.setCrust(pizzaInfo[3]);
    readyPizzas.setStatus(tempStatus);

    for(unsigned int i = 0; i < pizzaToppings.size(); i++) {
        readyPizzas.addTopping(pizzaToppings[i]);
    }

    return readyPizzas;
}

vector <Order> PizzaService::getOrderList() {
    PizzaRepo get;
    vector <Order> orders = get.readOrders();

    return orders;
}

vector <Order> PizzaService::getOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();
    vector <Order> locationOrders;

    for(unsigned int i = 0; i < allOrders.size(); i++) {
        if(!location.compare(allOrders[i].getLocation()) && allOrders[i].getProgress() != 'r') {
            locationOrders.push_back(allOrders[i]);
        }
    }

    return locationOrders;
}
