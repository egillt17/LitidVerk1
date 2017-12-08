#include <iostream>
<<<<<<< HEAD
#include "Main_ui.h"

=======
#include "Display.h"
#include "Manager.h"
#include "Sales.h"
#include "Baker.h"
#include "Delivery.h"
#include "Pizza.h"
#include "Order.h"
#include "Toppings.h"
>>>>>>> a1eef8c7b80988e56b05313cce19a0c285080108

using namespace std;

int main()
{
<<<<<<< HEAD
    Main_ui mainUI;
    mainUI.customerOrStaff();
=======

    Display mainUI;
    mainUI.displayMainUI();

    Pizza lala;
    Pizza grgr;
    lala = lala.make_pizza();
    grgr = grgr.make_pizza();
    system("CLS");
    cout << "This is your order: " << endl;
    cout << lala;
    cout << grgr;
>>>>>>> a1eef8c7b80988e56b05313cce19a0c285080108

    return 0;
}
