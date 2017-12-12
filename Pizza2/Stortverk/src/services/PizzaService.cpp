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
    string name;
    vector <string> costumerInfo;
    string extras = info[1];
    string delimiter = "^";
    unsigned int place = 0;
    while((place = info[1].find(delimiter)) != string::npos) {
        name = info[1].substr(0, place);
        if(name.compare("")) {
            costumerInfo.push_back(name);
        }
        info[1].erase(0, place + delimiter.length());
    }
   for(unsigned int i = 0; i < costumerInfo.size(); i++) {
    cout << costumerInfo[i] << endl;
   }

    cin >> name;
    info[0]; /// costumer info
    info[1]; /// extras
            /// rest is pizza!

    return order;
}

/*
std::string s = "scott>=tiger>=mushroom";
std::string delimiter = ">=";

size_t pos = 0;
std::string token;
while ((pos = s.find(delimiter)) != std::string::npos) {
    token = s.substr(0, pos);
    std::cout << token << std::endl;
    s.erase(0, pos + delimiter.length());
}
std::cout << s << std::endl;
*/
