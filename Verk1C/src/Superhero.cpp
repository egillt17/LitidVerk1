#include "Superhero.h"

Superhero::Superhero()
{
    _name = "";
    _age = 0;
    _power = 'n';
}

Superhero::Superhero(string name, int age, char power)
{
    _name = name;
    _age = age;
    _power = power;
}

Superhero::~Superhero()
{
    //dtor
}

istream& operator >> (istream& in, Superhero& hero){
    cout << "Name: ";
    in >> hero._name;
    cout << "Age: ";
    in >> hero._age;
    cout << "Power: ";
    in >> hero._power;

    return in;
}

ostream& operator << (ostream& out, const Superhero& hero){
    out << hero._name << " (" << hero._age << ") " << ":";
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

void Superhero::get_hero(Superhero hero){
    cout << "Name: " << _name << endl << "Age: " << _age << endl << "SuperPower: " << _power << endl;
}

void Superhero::set_hero(string name, int age, char power){
    _name = name;
    _age = age;
    _power = power;
}
