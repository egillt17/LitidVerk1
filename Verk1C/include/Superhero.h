#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>

using namespace std;


class Superhero
{
    public:
        Superhero();
        ~Superhero();
        friend istream& operator >> (istream& in, Superhero hero);
        friend ostream& operator << (ostream& out, const Superhero hero);

    private:
        string _name;
        int _age;
        char _power;
};

#endif // SUPERHERO_H
