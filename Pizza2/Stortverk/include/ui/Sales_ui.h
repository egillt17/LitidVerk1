#ifndef SALES_UI_H
#define SALES_UI_H
#include "Main_ui.h"
#include "Toppings.h"
#include "Pizza.h"
#include "Order.h"
#include <sstream>

class Sales_ui
{
    public:
        void salesMainUI();
        Pizza addPizza();
        Toppings addExtras();
        void viewOrderTotal(Order takeOrder);

    private:
};

#endif // SALES_UI_H
