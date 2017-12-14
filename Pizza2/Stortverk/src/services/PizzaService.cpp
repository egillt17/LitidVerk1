#include "PizzaService.h"

vector <string> PizzaService::getLocation() {
    vector <string> locations;
    PizzaRepo get;
    locations = get.readLocations();    /// gets locations from repo

    return locations;   /// and returns them as a string vector
}

void PizzaService::addLocation(string location) {
    PizzaRepo get;
    if(!locationCheck(location)) {      /// checks if location has already been added
        get.addLocationToList(location);    /// if not then it gets added to the list
    }
}

bool PizzaService::removeLocation(string location) {
    vector <string> locations = getLocation();
    PizzaRepo get;
    for(unsigned int i = 0; i < locations.size(); i++) {    /// goes through all the locations
        if(!location.compare(locations[i])) {       /// checks if its the one its looking for
            locations.erase (locations.begin()+i);  /// and if it finds it then it gets erased from the vector
            get.reWriteLocationList(locations);     /// that vector then gets sent to repo to rewrite the file
            return true;        /// lets know if location was found and removed
        }
    }

    return false;   /// lets know if location wasn't found
}

bool PizzaService::locationCheck(string location) { /// checks if location has already been added
    PizzaRepo get;

    vector <string> locations = getLocation();

    for(unsigned int i = 0; i < locations.size(); i++) { /// goes through all the locations
        if(!location.compare(locations[i])) {   /// checks if its the same
            locations[i] = location;        /// sets it as that variable
            get.reWriteLocationList(locations);     /// re writes list
            return true;    /// returns true if it was found
        }
    }

    return false;   /// returns false if it wasn't found
}

void PizzaService::addOrder(Order order) {
    PizzaRepo get;
    get.addOrderToList(order);
    system("pause");
}

Order PizzaService::fixOrderInfo(vector <string> info) {    /// this funtion takes raw info from repo and processes it into an order variable
    Order order;        /// create an order variable
    Toppings tempTop;   /// create a temp topping variable
    string name;
    vector <string> costumerInfo; /// this is where all the costumer info gets sorted
    vector <string> extras; /// this is where all the extras get sorted
    vector <string> pizzaInfo;  /// this is where all the info about the pizza gets sorted
    vector <Toppings> pizzaToppings;    /// this is where all the toppings on the pizza gets sorted
    string delimiter = "^";     /// the delimiter that divides all the info
    unsigned int place = 0;
    unsigned int counter = 2;
    int counter2 = 0;
    for(unsigned int i = 0; i < info[0].length(); i++) {    /// goes through all the first string because that is where the costumer info is kept
        place = info[0].find(delimiter);    /// and checks where the delimiter is
        name = info[0].substr(0, place);    /// takes out the substring and puts it in the name variable
        if(name.compare("")) {  /// if name is not empty then it gets added the vector
            costumerInfo.push_back(name);   /// adds the costumer info to the vector
        }
        info[0].erase(0, place + delimiter.length());   /// erases the stuff that we are done with
    }
    for(unsigned int i = 0; i < info[1].length()+2; i++) {  /// goes through the next string in the vector because that is where the extras are kept
        place = info[1].find(delimiter);    /// and checks where the delimiter is
        name = info[1].substr(0, place);    /// takes out the substring and puts it in the name variable
        if(name.compare("")) {          /// if name is not empty then it gets added to the vector
            extras.push_back(name);     /// adds the extras info to the vector
        }
        info[1].erase(0, place + delimiter.length());   /// erases the stuff that we are done with
    }
    while(counter < info.size()) {  /// we know by how its written that the rest of the order is the pizzas
        counter2 = counter; /// the counter start in 2 because that is where the pizzas start
        if(counter % 2 == 0) {  /// we know that the pizza info is written every other line thats why it checks if the counter is even
            for(unsigned int i = 0; i < info[counter2].length(); i++) { /// goes through the entire line
                place = info[counter2].find(delimiter); /// finds where the delimiter is
                name = info[counter2].substr(0, place); /// puts the substring into the name variable
                if(name.compare("")) {  /// if name is not empty then it gets added to the vector
                    pizzaInfo.push_back(name);  /// adds the pizza info the the vector
                }
                info[counter2].erase(0, place + delimiter.length());    /// erases the stuff that we are done with
            }
        }
        else {  /// if the counter is not even then we know that is the line where the toppings are kept
            for(unsigned int i = 0; i < info[counter2].length(); i++) { /// goes through the entire line
                place = info[counter2].find(delimiter); /// searches for the delimiter
                name = info[counter2].substr(0, place); /// puts the substring in the name variable
                if(name.compare("")) {  /// if name is not empty then it gets added
                    tempTop.setName(name);  /// puts the name in a topping variable
                    pizzaToppings.push_back(tempTop); /// so it can be added to the topping vector
                }
                info[counter2].erase(0, place + delimiter.length());    /// erases the studd that we are done with
            }
            if(pizzaInfo[0].compare("No pizzas")) { /// if the first string in pizza info is no pizzas then we know that there are no pizzas
            order.addPizza(makePizzaFromVector(pizzaInfo, pizzaToppings));  /// so it wont call this function that makes a pizza variable
            }
            pizzaInfo.clear();  /// clears vector so it can be used again
            pizzaToppings.clear();  /// clears vector so it can be used again
        }
        counter++;  /// adds 1 to the counter
    }

    char tempProg = '0';    /// char variable for progress
    char tempPick = '0';    /// char variable for pick up or sent
    char tempDeliv = '0';   /// char variable for delivered
    char tempPaidFor = '0'; /// char variable for paid for
    int tempPrice = 0;      /// int variable for price
    stringstream sin(costumerInfo[5]);  /// takes where the price is kept
    sin >> tempPrice;   /// and converts it into an int
    stringstream sin2(costumerInfo[2]); /// takes where the progress was being kept
    sin2 >> tempProg;   /// and converts it into a char
    stringstream sin3(costumerInfo[3]); /// takes where the pick up or sent was being kept
    sin3 >> tempPick;   /// and converts it into a char
    stringstream sin4(costumerInfo[4]); /// takes where the delivery was being kept
    sin4 >> tempDeliv;  /// and converts it into a char
    stringstream sin5(costumerInfo[6]); /// takes where the paid for was baing kept
    sin5 >> tempPaidFor;    /// and converts it into a char
    order.setExtras(makeToppingFromVector(extras)); /// sets extras for order
    order.setPerson(costumerInfo[0]);   /// sets persons name for order
    order.setLocationForOrder(costumerInfo[1]); /// sets location for order
    order.setProgress(tempProg);    /// sets progress for order
    order.setPickedOrSent(tempPick);    /// sets picked up or sent for order
    order.setDelivered(tempDeliv);  /// sets if pizza has been delivered
    order.setPrice(tempPrice);  /// sets the price of the order
    order.setPaidFor(tempPaidFor);  /// sets if the order has been paid for
    order.setComments(costumerInfo[7]); /// sets the comment that the costumer added

    return order;   /// returns the ready order
}

