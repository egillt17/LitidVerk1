#ifndef PIZZAREPO_H
#define PIZZAREPO_H

#include "PizzaService.h"
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
        vector <Order> readOrders();
        void reWriteOrders(vector <Order> orders);
        vector <string> readPizzaSpecials();
        void addPizzaSpecial();

    private:
};

#endif // PIZZAREPO_H
