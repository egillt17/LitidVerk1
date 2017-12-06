#include "InvalidMonthExc.h"

InvalidMonthExc::InvalidMonthExc(string message)
{
    _message = message;
}

string InvalidMonthExc::getMessage() {
    return _message;
}