vector <Toppings> PizzaService::makeToppingFromVector(vector <string> extras) {
    vector <Toppings> readyExtras;
    int tempPrice = 0;
    string tempName;
    Toppings topping;

    for(unsigned int i = 0; i < extras.size(); i++) {   /// goes through the string vector
        if(i % 2 == 0) {    /// we know that the name is always written first
            tempName = extras[i];   /// add it to a temp variable
        }
        else {  /// then there is the price
            stringstream sin(extras[i]);
            sin >> tempPrice;   /// add and convert it to a temp int variable
            topping.setName(tempName);  /// sets extras name
            topping.setPrice(tempPrice);    /// sets extras price
            readyExtras.push_back(topping); /// adds that variable to a vector
        }
    }

    return readyExtras; /// then it returns the vector with all the extras
}

Pizza PizzaService::makePizzaFromVector(vector <string> pizzaInfo, vector <Toppings> pizzaToppings) {
    Pizza readyPizzas;  /// create a pizza variable
    int tempPrice = 0;  /// create a temp price variable
    char tempStatus = '0';  /// create a temp status variable
    stringstream sin(pizzaInfo[0]); /// convert the price
    sin >> tempPrice;   /// into an int
    stringstream sin2(pizzaInfo[3]);    /// convert the status
    sin2 >> tempStatus; /// into an char
    readyPizzas.setPrice(tempPrice);    /// sets the price of the pizza
    readyPizzas.setSize(pizzaInfo[1]);  /// sets the size of the pizza
    readyPizzas.setSauce(pizzaInfo[2]); /// sets the sauce of the pizza
    readyPizzas.setCrust(pizzaInfo[4]); /// sets the crust of the pizza
    readyPizzas.setStatus(tempStatus);  /// sets the status of the pizza

    for(unsigned int i = 0; i < pizzaToppings.size(); i++) {    /// goes through the list with all the toppings
        readyPizzas.addTopping(pizzaToppings[i]);   /// and adds them to the pizza variable
    }

    return readyPizzas; /// then returns the ready pizza
}

vector <Order> PizzaService::getOrderList() {   /// returns vector with all orders
    PizzaRepo get;  /// to access repo
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
