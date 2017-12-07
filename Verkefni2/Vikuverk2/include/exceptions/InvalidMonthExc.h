#ifndef INVALIDMONTHEXC_H
#define INVALIDMONTHEXC_H

#include "Employee.h"


class InvalidMonthExc
{
    public:
        InvalidMonthExc(string message);
        string getMessage();

    private:
        string _message;
};

#endif // INVALIDMONTHEXC_H
