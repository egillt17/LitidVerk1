#ifndef SALES_UI_H
#define SALES_UI_H
#include "Main_ui.h"
#include "Toppings.h"
#include "Pizza.h"
#include "Order.h"
#include <sstream>
#include <string>

class Sales_ui
{
    public:
        void salesMainUI();
        ///Function that displays the sales persons main UI
        Pizza addPizza();
        ///Function that is used to add a pizza, and displays a user interface where you can view and edit your pizza
        Toppings addExtras();
        ///Function that displays a list of all toppings and lets you choose which extra you want to add to your order
        void viewOrderTotal(Order takeOrder);
        ///Function that displays the order, with everything there is to know about that order
        void setOrderSettings(Order& order);
        ///Function that is used to set the settings of an order, such as location, picked or sent, or to set the paid status. Takes in an order

    private:
};

#endif // SALES_UI_H
