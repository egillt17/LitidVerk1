 #include "Sales_ui.h"

void Sales_ui::salesMainUI()
{
    char answer = '\0';
    string input = "";
    Order takeOrder;
    Pizza pizza;
    Toppings extras;
    int pizzaPrice = 0;
    int extrasPrice = 0;

    while (true)
    {
        int orderPrice = pizzaPrice + extrasPrice;
        takeOrder.setPrice(orderPrice);
        system("CLS");
        cout << "                Sales Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' to set up a new order" << endl;
        cout << "| '2' to add pizza to the order" << endl;
        cout << "| '3' to add extras to the order" << endl;
        cout << "| '4' to view total of an order" << endl;
        cout << "| '5' to set an order picked up or sent" << endl;
        cout << "| '6' to mark an order paid for" << endl;
        cout << "| '7' to mark a pizza to a specific delivery place" << endl;
        cout << "| '8' to  Add comments" << endl;
        cout << "| '9' to Quit" << endl;

        cin >> answer;
        cout << endl;

        if (answer == '1') {
            system("CLS");
            cout << "---Setting up a new order---" << endl;
            cout << "| Name: ";
            cin.ignore();
            getline(cin, input);
            takeOrder.setPerson(input);
        }
        else if (answer == '2') {
            system("CLS");
            pizza = addPizza();
            takeOrder.addPizza(pizza);
            pizzaPrice = takeOrder.getPizzaTotalCost();
        }
        else if (answer == '3') {
            extras = addExtras();
            if(extras.getName().compare("")) {
                takeOrder.addExtras(extras);
                extrasPrice = takeOrder.getExtrasTotalCost();
            }
        }
        else if (answer == '4') {
            system("CLS");
            cout << "---Getting the total cost of an order---" << endl;
            viewOrderTotal(takeOrder);
        }
        else if (answer == '5') {
            system("CLS");
            char answer = '\0';
            while (true) {
                cout << "---setting an order picked up or sent---" << endl;
                cout << "| Do you want the order picked up or sent? ('p' for picked up, 's' for sent)";
                cin >> answer;
                if (answer == 'p' || answer == 's') {
                    Order order;
                    order.setPickedOrSent(answer);
                    break;
                }
                else {
                    cout << "| Wrong input, please try again" << endl;
                }
            }
        }
        else if (answer == '6') {
            system("CLS");
            cout << "---Marking an order paid for---" << endl;
            Order order;
            order.setPaidFor('y');
        }
        else if (answer == '7') {
            system("CLS");
            cout << "---Marking a pizza to a specific delivery place---" << endl;
            Order order;
            order.setLocationForOrder("SpecificDeliveryPlace");
        }
        else if (answer == '8') {
            system("CLS");
            cout << "---Adding comments---" << endl;
            cout << "| Comment: ";
            cin.ignore();
            getline(cin, input);
            Order order;
            order.setComments(input);
        }
        else if (answer == '9') {
            system("CLS");
            break;
        }
        else {
            system("CLS");
            cout << "| Wrong input, please try again" << endl << endl;
        }
    }
}

Pizza Sales_ui::addPizza() {
    string answer = "";
    char input = '0';
    unsigned int number = 0;
    int sizePrice = 0;
    int saucePrice = 0;
    int crustPrice = 0;
    int toppingPrice = 0;

    TopService get;
    Pizza pizza;
    vector <Toppings> topping;
    while(true){
        system("CLS");
        int totalPrice = sizePrice + saucePrice + crustPrice + toppingPrice;
        pizza.setPrice(totalPrice);
        topping.clear();
        cout << "                Your pizza                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << pizza;
        cout << "                Pizza menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' set size" << endl;
        cout << "| '2' set sauce" << endl;
        cout << "| '3' set crust" << endl;
        cout << "| '4' add topping" << endl;
        cout << "| '5' clear toppings" << endl;
        cout << "| '6' Done" << endl;

        cin >> input;
        if (input == '1') {
            system("CLS");
            topping = get.getToppingList(3);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a size: ";
            cin >> answer;
            stringstream sin(answer);
            sin >> number;
            if(number > 0 && number <= topping.size()) {
                pizza.setSize(topping[number-1].getName());
                sizePrice = topping[number-1].getPrice();
            }
            else {
                cout << "no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '2') {
            system("CLS");
            topping = get.getToppingList(4);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a sauce: ";
            cin >> answer;
            stringstream sin(answer);
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.setSauce(topping[number-1].getName());
                saucePrice = topping[number-1].getPrice();
            }
            else {
                cout << "no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '3') {
            system("CLS");
            topping = get.getToppingList(2);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a crust: ";
            cin >> answer;
            stringstream sin(answer);
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.setCrust(topping[number-1].getName());
                crustPrice = topping[number-1].getPrice();
            }
            else {
                cout << "no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '4') {
            system("CLS");
            topping = get.getToppingList(1);
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << (i+1) << ". " << topping[i];
            }
            cout << "Pick a Topping: ";
            cin >> answer;
            stringstream sin(answer);
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.addTopping(topping[number-1]);
                toppingPrice = pizza.getToppingPrice();
            }
            else {
                cout << "no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '5') {
            pizza.clearTopping();
            toppingPrice = pizza.getToppingPrice();
        }
        else if (input == '6') {
            if(!pizza.getSize().compare("Not picked")) {
                cout << "You have to pick a size to add the pizza" << endl;
                system("pause");
            }
            else {
                break;
            }
        }
    }

    return pizza;
}

Toppings Sales_ui::addExtras() {
    Toppings extras;
    string answer = "";
    vector <Toppings> topping;
    TopService get;
    system("CLS");
    topping = get.getToppingList(5);
    cout << "                Extras menu                " << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl;
    for(unsigned int i = 0; i < topping.size(); i++) {
        cout << (i+1) << ". " << topping[i];
    }
    cout << "Pick an extra: ";
    cin >> answer;
    stringstream sin(answer);
    unsigned int number = 0;
    sin >> number;
    if(number > 0 && number <= topping.size()){
        extras = topping[number-1];
    }
    else {
        cout << "no can do!" << endl;
        system("pause");
    }


    return extras;
}

void Sales_ui::viewOrderTotal(Order takeOrder) {
    cout << takeOrder;
    system("pause");
}
