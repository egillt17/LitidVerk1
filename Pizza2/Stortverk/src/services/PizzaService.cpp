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
    unsigned int counter = 2;
    int counter2 = 0;
    for(unsigned int i = 0; i < info[0].length(); i++) {
        place = info[0].find(delimiter);
        name = info[0].substr(0, place);
        if(name.compare("")) {
            costumerInfo.push_back(name);
        }
        info[0].erase(0, place + delimiter.length());
    }
    for(unsigned int i = 0; i < info[1].length()+2; i++) {
        place = info[1].find(delimiter);
        name = info[1].substr(0, place);
        if(name.compare("")) {
            extras.push_back(name);
        }
        info[1].erase(0, place + delimiter.length());
    }
    while(counter < info.size()) {
        counter2 = counter;
        if(counter % 2 == 0) {
            for(unsigned int i = 0; i < info[counter2].length(); i++) {
                place = info[counter2].find(delimiter);
                name = info[counter2].substr(0, place);
                if(name.compare("")) {
                    pizzaInfo.push_back(name);
                }
                info[counter2].erase(0, place + delimiter.length());
            }
        }
        else {
            for(unsigned int i = 0; i < info[counter2].length(); i++) {
                place = info[counter2].find(delimiter);
                name = info[counter2].substr(0, place);
                if(name.compare("")) {
                    tempTop.setName(name);
                    pizzaToppings.push_back(tempTop);
                }
                info[counter2].erase(0, place + delimiter.length());
            }
            if(pizzaInfo[0].compare("No pizzas")) {
            order.addPizza(makePizzaFromVector(pizzaInfo, pizzaToppings));
            }
            pizzaInfo.clear();
            pizzaToppings.clear();
        }
        counter++;
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
    stringstream sin2(pizzaInfo[3]);
    sin2 >> tempStatus;
    readyPizzas.setPrice(tempPrice);
    readyPizzas.setSize(pizzaInfo[1]);
    readyPizzas.setSauce(pizzaInfo[2]);
    readyPizzas.setCrust(pizzaInfo[4]);
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

vector <Order> PizzaService::getUnfinishedOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();
    vector <Order> locationOrders;

    for(unsigned int i = 0; i < allOrders.size(); i++) {
        if(!location.compare(allOrders[i].getLocation()) && allOrders[i].getProgress() != 'r') {
            locationOrders.push_back(allOrders[i]);
        }
    }
    return locationOrders;
}

void PizzaService::reWriteOrdersService(vector <Order> orders, string location) {
    vector <Order> allOrders = getOrderList();
    PizzaRepo get;

    for(unsigned int i = 0; i < allOrders.size(); i++) {
        if(location.compare(allOrders[i].getLocation())) {
            orders.push_back(allOrders[i]);
        }
    }
    checkIfOrderIsReady(orders);
    get.reWriteOrders(orders);
}

vector <Order> PizzaService::getReadyOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();
    vector <Order> readyOrders;

    for(unsigned int i = 0; i < allOrders.size(); i++) {
        if(!location.compare(allOrders[i].getLocation()) && allOrders[i].getProgress() == 'r') {
            readyOrders.push_back(allOrders[i]);
        }
    }
    return readyOrders;
}

vector <Order> PizzaService::getAllOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();
    vector <Order> AllOrdersAtLocation;

    for(unsigned int i = 0; i < allOrders.size(); i++) {
        if(!location.compare(allOrders[i].getLocation())) {
            AllOrdersAtLocation.push_back(allOrders[i]);
        }
    }
    return AllOrdersAtLocation;
}

void PizzaService::checkIfOrderIsReady(vector <Order>& allOrders) {
    vector <Pizza> tempPizza;
    int counter = 0;
    for(unsigned int i = 0; i < allOrders.size(); i++) {
        counter = 0;
        tempPizza = allOrders[i].getPizzas();
        for(unsigned int j = 0; j < tempPizza.size(); j++) {
            if(tempPizza[j].getStatus() != 'r') {
                counter++;
            }
        }
        if(counter == 0) {
            allOrders[i].setProgress('r');
        }
    }
}

vector <Pizza> PizzaService::getPizzaSpecials() {
    vector <Pizza> pizzaSpecials;
    vector <string> pizzaInfo;
    vector <Toppings> pizzaToppings;
    PizzaRepo get;
    string delimiter = "^";
    string name = "";
    unsigned int place = 0;
    unsigned int counter = 0;
    int counter2 = 0;
    Toppings tempTop;
    vector <string> info = get.readPizzaSpecials();
    while(counter < info.size()) {
        counter2 = counter;
        if(counter % 2 == 0) {
            for(unsigned int i = 0; i < info[counter2].length(); i++) {
                place = info[counter2].find(delimiter);
                name = info[counter2].substr(0, place);
                if(name.compare("")) {
                    pizzaInfo.push_back(name);
                }
                info[counter2].erase(0, place + delimiter.length());
            }
        }
        else {
            for(unsigned int i = 0; i < info[counter2].length(); i++) {
                place = info[counter2].find(delimiter);
                name = info[counter2].substr(0, place);
                if(name.compare("")) {
                    tempTop.setName(name);
                    pizzaToppings.push_back(tempTop);
                }
                info[counter2].erase(0, place + delimiter.length());
            }
            if(pizzaInfo[0].compare("No pizzas")) {
            pizzaSpecials.push_back(makePizzaFromVector(pizzaInfo, pizzaToppings));
            }
            pizzaInfo.clear();
            pizzaToppings.clear();
        }
        counter++;
    }

    return pizzaSpecials;
}

void PizzaService::addPizzaSpecialToList(Pizza pizza) {
    PizzaRepo get;
    get.addPizzaSpecial(pizza);
}

void reWritePizzaService(vector <Pizza> pizzas) {
    PizzaRepo get;
    get.reWritePizzaSpecial(pizzas);
}
