#include "Manager_ui.h"

void Manager_ui::managerMainUI(){
    char input = '\0';


    while(true) {
        cout << "| -Manager Main Menu- " << endl;
        cout << "| 1. Pizza management " << endl;
        cout << "| 2. Toppings management" << endl;
        cout << "| 3. Extra management" << endl;
        cout << "| 4. Location management" << endl;
        cout << "| 5. Pricing management" << endl;
        cout << "| 6. To exit to Main menu" << endl;
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
            cout << "Invalid input - try again" << endl;
            system("pause");
        }
    }
}

void Manager_ui::managePizzaUI() {
    cout << " -Manager - Pizza management- " << endl;
}

void Manager_ui::manageToppingUI() {
    char input = '\0';

    while(true) {
        cout << " -Manager - Toppings management- " << endl;
        cout << "|  " << endl;
        cout << "| 1. Input new topping " << endl;
        cout << "| 2. Remove topping" << endl;
        cout << "| 3. Back to Manager main menu" << endl;
        cin >> input;

        if(input == '1') {
            cout << "*write topping to topping list" << endl;
            cin >> input;
        }
        else if(input == '2'){
            cout << "**remove topping from a list" << endl;
            cin >> input;
        }
        else if(input == '3') {
            system("cls");
            break;
        }
        else {
            cout << "Invalid input - try again" << endl;
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
