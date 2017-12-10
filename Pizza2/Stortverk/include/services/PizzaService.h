#ifndef PIZZASERVICE_H
#define PIZZASERVICE_H

#include "Pizza.h"
#include "Toppings.h"
#include "PizzaRepo.h"


class PizzaService
{
    public:
        vector <string> getLocation();
        void addLocation(string location);
        bool removeLocation(string location);


    private:
        bool locationCheck(string location);
};

#endif // PIZZASERVICE_H
