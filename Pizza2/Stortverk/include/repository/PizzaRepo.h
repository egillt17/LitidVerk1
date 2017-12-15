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
        /// reads all locations from the file
        void addLocationToList(string location);
        /// adds a location to the file
        void reWriteLocationList(vector <string> locations);
        /// rewrites the location file
        void addOrderToList(Order order);
        /// adds an order to the file
        vector <Order> readOrders();
        /// reads all orders from the file
        void reWriteOrders(vector <Order> orders);
        /// rewrites order file
        vector <string> readPizzaSpecials();
        /// reads all pizza specials from file
        void addPizzaSpecial(Pizza pizza);
        /// adds pizza special from file
        void reWritePizzaSpecial(vector <Pizza> pizzas);
        /// rewrites pizza special file
        void addDeliveredOrdersToList(vector <Order> orders);

    private:
};

#endif // PIZZAREPO_H
