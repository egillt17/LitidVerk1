#include "Superhero.h"
// nulling out the private variables so there wont be anything in them when I want to use them
Superhero::Superhero()
{
    _name = "";
    _age = 0;
    _power = 'n';
}
// adds the 3 variables that the function takes in and puts in the private variables
Superhero::Superhero(string name, int age, char power){
    _name = name;
    _age = age;
    _power = power;
}

Superhero::~Superhero()
{
    //dtor
}
// here I have overwritten the in stream to show the program how I want
// the superhero variable to be prompted to the user so the user can add
// input it
istream& operator >> (istream& in, Superhero& hero){
    cout << "Name: ";
    in >> hero._name;
    cout << "Age: ";
    in >> hero._age;
    cout << "Power: ";
    in >> hero._power;

    return in;
}
// here I have overwritten the in stream to show the program how I want
// the superhero variable to be printed out
ostream& operator << (ostream& out, const Superhero& hero){
    out << hero._name << " (" << hero._age << ")" << ": ";
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

    return out;
}
