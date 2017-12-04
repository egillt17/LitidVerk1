#include "Order.h"

Order::Order()
{
    //ctor
}

Order::~Order()
{
    //dtor
}

void take_order(){
    char input = '0';
    while(input != 'q' || input != 'Q'){
        cout << "What would you like to order?" << endl;
        cout << "Pizza = p | " << "Extras = e | " << "Quit = q" << endl;
        cout << "Type: ";
        cin >> input;
        if(input == 'p' || input == 'P'){

        }
        else if(input == 'e' || input == 'E'){

        }
        else if(input == 'q' || input == 'Q'){

        }
        else{
            cout << "Invalid input!" << endl;
        }
    }

}
