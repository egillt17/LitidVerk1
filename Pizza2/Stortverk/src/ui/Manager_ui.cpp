#include "Manager_ui.h"

void Manager_ui::managerMainUI(){
    char input = '\0';


    while(true) {
        cout << "               Manager Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' for Pizza management " << endl;
        cout << "| '2' for Toppings management" << endl;
        cout << "| '3' for Extra management" << endl;
        cout << "| '4' for Location management" << endl;
        cout << "| '5' for Pricing management" << endl;
        cout << "| '6' to exit to the Main menu" << endl;
        cin >> input;

        if(input == '1') {
            system("cls");
            managePizzaUI();
        }
        else if(input == '2'){
            system("cls");
            manageToppingUI();
        }
        else if(input == '3') {
            system("cls");
            manageExtraUI();
        }
        else if(input == '4') {
            system("cls");
            manageLocationUI();
        }
        else if(input == '5') {
            system("cls");
            managePriceUI();
        }
        else if(input == '6') {
            system("cls");
            break;
        }
        else {
            system("cls");
            cout << "Wrong input, please try again" << endl << endl;
            system("pause");
        }
    }
}

void Manager_ui::managePizzaUI() {
    cout << " -Manager - Pizza management- " << endl;
}

void Manager_ui::manageToppingUI() {
    char input = '\0';
    TopService get;
    vector <Toppings> topping;

    while(true) {
        cout << " -Manager - Toppings management- " << endl;
        cout << "|  " << endl;
        cout << "| 1. Display topping list " << endl;
        cout << "| 2. Input new topping to list" << endl;
        cout << "| 3. Remove topping from list" << endl;
        cout << "| 4. Back to Manager main menu" << endl;
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << "Display topping list" << endl;
            topping = get.getToppingList();
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i];
            }
            system("pause");
            system("cls");

        }
        else if(input == '2'){
            cout << "Input new toppping" << endl;
            //get.addTopping()
        }
        else if(input == '3'){
            cout << "Remove topping from list" << endl;
            string lala;
            cin >> lala;
            if(!get.removeTopping(lala)) {
                cout << "no can do!" << endl;
                system("pause");
            }
            system("cls");
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "Wrong input, please try again" << endl << endl;
        }
    }
}

void Manager_ui::manageExtraUI(){
    cout << " -Manager - Extra management- " << endl;
}

void Manager_ui::manageLocationUI(){
    cout << " -Manager - Location management- " << endl;
}

void Manager_ui::managePriceUI() {
    cout << " -Manager - Pricing management- " << endl;
}
