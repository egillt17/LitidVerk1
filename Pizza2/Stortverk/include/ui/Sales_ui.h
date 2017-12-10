#ifndef SALES_UI_H
#define SALES_UI_H
#include "Main_ui.h"
#include "Toppings.h"
#include "Pizza.h"

class Sales_ui
{
    public:
        void salesMainUI();
        Pizza addPizza();
        Toppings addToppings();
        Toppings addExtras();

    private:
};

#endif // SALES_UI_H
