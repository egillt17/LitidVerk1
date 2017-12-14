#include "Time.h"
//#include <ctime>
    
Time::Time()
{
    //ctor
}

ostream& operator << (ostream& out, const Time& time){
    
    out << setw(2) << setfill('0') << time._hour << ":";
    out << setw(2) << setfill('0') << time._minute;
    

}

void Time::setTime(){/*
    time_t now;
    struct tm nowLocal;
    now=time(NULL);
    nowLocal=*localtime(&now); 
    _day = nowLocal.tm_mday;
    _month = nowLocal.tm_mon;
    _year = nowLocal.tm_year;
    _hour = nowLocal.tm_hour;
    _minute = nowLocal.tm_min;*/
}



/*
void getTime() {

    int day;
    int month;
    int year;
    int hour;
    int min;
    int seconds;  
    hour = 0;
    min = 0;
    seconds = 0;
    day = aTime->tm_mday;
    month = aTime->tm_mon + 1; // Month is 0 – 11, add 1 to get a jan-dec 1-12 concept
    year = aTime->tm_year + 1900; // Year is # years since 1900
    hour = aTime->tm_hour;
    min = aTime->tm_min;
    seconds = aTime->tm_sec;  
    
    cout << month << "/" << day << "/" << year << "-[";
    if(hour < 10){
        cout << "0";
    }
    cout << hour << ":";    
    if(min < 10){
        cout << "0";
    }
    cout << min << ":" << seconds << "]" << endl;
}



int main(){

getTime();


/*
while(1) {
    

    Sleep(2000);
    
}

return 0;
}
*/
