#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "Pizza.h"
#include "Toppings.h"
#include "PizzaRepo.h"
#include "Main_ui.h"
#include "Order.h"


class PizzaService
{
    public:
        vector <string> getLocation();
        void addLocation(string location);
        bool removeLocation(string location);
        Toppings pickTopping(int number);
        void addOrder(Order order);
        vector <Order> getOrders();
        Order fixOrderInfo(vector <string> info);


    private:
        bool locationCheck(string location);
};

#endif // PIZZASERVICE_H
