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
    vector <Order> allOrders = getOrderList();  /// gets all orders
    vector <Order> locationOrders;

    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all the orders
        if(!location.compare(allOrders[i].getLocation()) && allOrders[i].getProgress() != 'r') {    /// checks if it is the right location and if its not ready
            locationOrders.push_back(allOrders[i]); /// if it meets those requirements then it gets added to the other vector
        }
    }
    return locationOrders;  /// returns the filtered vector
}

void PizzaService::reWriteOrdersService(vector <Order> orders, string location) {   /// sends orders to be re written in repo
    vector <Order> allOrders = getOrderList();  /// gets all orders
    PizzaRepo get;

    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all the orders
        if(location.compare(allOrders[i].getLocation())) {  /// if its not the same as the location then it gets added
            orders.push_back(allOrders[i]);         /// because the vector that gets sent in only has the orders for a specific location
        }
    }
    checkIfOrderIsReady(orders);    /// goes through the orders and checks if they are ready
    orders = checkIfOrderIsDelivered(orders);
    get.reWriteOrders(orders);      /// then it gets sent down to the repo to be re written
}

vector <Order> PizzaService::getReadyOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();  /// gets all orders
    vector <Order> readyOrders;

    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all the orders
        if(!location.compare(allOrders[i].getLocation()) && allOrders[i].getProgress() == 'r') {    /// checks if they are the right location and if they are ready
            readyOrders.push_back(allOrders[i]);    /// if they meet the requirements then they get added
        }
    }
    return readyOrders; /// returns the filtered vector
}

vector <Order> PizzaService::getAllOrdersforASpecificLocation(string location) {
    vector <Order> allOrders = getOrderList();  /// gets all orders
    vector <Order> AllOrdersAtLocation;

    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all orders
        if(!location.compare(allOrders[i].getLocation())) { /// and checks if they have the right location
            AllOrdersAtLocation.push_back(allOrders[i]);    /// if so they get added
        }
    }
    return AllOrdersAtLocation; /// returns filtered vector
}

void PizzaService::checkIfOrderIsReady(vector <Order>& allOrders) {
    vector <Pizza> tempPizza;   /// temp pizza vector
    int counter = 0;    /// create a counter
    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all the vector
        counter = 0;    /// nulls counter
        tempPizza = allOrders[i].getPizzas();   /// puts all the pizzas of the order in the temp vector
        for(unsigned int j = 0; j < tempPizza.size(); j++) {    /// goes through all the pizzas
            if(tempPizza[j].getStatus() != 'r') {   /// if they are not ready then it gets marked
                counter++;
            }
        }
        if(counter == 0) {  /// if there was nothing marked with a specific order that means that everything is ready
            allOrders[i].setProgress('r');  /// and the order gets marked as ready
        }
    }
}

vector <Pizza> PizzaService::getPizzaSpecials() {   /// returns the pizza specials
    vector <Pizza> pizzaSpecials;   /// create a pizza vector
    vector <string> pizzaInfo;  /// create a for the pizza info
    vector <Toppings> pizzaToppings;    /// vector for the pizza topping
    PizzaRepo get;
    string delimiter = "^"; /// set delimiter
    string name = "";
    unsigned int place = 0;
    unsigned int counter = 0;
    int counter2 = 0;
    Toppings tempTop;
    vector <string> info = get.readPizzaSpecials(); /// put all the info that was sent from repo into this vector
    while(counter < info.size()) {  /// goes through the entire vector
        counter2 = counter;
        if(counter % 2 == 0) {  /// we check if its even because we know that the pizza info is written in every other line
            for(unsigned int i = 0; i < info[counter2].length(); i++) { /// goes through the entire string
                place = info[counter2].find(delimiter); /// checks for delimiter
                name = info[counter2].substr(0, place); /// puts substring in name
                if(name.compare("")) {  /// if name is empty then it doesnt get added
                    pizzaInfo.push_back(name);  /// adds name to the pizza info
                }
                info[counter2].erase(0, place + delimiter.length());    /// erases the stuff that we dont need any more
            }
        }
        else {  /// because we know that in the line below pizza info the toppings are written
            for(unsigned int i = 0; i < info[counter2].length(); i++) {   /// goes through the entire string
                place = info[counter2].find(delimiter); /// checks for delimiter
                name = info[counter2].substr(0, place); /// puts the substring in name
                if(name.compare("")) {  /// if name is empty then it doesnt get added
                    tempTop.setName(name);  /// puts name into temp topping variable
                    pizzaToppings.push_back(tempTop);   /// then the topping variable gets added to the vector
                }
                info[counter2].erase(0, place + delimiter.length());    /// erases the stuff that we dont need any more
            }
            pizzaSpecials.push_back(makePizzaFromVector(pizzaInfo, pizzaToppings)); /// gets made into a pizza variable that gets added to the vector
            pizzaInfo.clear();  /// clears vector
            pizzaToppings.clear();  /// clears vector
        }
        counter++;  /// adds one to the counter
    }

    return pizzaSpecials;   /// returns the vector with all the pizzas
}

void PizzaService::addPizzaSpecialToList(Pizza pizza) { /// gets pizza form ui
    PizzaRepo get;
    get.addPizzaSpecial(pizza); /// to be sent down to repo
}

void PizzaService::reWritePizzaService(vector <Pizza> pizzas) {   /// gets vector
    PizzaRepo get;
    get.reWritePizzaSpecial(pizzas);    /// to be sent down to repo so the file can be rewritten
}

vector <Order> PizzaService::checkIfOrderIsDelivered(vector <Order> allOrders) {
    vector <Order> deliveredOrders; /// vector for delivered orders
    vector <Order> unDeliveredOrders;   /// vector for undelivered orders
    PizzaRepo get;

    for(unsigned int i = 0; i < allOrders.size(); i++) {    /// goes through all the orders
        if(allOrders[i].getDelivered() == 'y') {    /// if they are marked as delivered
            deliveredOrders.push_back(allOrders[i]);    /// then they get added to the delivered vector
        }
        else{   /// else they get added to the undelivered orders
            unDeliveredOrders.push_back(allOrders[i]);
        }
    }
    if(!deliveredOrders.empty()) {  /// if delivered orders is not empty then it gets sent to repo
        get.addDeliveredOrdersToList(deliveredOrders);
    }

    return unDeliveredOrders;   /// returns all undelivered orders
}

vector <Order> PizzaService::getOldOrders() {
    PizzaRepo get;
    vector <Order> oldOrders = get.readOldOrders(); /// gets all old orders from repo
    return oldOrders;   /// and returns them
}

int PizzaService::TotalSales() {
    vector <Order> oldOrders = getOldOrders();  /// gets all old orders
    int salesTotal = 0;
    for(unsigned int i = 0; i < oldOrders.size(); i ++) {   /// goes through them
        salesTotal += oldOrders[i].getPrice();  /// and adds all the prices up in this variable
    }

    return salesTotal; /// then it returns all the sales numbers
}

int PizzaService::AverageOrderPrice() {
    vector <Order> oldOrders = getOldOrders();  /// gets all the orders
    int salesTotal = TotalSales();  /// gets total sales
    int averagePriceOfOrder = salesTotal / oldOrders.size();    /// divides total sales with the number of old orders

    return averagePriceOfOrder; /// and returns the average of all orders
}

