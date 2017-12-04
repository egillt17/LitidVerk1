#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>

using namespace std;

class Superhero
{
    public:
        // constructor
        Superhero();
        // constructor with 3 variables
        Superhero(string name, int age, char power);
        ~Superhero();
        // overwritten input stream
        friend istream& operator >> (istream& in, Superhero& hero);
        // overwritten output stream
        friend ostream& operator << (ostream& out, const Superhero& hero);

    private:
        string _name;
        int _age;
        char _power;
};

#endif // SUPERHERO_H
