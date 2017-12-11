#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "Pizza.h"
#include "Toppings.h"
#include "Order.h"

class PizzaRepo
{
    public:
        vector <string> readLocations();
        void addLocationToList(string location);
        void reWriteLocationList(vector <string> locations);
        void addOrderToList(Order order);

    private:
};

#endif // PIZZAREPO_H
