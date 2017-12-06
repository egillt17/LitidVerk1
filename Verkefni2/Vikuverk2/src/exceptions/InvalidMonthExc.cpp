#include "InvalidMonthExc.h"

InvalidMonthExc::InvalidMonthExc(string message) 
{
    this->message = message;
}

string InvalidMonthExc::getMessage() {
    return message;
}
