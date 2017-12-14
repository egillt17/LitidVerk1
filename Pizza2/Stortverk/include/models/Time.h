#ifndef TIME_H
#define TIME_H

//#include <ctime>
#include <iostream>
#include <iomanip>

using namespace std;

class Time
{
    public:
        Time();
        friend ostream& operator << (ostream& out, const Time& time);
        void setTime();

    private:
        int _day;
        int _month;
        int _year;
        int _hour;
        int _minute;
};

#endif // TIME_H
