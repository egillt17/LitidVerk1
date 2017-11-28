#ifndef SUPERHERO_H
#define SUPERHERO_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;


class Superhero
{
    public:
        Superhero();
        Superhero(string name, int age, char power);
        ~Superhero();
        friend istream& operator >> (istream& in, Superhero& hero);
        friend ostream& operator << (ostream& out, const Superhero& hero);
        friend ofstream& operator << (ofstream& os, const Superhero& hero);
        void get_hero(Superhero hero);
        void set_hero(string name, int age, char power);

    private:
        string _name;
        int _age;
        char _power;
};

#endif // SUPERHERO_H

