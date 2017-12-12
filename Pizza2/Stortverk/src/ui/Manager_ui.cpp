#include "Manager_ui.h"

enum Pick {toppings = 1, crust, sizes, sauce, extra};

void Manager_ui::managerMainUI(){
    char input = '\0';


    while(true) {
        cout << endl;
        cout << "               Manager Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' for Pizza specials management " << endl;
        cout << "| '2' for Toppings management" << endl;
        cout << "| '3' for Extra management" << endl;
        cout << "| '4' for Location management" << endl;
        cout << "| '5' for Crust, Sauce and Size management" << endl;
        cout << "| '6' to exit to the Main menu" << endl;
        cout << "| Input : ";
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
            cout << "| Wrong input, please try again" << endl;
            cout << "| ";
            system("pause");
            system("cls");
        }
    }
}

void Manager_ui::managePizzaUI() {
    cout << " -Manager - Pizza management- " << endl;
}

void Manager_ui::manageToppingUI() {
    char input = '\0';
    TopService get;
    Validate validate;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << endl;
        cout << "         -Manager - Toppings management-        " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display topping list " << endl;
        cout << "| '2' Input new topping to list" << endl;
        cout << "| '3' Remove topping from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "             -Display topping list-        " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(1);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << topping[i];
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        else if(input == '2'){
            while(true) {
                system("cls");
                cout << endl;
                cout << "              -Input new topping-               " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Name: ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    cout << "| Price: ";
                    cin >> price;
                    try {
                        validate.validateNum(price);
                        get.addTopping(top, price, 1);
                        break;
                    }
                    catch(InvalidNumExceptions e) {
                        cout << e.getMessage() << endl;
                        
                    }
                }
                catch(InvalidNameException e) {
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3'){
            while(true){
                system("cls");
                cout << endl;
                cout << "           -Remove topping from list-         " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(1);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << topping[i];
                }
                cout << "| " << endl;
                cout << "| What topping would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    if(!get.removeTopping(top, 1)) {
                        cout << "| Topping not found!" << endl;
                        cout << "| ";
                        system("pause");
                        break;
                    }
                    cout << "| Successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidNameException e) {
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

void Manager_ui::manageExtraUI(){
    char input = '\0';
    TopService get;
    Validate validate;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << endl;
        cout << "          -Manager - Extras management-         " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display extras list " << endl;
        cout << "| '2' Input new extras to list" << endl;
        cout << "| '3' Remove extras from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "             -Display extras list-              " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(extra);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << topping[i];
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        else if(input == '2'){
            while(true) {
                system("cls");
                cout << endl;
                cout << "              -Input new extras-                " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Name: ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    cout << "| Price: ";
                    cin >> price;
                    try {
                       validate.validateNum(price);
                        get.addTopping(top, price, extra);
                        break;
                    }
                    catch(InvalidNumExceptions e){
                        
                        cout << e.getMessage() << endl;
                    }
                }
                catch(InvalidNameException e){                    
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3'){
            while(true){
                system("cls");
                cout << endl;
                cout << "            -Remove extras from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| " << endl;
                topping = get.getToppingList(extra);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| " << topping[i];
                }
                cout << "| " << endl;
                cout << "| What extras would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    if(!get.removeTopping(top, extra)) {
                        cout << "| Extra not found" << endl;
                        cout << "| ";
                        system("pause");
                        break;
                    }
                }
                catch(InvalidNameException e){
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                cout << "| Successfully removed" << endl;
                cout << "| ";
                system("pause");
                break;
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

void Manager_ui::manageLocationUI(){
    char input = '\0';
     PizzaService get;
     Validate validate;
    vector <string> locations;
    string location;

    while(true) {
        system("cls");
        cout << endl;
        cout << "         -Manager - Location management-        " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| '1' Display locations list " << endl;
        cout << "| '2' Input new locations to list" << endl;
        cout << "| '3' Remove locations from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        if(input == '1') {
            system("cls");
            cout << endl;
            cout << "            -Display locations list-            " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "|" << endl;
            locations = get.getLocation();
            for(unsigned int i = 0; i < locations.size(); i++) {
                cout << "| Address " << i+1 << ": " << locations[i] << endl;
            }
            cout << "|" << endl;
            cout << "| ";
            system("pause");
        }
        else if(input == '2'){
            while(true){
                system("cls");
                cout << endl;
                cout << "             -Input new locations-              " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "| Input location and address number" << endl;
                cout << "| Or input location only" << endl;
                cout << "| " << endl;
                cout << "| Address: ";
                cin.ignore();
                getline(cin, location);
                try {
                    validate.validateLocation(location);
                    get.addLocation(location);
                    cout << "| Location succesfully added" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidLocationException e){
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3'){
            while(true){
                system("cls");
                cout << endl;
                cout << "          -Remove location from list-           " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" << endl;
                locations = get.getLocation();
                for(unsigned int i = 0; i < locations.size(); i++) {
                    cout << "| Address " << i+1 << ": " << locations[i] << endl;
                }
                cout << "|" << endl;
                cout << "| What location would you like to remove? ";
                cin.ignore();
                getline(cin, location);
                try {
                    validate.validateLocation(location);
                    if(!get.removeLocation(location)) {
                        cout << "| Location not found" << endl;
                        cout << "| ";
                        system("pause");
                        break;
                    }
                    cout << "| Location successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
                catch(InvalidLocationException e) {
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            system("cls");
            break;
        }
        else {
            cout << "| Wrong input, please try again" << endl << endl;
            cout << "| ";
            system("pause");
        }
    }
}

void Manager_ui::manageSettingUI() {
    char input = '\0';
    int pick = 0;
    Validate validate;
    TopService get;
    vector <Toppings> topping;
    string top = "";
    string price = "";

    while(true) {
        system("cls");
        cout << endl;
        cout << "   -Manager - Crust, Sauce and Size management- " << endl;
        cout << "-------------------------------------------------" << endl;
        cout << "|  " << endl;
        cout << "| '1' Display list " << endl;
        cout << "| '2' Input new item to list" << endl;
        cout << "| '3' Remove item from list" << endl;
        cout << "| '4' Back to Manager main menu" << endl;
        cout << "| Input : ";
        cin >> input;

        if(input == '1') {
            system("cls");
            pick = crustSauceSize();
            cout << endl;
            cout << "                -Display list-                  " << endl;
            cout << "------------------------------------------------" << endl;
            cout << "| " << endl;
            topping = get.getToppingList(pick);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << topping[i];
            }
            cout << "| " << endl;
            cout << "| ";
            system("pause");
        }
        else if(input == '2'){
            while(true){
                system("cls");
                pick = crustSauceSize(); // 2 - crust 4 - sauce 3 - size
                string name[5] = {"", "", "crust", "size", "sauce"};
                system("cls");
                cout << endl;
                cout << "               -Input new " << name[pick] << "-"<< endl;
                cout << "------------------------------------------------" << endl;
                cout << "|Name : ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    cout << "| Price: ";
                    cin >> price;
                    try {
                        validate.validateNum(price);
                        get.addTopping(top, price, pick);
                        cout << "| " << name[pick] << " successfully added" << endl;
                        cout << "| ";
                        system("pause");
                        break;
                    }
                    catch (InvalidNumExceptions e){
                        cout << e.getMessage() << endl;
                        break;
                    }
                }
                catch (InvalidNameException e){
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '3'){
            while(true) {
                system("cls");
                pick = crustSauceSize();
                system("cls");
                cout << endl;
                cout << "            -Remove item from list-             " << endl;
                cout << "------------------------------------------------" << endl;
                cout << "|" <<  endl;
                topping = get.getToppingList(pick);
                for(unsigned int i = 0; i < topping.size(); i++) {
                    cout << "| Name: " << topping[i]; 
                }
                cout << "|" << endl;
                cout << "| What item would you like to remove? ";
                cin.ignore();
                getline(cin, top);
                try {
                    validate.validateName(top);
                    if(!get.removeTopping(top, pick)) {
                        cout << "| Item not found" << endl;
                        system("pause");
                    }
                    cout << "| Item successfully removed" << endl;
                    cout << "| ";
                    system("pause");
                    break;  
                }
                catch(InvalidNameException e) {
                    cout << e.getMessage() << endl;
                    cout << "| ";
                    system("pause");
                    break;
                }
            }
        }
        else if(input == '4') {
            //system("cls");
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
        cout << endl;
        cout << "      -Which one would you like to manage?-     " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "|  " << endl;
        cout << "| 1. Crust" << endl;
        cout << "| 2. Sauce" << endl;
        cout << "| 3. Size" << endl;
        cout << "| " << endl;
        cout << "| Input : ";
        cin.ignore();
        cin >> input;

        if(input == '1') {
            pick = 2;
            system("cls");
            break;
        }
        else if(input == '2') {
            pick = 4;
            system("cls");
            break;
        }
        else if(input == '3') {
            pick = 3;
            system("cls");
            break;
        }
        else {
            cout << "Wrong input, please try again" << endl;
        }
    }
    //system("cls");
    return pick;
}
