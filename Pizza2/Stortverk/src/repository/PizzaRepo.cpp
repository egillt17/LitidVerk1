#include "PizzaRepo.h"

vector <string> PizzaRepo::readLocations() {
    vector <string> locations;
    string location;
    ifstream fin;
    fin.open("Locations.txt");
    if(fin.is_open()) {
        while(getline(fin, location)) {
            locations.push_back(location);
        }
    }

    return locations;
}
