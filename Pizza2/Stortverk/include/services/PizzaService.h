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
        /// returns all the locations
        void addLocation(string location);
        /// sends location to repo to be added to the list
        bool removeLocation(string location);
        /// removes location from the list
        void addOrder(Order order);
        /// adds an order to the order list
        Order fixOrderInfo(vector <string> info);
        /// takes info from repo and turns it into an order variable
        vector <Order> getOrderList();
        /// returns list with all orders
        vector <Order> getUnfinishedOrdersforASpecificLocation(string location);
        /// returns all unfinished orders for a specific location
        void reWriteOrdersService(vector <Order> orders, string location);
        /// sends the orders to repo to be re writen into the file
        vector <Order> getReadyOrdersforASpecificLocation(string location);
        /// returns all ready orders for a specific location
        vector <Order> getAllOrdersforASpecificLocation(string location);
        /// returns all orders for a specific location
        vector <Pizza> getPizzaSpecials();
        /// returns all pizza specials from the file
        void addPizzaSpecialToList(Pizza pizza);
        /// adds a pizza special to the list
        void reWritePizzaService(vector <Pizza> pizzas);
        /// sends pizza special list to repo to be re writen


    private:
        vector <Toppings> makeToppingFromVector(vector <string> extras);
        /// takes a string vector and and puts the info into a topping vector
        Pizza makePizzaFromVector(vector <string> pizzaInfo, vector <Toppings> pizzaToppings);
        /// takes 2 string vectors one with info about the pizza the other with all the toppings and turns it
        /// into a pizza variable and returns that
        void checkIfOrderIsReady(vector <Order>& allOrders);
        /// checks all the orders and if all the pizzas in a specific order are ready then the order gets marked as ready
        bool locationCheck(string location);
        /// checks if location has already been added
};

#endif // PIZZASERVICE_H
