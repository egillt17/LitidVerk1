#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "Pizza.h"
#include "Toppings.h"

class PizzaRepo
{
    public:
        vector <string> readLocations();
        void addLocationToList(string location);
        void reWriteLocationList(vector <string> locations);

    private:
};

#endif // PIZZAREPO_H
