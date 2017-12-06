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

    return employee;
}

bool Service::employeeCheck(Employee employeeTest) {
    bool found = false;
    vector <Employee> employee;
    Repository get;
    get.getInfoInFile(employee);

    for(unsigned int i = 0; i < employee.size(); i++) {
        if(!employeeTest.get_name().compare(employee[i].get_name())) {
            if(!employeeTest.get_ssn().compare(employee[i].get_ssn())) {
                if(employeeTest.get_month() == employee[i].get_month()) {
                    if(employeeTest.get_year() == employee[i].get_year()) {
                        employee[i] = employeeTest;
                        found = true;
                    }

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
    int salary = 0;
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
                salary += employee[i].get_salary();
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
