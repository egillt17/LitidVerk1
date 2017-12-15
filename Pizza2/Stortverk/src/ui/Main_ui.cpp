#include "Main_ui.h"


void Main_ui::mainUI() {

    char input = '\0';

    while (true) {
        cout << "                   Main menu                    " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What is your role? " << endl;
        cout << "| '1' for Manager," << endl << "| '2' for Sales Person, " << endl << "| '3' for Baker, " << endl
             << "| '4' for Delivery person, " << endl << "| '5' to Quit " << endl;
        cout << "| Input: ";
        cin >> input;

        if (input == '1') {
            system("CLS");
            Manager_ui managerUI;
            managerUI.managerMainUI();
        }
        else if (input == '2') {
            system("CLS");
            Sales_ui salesUI;
            salesUI.salesMainUI();
        }
        else if (input == '3') {
            system("CLS");
            Baker_ui bakerUI;
            bakerUI.bakerMainUI();
        }
        else if (input == '4') {
            system("CLS");
            Delivery_ui deliveryUI;
            deliveryUI.deliveryMainUI();
        }
        else if (input == '5') {
            system("CLS");
            cout << "| Exiting" << endl << endl;
            break;
        }
        else {
            system("CLS");
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}
