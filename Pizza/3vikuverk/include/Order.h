#ifndef ORDER_H
#define ORDER_H
#include "Toppings.h"


class Order
{
    public:
        Order();
        ~Order();
        void take_order();

    private:
        int _amount;
};

#endif // ORDER_H
