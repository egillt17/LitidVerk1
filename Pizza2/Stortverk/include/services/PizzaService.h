#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "Pizza.h"
#include "Toppings.h"
#include "PizzaRepo.h"
#include "Main_ui.h"
#include "Order.h"
#include "TopService.h"


class PizzaService
{
    public:
        vector <string> getLocation();
        void addLocation(string location);
        bool removeLocation(string location);
        Toppings pickTopping(int number);
        void addOrder(Order order);
        Order fixOrderInfo(vector <string> info);
        vector <Toppings> makeToppingFromVector(vector <string> extras);
        Pizza makePizzaFromVector(vector <string> pizzaInfo, vector <Toppings> pizzaToppings);
        vector <Order> getOrderList();
        vector <Order> getUnfinishedOrdersforASpecificLocation(string location);
        void reWriteOrdersService(vector <Order> orders, string location);
        vector <Order> getReadyOrdersforASpecificLocation(string location);
        vector <Order> getAllOrdersforASpecificLocation(string location);
        vector <Pizza> getPizzaSpecials();
        void addPizzaSpecialToList(Pizza pizza);
        void reWritePizzaService(vector <Pizza> pizzas);


    private:
        void checkIfOrderIsReady(vector <Order>& allOrders);
        bool locationCheck(string location);
};

#endif // PIZZASERVICE_H
