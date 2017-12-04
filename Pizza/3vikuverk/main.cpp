#include <iostream>
#include "Display.h"
#include "Manager.h"
#include "Sales.h"
#include "Baker.h"
#include "Delivery.h"
#include "Pizza.h"
#include "Order.h"
#include "Toppings.h"

using namespace std;

int main()
{

    Display mainUI;
    mainUI.displayMainUI();

    Pizza lala;
    lala = lala.make_pizza();
    system("CLS");
    cout << "This is your pizza: " << endl;
    cout << lala;

    return 0;
}
