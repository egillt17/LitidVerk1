#include "Manager_ui.h"

void Manager_ui::managerMainUI(){
    char input = '\0';


    while(true) {
        cout << "               Manager Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' for Pizza specials management " << endl;
        cout << "| '2' for Toppings management" << endl;
        cout << "| '3' for Extra management" << endl;
        cout << "| '4' for Location management" << endl;
        cout << "| '5' for Crust, Sauce and Size management" << endl;
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
            manageSettingUI();
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
    string top = "";
    string price = "";

    while(true) {
        system("cls");
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
            topping = get.getToppingList(1);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i];
            }
            system("pause");

        }
        else if(input == '2'){
            cout << "Input new topping" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, top);
            cout << "Price: ";
            cin >> price;
            get.addTopping(top, price, 1);
        }
        else if(input == '3'){
            cout << "Remove topping from list" << endl;
            cout << "What topping would you like to remove? ";
            cin.ignore();
            getline(cin, top);
            if(!get.removeTopping(top, 1)) {
                cout << "no can do!" << endl;
                system("pause");
            }
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
        char input = '\0';
    TopService get;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << " -Manager - Extras management- " << endl;
        cout << "|  " << endl;
        cout << "| 1. Display extras list " << endl;
        cout << "| 2. Input new extras to list" << endl;
        cout << "| 3. Remove extras from list" << endl;
        cout << "| 4. Back to Manager main menu" << endl;
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << "Display extras list" << endl;
            topping = get.getToppingList(5);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i];
            }
            system("pause");

        }
        else if(input == '2'){
            cout << "Input new extras" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, top);
            cout << "Price: ";
            cin >> price;
            get.addTopping(top, price, 5);
        }
        else if(input == '3'){
            cout << "Remove extras from list" << endl;
            cout << "What extras would you like to remove? ";
            cin.ignore();
            getline(cin, top);
            if(!get.removeTopping(top, 5)) {
                cout << "no can do!" << endl;
                system("pause");
            }
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

void Manager_ui::manageLocationUI(){
    char input = '\0';
     PizzaService get;
    vector <string> locations;
    string location;

    while(true) {
        system("cls");
        cout << " -Manager - Location management- " << endl;
        cout << "|  " << endl;
        cout << "| 1. Display locations list " << endl;
        cout << "| 2. Input new locations to list" << endl;
        cout << "| 3. Remove locations from list" << endl;
        cout << "| 4. Back to Manager main menu" << endl;
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << "Display locations list" << endl;
            locations = get.getLocation();
            for(unsigned int i = 0; i < locations.size(); i++) {
                cout << locations[i] << endl;
            }
            system("pause");

        }
        else if(input == '2'){
            cout << "Input new locations" << endl;
            cin.ignore();
            getline(cin, location);
            get.addLocation(location);

        }
        else if(input == '3'){
            cout << "Remove location from list" << endl;
            cout << "What location would you like to remove? ";
            cin.ignore();
            getline(cin, location);
            if(!get.removeLocation(location)) {
                cout << "no can do!" << endl;
                system("pause");
            }
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

void Manager_ui::manageSettingUI() {
    char input = '\0';
    int pick = 0;
    TopService get;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << " -Manager - Crust, Sauce and Size management- " << endl;
        cout << "|  " << endl;
        cout << "| 1. Display list " << endl;
        cout << "| 2. Input new item to list" << endl;
        cout << "| 3. Remove item from list" << endl;
        cout << "| 4. Back to Manager main menu" << endl;
        cin >> input;

        if(input == '1') {
            system("cls");
            pick = crustSauceSize();
            cout << "Display list" << endl;
            topping = get.getToppingList(pick);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << topping[i];
            }
            system("pause");

        }
        else if(input == '2'){
            pick = crustSauceSize();
            cout << "Input new item" << endl;
            cout << "Name: ";
            cin.ignore();
            getline(cin, top);
            cout << "Price: ";
            cin >> price;
            get.addTopping(top, price, pick);
        }
        else if(input == '3'){
            pick = crustSauceSize();
            cout << "Remove item from list" << endl;
            cout << "What item would you like to remove? ";
            cin.ignore();
            getline(cin, top);
            if(!get.removeTopping(top, pick)) {
                cout << "no can do!" << endl;
                system("pause");
            }
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

int Manager_ui::crustSauceSize() {
    char input = '0';
    int pick = 0;
        while(true) {
        cout << "Which one would you like to manage?" << endl;
        cout << "|  " << endl;
        cout << "| 1. Crust" << endl;
        cout << "| 2. Sauce" << endl;
        cout << "| 3. Size" << endl;
        cin >> input;

        if(input == '1') {
            pick = 2;
            break;
        }
        else if(input == '2') {
            pick = 4;
            break;
        }
        else if(input == '3') {
            pick = 3;
            break;
        }
        else {
            cout << "Wrong input, please try again" << endl;
        }
    }
    system("cls");
    return pick;
}
