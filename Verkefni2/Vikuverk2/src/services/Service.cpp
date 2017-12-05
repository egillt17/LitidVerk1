#include "Service.h"


Service::Service() {
    //ctor
}

Service::~Service() {
    //dtor
}

void Service::writeEmployeeInFile(string name, string ssn, string salary, string month, string year) {
    int salaryNumber = 0;
    int monthNumber = 0;
    int yearNumber = 0;

    stringstream sin1(salary);
    sin1 >> salaryNumber;
    stringstream sin2(month);
    sin2 >> monthNumber;
    stringstream sin3(year);
    sin3 >> yearNumber;

    Employee employee(name, ssn, salaryNumber, monthNumber, yearNumber);

}
