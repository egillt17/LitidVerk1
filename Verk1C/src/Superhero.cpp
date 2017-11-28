#include "Superhero.h"

Superhero::Superhero()
{
    _name = "";
    _age = 0;
    _power = 'n';
}

istream& operator >> (istream& in, Superhero hero){
    in >> hero._name >> hero._age >> hero._power;
    return in;
}

ostream& operator << (ostream& out, const Superhero hero){
    out << hero._name << " (" << hero._age << ") " << ": " << hero._power;
    return out;
}

Superhero::~Superhero()
{
    //dtor
}
