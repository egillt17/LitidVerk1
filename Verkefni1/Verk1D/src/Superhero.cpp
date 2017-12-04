#include "Superhero.h"  //to link to the header file of the class

Superhero::Superhero()  //Constructor without any variables
{
    /*
    this nullifies the private variables in the class
    */
    _name[0] = '\0'; 
    _age = 0;
    _power = 'n';   
}

Superhero::Superhero(string name, int age, char power)  // constructor, makes a class with a name , age and power
{
    int name_lengt = name.size();           //as we are using strings, and we are storing the name in a character array, this gets the size of the string
    for(int i = 0; i < name_lengt; i++) {   //for-loop, uses the name_length from the string
        _name[i] = name[i];                 //itirate the first instance in the string to the first instance in the private variable char array
    }
    _name[name_lengt] = '\0';               // puts an end to the char array, so it doesn't print out everything after the actual name
    _age = age;                             //sets the age to the private var
    _power = power;                         //sets the power to the private char var
}

Superhero::~Superhero()     //deconstructor, not used
{
    //dtor
}

istream& operator >> (istream& in, Superhero& hero){    //friend function, overloads the >> operator in Superhero class(to cin >> hero in main.cpp)
    cout << "Name: ";       //Ask first the name
    in >> hero._name;       //you input the name, into the class
    cout << "Age: ";        //Ask the age
    in >> hero._age;        //input the age, into the class
    cout << "Power: ";      //ask the power
    in >> hero._power;      //input the power to the class

    return in;              // inputs from the stream
}

ostream& operator << (ostream& out, const Superhero& hero){     //friend function, overloads the << operator in Superhero class( to cout << hero in main.cpp)
    out << hero._name << " (" << hero._age << ")" << ": ";      //output to screen the hero "name (age) : "
    /*
    If else statements, that if the conditions of the private char variable in the class is as follows, it will display the full meaning of that 
    character, 'f' for flying, 'g' for giant, 'h' for hacker, and 'n' for none. If the input of the char is other than those , it will display Weakling
    */
    if(hero._power == 'f'){        
        out << "Flying" << endl;    
    }
    else if(hero._power == 'g'){    
        out << "Giant" << endl;     
    }
    else if(hero._power == 'h'){    
        out << "Hacker" << endl;    
    }
    else if(hero._power == 'n'){    
        out << "None" << endl;      
    }
    else{                           
        out << "Weakling" << endl;  
    }

    return out;                     //outputs on the stream
}

void Superhero::get_hero(Superhero hero){       //
    cout << "Name: " << _name << endl << "Age: " << _age << endl << "Power: " << _power << endl;   // this function is get_hero, tha gets the hero of 
                                                                                                        //the superhero class, prints out the name, age and pwer.
}
