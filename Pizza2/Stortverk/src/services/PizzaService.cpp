#include "PizzaService.h"

vector <string> PizzaService::getLocation() {
    vector <string> locations;
    PizzaRepo get;
    locations = get.readLocations();

    return locations;
}
