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
    fin.close();
    return locations;
}

void PizzaRepo::addLocationToList(string location) {
    ofstream fout;
    fout.open("Locations.txt", ios::app);
    if(fout.is_open()) {
        fout << location << endl;
    }
    else {

    }
    fout.close();
}

void PizzaRepo::reWriteLocationList(vector <string> locations) {
    ofstream fout;
    fout.open("Locations.txt");
    if(fout.is_open()) {
        for(unsigned int i = 0; i < locations.size(); i++) {
            fout << locations[i] << endl;
        }
    }
    else {

    }
    fout.close();
}
