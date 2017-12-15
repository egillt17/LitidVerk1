 #include "Sales_ui.h"
 #include <string>


void Sales_ui::salesMainUI()
{
    char answer = '\0';
    string input = "";
    Order takeOrder;
    PizzaService get;
    Pizza pizza;
    Toppings extras;
    int pizzaPrice = 0;
    int extrasPrice = 0;
    int orderPrice = 0;

    while (true)
    {
        system("CLS");
        vector <Pizza> orderPizzas = takeOrder.getPizzas();         ///checking if the order consists of 2 pizzas and 1 extra, af if so then the extra is free
        vector <Toppings> orderExtras = takeOrder.getExtras();      ///Because of the special offer that is available
        if (orderPizzas.size() == 2 && orderExtras.size() == 1) {
            extrasPrice = 0;
            cout << "Whammy! you ordered two pizzas and 1 extra which means the extra is free! " << endl;
        }
        orderPrice = pizzaPrice + extrasPrice;
        takeOrder.setPrice(orderPrice);
        cout << "                Sales Main Menu                " << endl;
        cout << "------------------------------------------------" << endl;
        cout << "| What would you like to do? " << endl;
        cout << "| '1' to set name on order" << endl;
        cout << "| '2' to add pizza to the order" << endl;
        cout << "| '3' to add extras to the order" << endl;
        cout << "| '4' to set order settings" << endl;
        cout << "| '5' to Add comments" << endl;
        cout << "| '6' to Commit Order" << endl;
        cout << "| '7' to Quit" << endl << "| " << endl;
        cout << "| (order 2 pizzas and 1 extra to get the extra free!)" << endl;
        cout << "|-----------------------------------------------" << endl;
        cout << "|" << endl;
        cout << "|           Current Order: " << endl;
        viewOrderTotal(takeOrder);
        cout << "|" << endl;
        cout << "| Input: ";
        cin >> answer;

        if (answer == '1') {                                        ///Pretty straightforward if / else commands here
            cout << "| Please enter a name for the order" << endl;
            cout << "| Name: ";
            cin.ignore();
            getline(cin, input);
            takeOrder.setPerson(input);
        }
        else if (answer == '2') {

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
            setOrderSettings(takeOrder);
        }
        else if (answer == '6') {
            if(!takeOrder.getPerson().compare("Unknown") || !takeOrder.getLocation().compare("Unknown")) {
                cout << "| To commit an order you have to set a name to the order" << endl;
                cout << "| and pick a location" << endl;
                system("pause");
            }
            else {
                if(takeOrder.getExtras().empty() && takeOrder.getPizzas().empty()) {
                    cout << "| To commit an order you have to add either a pizza or an extra" << endl;
                    system("pause");
                }
                else {
                get.addOrder(takeOrder);
                takeOrder.clearOrder(takeOrder);
                }
            }
        }
        else if (answer == '5') {
            cout << "| Comment: ";
            cin.ignore();
            getline(cin, input);            ///cin.ignore() is used to ba able to send a getline() to the setComments function in the Order class
            takeOrder.setComments(input);
        }
        else if (answer == '7') {
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

    PizzaService getSpecial;
    vector<Pizza> pizza_special = getSpecial.getPizzaSpecials();
    TopService get;
    Pizza pizza;
    vector <Toppings> topping;
    while(true){
        system("CLS");
        int totalPrice = sizePrice + saucePrice + crustPrice + toppingPrice;            ///Keeps the total price updated before displaying it
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
        cout << "| '6' choose special pizza" << endl;
        cout << "| '7' Done" << endl;
        cout << "| Input : ";
        cin >> input;
        if (input == '1') {
            topping = get.getToppingList(3);
            cout << "                 -Size list-                    " << endl;
            cout << "------------------------------------------------" << endl;
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << (i+1) << ". " << topping[i];
            }
            cout << "| Pick a size: ";
            cin >> answer;
            stringstream sin(answer);                   ///Stringstream changes the char answer into the int number so we can compare it to the topping.size() number
            sin >> number;                              ///in the if / else statement, we do this so the user can only interact with the exact size of the array
            if(number > 0 && number <= topping.size()) {
                pizza.setSize(topping[number-1].getName());         ///Also updates the price of the size varialbe
                sizePrice = topping[number-1].getPrice();
            }
            else {
                cout << "| no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '2') {
            topping = get.getToppingList(4);
            cout << "                -Sauce list-                    " << endl;
            cout << "------------------------------------------------" << endl;
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << (i+1) << ". " << topping[i];
            }
            cout << "| Pick a sauce: ";
            cin >> answer;
            stringstream sin(answer);                   ///Works the same way as the chunk of code above but instead changes the sauce and it's price
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.setSauce(topping[number-1].getName());
                saucePrice = topping[number-1].getPrice();
            }
            else {
                cout << "| no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '3') {
            topping = get.getToppingList(2);
            cout << "                -Crust list-                    " << endl;
            cout << "------------------------------------------------" << endl;
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << (i+1) << ". " << topping[i];
            }
            cout << "| Pick a crust: ";
            cin >> answer;
            stringstream sin(answer);                   ///Works the same way as the chunk of code above but instead changes the crust and it's price
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.setCrust(topping[number-1].getName());
                crustPrice = topping[number-1].getPrice();
            }
            else {
                cout << "| no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '4') {
            topping = get.getToppingList(1);
            cout << "                -Toppings list-                 " << endl;
            cout << "------------------------------------------------" << endl;
            for(unsigned int i = 0; i < topping.size(); i++) {
                cout << "| " << (i+1) << ". " << topping[i];
            }
            cout << "| Pick a Topping: ";
            cin >> answer;
            stringstream sin(answer);                   ///Works the same way as the chunk of code above but instead changes the toppings variable and it's price
            sin >> number;
            if(number > 0 && number <= topping.size()){
                pizza.addTopping(topping[number-1]);
                toppingPrice = pizza.getToppingPrice();
            }
            else {
                cout << "| no can do!" << endl;
                system("pause");
            }
        }
        else if (input == '5') {
            pizza.clearTopping();                       ///Resets all toppings on the pizza
            toppingPrice = pizza.getToppingPrice();
        }
        else if (input == '6') {
            string inputNum = "";
            unsigned int number;
            for(unsigned int i = 0; i < pizza_special.size();i++) {
                cout << "|      Pizza number: " << (i+1) << endl;
                cout << pizza_special[i];
            }
            cout << "| Choose Pizza number: ";
            cin >> inputNum;
            stringstream sin(inputNum);
            sin >> number;
            if(number <= pizza_special.size() && number > 0){
                pizza = pizza_special[number-1];
                cout << "| Special pizza added" << endl;
                cout << "| ";
                system("pause");
                break;
            }
            if(number > pizza_special.size() || number <= 0){
                cout << "| Invalid Input" << endl;
                cout << "| ";
                system("PAUSE");
            }
        }
        else if (input == '7') {
            if(!pizza.getSize().compare("Not picked")) {
                cout << "| You have to pick a size to add the pizza" << endl;     ///The program only allows the user to create the pizza if the size of the pizza is chosen
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
    vector <Toppings> topping;                                      ///Menu for the extras
    TopService get;
    topping = get.getToppingList(5);
    cout << "                Extras menu                " << endl;
    cout << "------------------------------------------------" << endl;
    cout << endl;
    for(unsigned int i = 0; i < topping.size(); i++) {
        if (i < 9) {                                               ///Displays all extras in the vector toppings (We chose to make all extras a part of the toppings class)
            cout << "| " << (i+1) << ". " << " " << topping[i];
        }
        else {
            cout << "| " << (i+1) << ". " << topping[i];
        }
    }
    cout << "| " << (topping.size()+1) << ". to Exit" << endl;
    cout << "| Pick an extra: ";
    cin >> answer;
    stringstream sin(answer);                                           ///Changes the char answer to the int number to compare it like the code above
    unsigned int number = 0;
    sin >> number;
    if(number > 0 && number <= topping.size()){
        extras = topping[number-1];                 ///Sets the extra that was choosen to the extras variable
    }
    else if (number == topping.size()+1) {
        system("CLS");
        salesMainUI();
    }
    else {
        cout << "| no can do!" << endl;
        system("pause");
    }


    return extras;
}

void Sales_ui::viewOrderTotal(Order takeOrder) {
    cout << "| " << takeOrder;      ///Displays the order, with everything there is to know about that order
}

void Sales_ui::setOrderSettings(Order& order) {
    PizzaService get;
    vector <string> locations;
    string answer = "";
    char input;
    while(true) {
        cout << "                       Order Settings menu                " << endl;
        cout << "----------------------------------------------------------" << endl;
        cout << "|      What would you like to do? " << endl;
        cout << "|      '1' set location" << endl;
        cout << "|      '2' set picked up or sent" << endl;
        cout << "|      '3' set paid status" << endl;
        cout << "|      pick a number: ";
        cin >> input;

        if(input == '1') {
            locations = get.getLocation();
            for(unsigned int i = 0; i < locations.size(); i++) {
            cout << "|          " << (i+1) << ". " << locations[i] << endl;
            }
            cout << "|          Pick an Location: ";
            cin >> answer;
            stringstream sin(answer);                   ///Changing string to int, to compare it with the size of the vector locations
            unsigned int number = 0;
            sin >> number;
            if(number > 0 && number <= locations.size()){
                order.setLocationForOrder(locations[number-1]);
                break;
            }
            else {
                cout << "| Invalid Input" << endl;
                cout << "| ";
                system("pause");
                break;
            }
        }
        else if(input == '2') {
            cout << "|          '1' for picked up" << endl;
            cout << "|          '2' for sent" << endl;
            cout << "|          pick a number: ";
            cin >> answer;
            stringstream sin(answer);                   ///Same stringstream usage as before, only now to compare the number to integers
            unsigned int number = 0;
            sin >> number;
            if(number == 1) {
                order.setPickedOrSent('p');
                break;
            }
            else if(number == 2) {
                order.setPickedOrSent('d');
                break;
            }
            else {
                cout << "| Invalid input" << endl;
                system("pause");
                break;
            }
        }
        else if(input == '3') {
            cout << "|          '1' for paid" << endl;
            cout << "|          '2' for not paid" << endl;
            cout << "|          pick a number: ";
            cin >> answer;
            stringstream sin(answer);
            unsigned int number = 0;
            sin >> number;
            if(number == 1) {
                order.setPaidFor('p');
                break;
            }
            else if(number == 2) {
                order.setPaidFor('n');
                break;
            }
            else {
                cout << "| Invalid input!" << endl;
                cout << "| ";
                system("pause");
                break;
            }
        }
        else {
            cout << "| Invalid Input " << endl;
            cout << "| ";
            system("pause");
            break;
        }
    }
}
