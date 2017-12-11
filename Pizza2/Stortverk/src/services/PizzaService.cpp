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
