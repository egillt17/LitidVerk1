#include "Service.h"


Service::Service() {
    //ctor
}

Service::~Service() {
    //dtor
}

void Service::writeEmployeeInFile(string name, string ssn, string salary, string month, string year) {
    Employee employee = makeEmployee(name, ssn, salary, month, year);
    if(!employeeCheck(employee)) {
        Repository input;
        input.writeInFile(employee);
    }
}

Employee Service::makeEmployee(string name, string ssn, string salary, string month, string year) {
    int monthNumber = 0;
    int yearNumber = 0;

    stringstream sin2(month);
    sin2 >> monthNumber;
    stringstream sin3(year);
    sin3 >> yearNumber;

    Employee employee(name, ssn, salary, monthNumber, yearNumber);

    return employee;
}

bool Service::employeeCheck(Employee employeeTest) {
    bool found = false;
    vector <Employee> employee;
    Repository get;
    get.getInfoInFile(employee);

    for(unsigned int i = 0; i < employee.size(); i++) {
        if(!employeeTest.get_ssn().compare(employee[i].get_ssn())) {
            if(employeeTest.get_month() == employee[i].get_month()) {
                if(employeeTest.get_year() == employee[i].get_year()) {
                    employee[i] = employeeTest;
                    found = true;
                }
            }
        }
    }
    if(found == true) {
        get.reWriteInFile(employee);
    }

    return found;
}

Employee Service::findEmployeeMonth(string ssn, string month, string year) {
    int monthNumber = 0;
    int yearNumber = 0;
    Employee employee2;
    stringstream sin1(month);
    sin1 >> monthNumber;
    stringstream sin2(year);
    sin2 >> yearNumber;
    Repository get;
    vector <Employee> employee;
    get.getInfoInFile(employee);

    for(unsigned int i = 0; i < employee.size(); i++) {
        if(!ssn.compare(employee[i].get_ssn())) {
            if(monthNumber == employee[i].get_month()) {
                if(yearNumber == employee[i].get_year()) {
                    employee2 = employee[i];
                }

            }
        }
    }

    return employee2;
}

Employee Service::findEmployeeYearlySalary(string ssn, string year) {
    int yearNumber = 0;
    double salary = 0;
    double cash = 0;
    bool found = false;
    vector <Employee> employee;
    Employee employeeYs;
    Repository get;
    get.getInfoInFile(employee);

    stringstream sin1(year);
    sin1 >> yearNumber;

    for(unsigned int i = 0; i < employee.size(); i++) {
        if(!ssn.compare(employee[i].get_ssn())) {
            if(yearNumber == employee[i].get_year()) {
                employeeYs = employee[i];
                stringstream sin2(employee[i].get_salary());
                sin2 >> cash;
                salary += cash;
                found = true;

            }
        }
    }
    if(found == true) {
        employeeYs.set_salary(salary);
        employeeYs.set_month(0);
    }

    return employeeYs;
}

Employee Service::findHighestEmployeeYearly(string year) {
    Employee highestEmployee;
    int yearNumber = 0;
    double salary = 0;
    double cash = 0;
    bool found = false;
    vector <Employee> employee;
    vector <Employee> employeef;

    Repository get;
    get.getInfoInFile(employee);
    stringstream sin1(year);
    sin1 >> yearNumber;

    for(unsigned int i = 0; i < employee.size(); i++) {
        if(employee[i].get_year() == yearNumber) {
            employeef.push_back(employee[i]);
        }
    }

    for(unsigned int i = 0; i < employeef.size(); i++) {
        salary = 0;
        found = false;
        for(unsigned int j = 0; j < employee.size(); j++) {
            if(!employeef[i].get_ssn().compare(employee[j].get_ssn())) {
                stringstream sin2(employee[j].get_salary());
                sin2 >> cash;
                salary += cash;
                found = true;
            }
        }
        if(found) {
            employeef[i].set_salary(salary);
            employeef[i].set_month(0);
        }
    }
    stringstream sin5(employeef[0].get_salary());
    sin5 >> salary;
    for(unsigned int i = 0; i < employeef.size(); i++) {
        stringstream sin4(employeef[i].get_salary());
        sin4 >> cash;
        if(cash > salary) {
            highestEmployee = employeef[i];
            stringstream sin5(employeef[i].get_salary());
            sin5 >> salary;
        }
    }

    return highestEmployee;
}
