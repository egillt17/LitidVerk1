#include "Main_ui.h"
#include <iostream>
#include <stdlib.h>
//#include "Manager_ui"
using namespace std;

Main_ui::Main_ui()
{
    //ctor
}

void Main_ui::customerOrStaff()
{
    char input = '\0';

    while (true) {
        cout << "                   Main menu                    " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "Hello! Are you a costomer or staff member?      " << endl;
        cout << "1 for Customer, 2 for staff, 3 to Quit          " << endl;
        cin >> input;

        if (input == '1') {
            system("CLS");
            customerMainUI();
        }
        else if (input == '2') {
            system("CLS");
            staffMainUI();
        }
        else if (input == '3') {
            cout << "Exiting" << endl;
            break;
        }
        else {
            cout << "Wrong input, please try again" << endl;
        }
    }
}

void Main_ui::customerMainUI() {

    char input = '\0';

    while (true) {
        cout << "                Customer Main UI                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "What would you like to order? " << endl;
        cout << "1 for Pizza, 2 for Side dishes, 3 for Beverages, 4 to Quit " << endl;
        cin >> input;

        if (input == '1') {
            system("CLS");
            cout << "order Pizza" << endl;
            //orderPizza();
        }
        else if (input == '2') {
            system("CLS");
            cout << "order Sides" << endl;
            //orderSides();
        }
        else if (input == '3') {
            system("CLS");
            cout << "order Drikns" << endl;
            //orderDrinks();
        }
        else if (input == '4') {
            system("CLS");
            cout << "Exiting" << endl;
            break;
        }
        else {
            system("CLS");
            cout << "Wrong input, please try again" << endl;
        }
    }
}

void Main_ui::staffMainUI() {

    char input = '\0';

    while (true) {
        cout << "                 Staff Main UI                  " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "What is your role? " << endl;
        cout << "1 for Manager, 2 for Sales Person, 3 for Baker, " << endl
             << "4 for Delivery person, 5 to Quit " << endl;
        cin >> input;

        if (input == '1') {
            system("CLS");
            cout << "Manager" << endl;
            Manager_ui managerUI;
            managerUI.managerMainUI();
        }
        else if (input == '2') {
            system("CLS");
            cout << "Sales Person" << endl;
            //salesMainUI();
        }
        else if (input == '3') {
            system("CLS");
            cout << "Baker" << endl;
            //bakerMainUI();
        }
        else if (input == '4') {
            system("CLS");
            cout << "Delivery Person" << endl;
            //deliveryMainUI();
        }
        else if (input == '5') {
            system("CLS");
            cout << "Exiting" << endl;
            break;
        }
        else {
            system("CLS");
            cout << "Wrong input, please try again" << endl;
        }
    }
}
