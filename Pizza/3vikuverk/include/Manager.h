#ifndef MANAGER_H
#define MANAGER_H
#include "Toppings.h"


class Manager
{
    public:
        Manager();
        virtual ~Manager();
        Toppings managerAddToppings();
        void managerPrintPizzas();
        void managerPrintToppings();

    protected:

    private:
};

#endif // MANAGER_H
