#include "Service.h"


void Service::writeEmployeeInFile(string name, string ssn, string salary, string month, string year) {
    Employee employee = makeEmployee(name, ssn, salary, month, year);   ///here all the variables are being made into an employee variable
    if(!employeeCheck(employee)) {  /// here a function gets called that checks if the employee has already been added at that time
        Repository input;   /// to access repository
        input.writeInFile(employee); /// sends the employee variable to the repository to be added to the file
    }
}

Employee Service::makeEmployee(string name, string ssn, string salary, string month, string year) {
    int monthNumber = 0;    /// int variable for month
    int yearNumber = 0;     /// int variable for year

    stringstream sin2(month);   ///changing month into an int
    sin2 >> monthNumber;
    stringstream sin3(year);    ///changing year into an int
    sin3 >> yearNumber;

    Employee employee(name, ssn, salary, monthNumber, yearNumber);  /// employee constructor

    return employee;    ///returns all the variables in an employee form
}

bool Service::employeeCheck(Employee employeeTest) {
    bool found = false;
    vector <Employee> employee;
    Repository get;
    get.getInfoInFile(employee);    /// sends in the vector to be filled with all the info thats needed

    for(unsigned int i = 0; i < employee.size(); i++) { /// runs through the vector
        if(!employeeTest.get_ssn().compare(employee[i].get_ssn())) {    /// checks for ssn
            if(employeeTest.get_month() == employee[i].get_month()) {       /// checks for month
                if(employeeTest.get_year() == employee[i].get_year()) {    ///checks for year
                    employee[i] = employeeTest;     ///if it gets through the checks then it gets overwritten
                    found = true;       /// and marks that the employee was found
                }
            }
        }
    }
    if(found == true) { /// if the employee was found then
        get.reWriteInFile(employee);    ///the vector gets sent to the repository to rewrite the file
    }

    return found;   /// lets the function that called it know if the employee was found
}

Employee Service::findEmployeeMonth(string ssn, string month, string year) {
    int monthNumber = 0;    /// int variable for month
    int yearNumber = 0;     /// int variable for year
    Employee employee2;     /// return value
    stringstream sin1(month);   /// turns month into an int value
    sin1 >> monthNumber;
    stringstream sin2(year);    /// turns year into an int value
    sin2 >> yearNumber;
    Repository get;     /// to access repository
    vector <Employee> employee;
    get.getInfoInFile(employee);    /// fills vector with all the info that will be needed

    for(unsigned int i = 0; i < employee.size(); i++) { /// runs through the vector
        if(!ssn.compare(employee[i].get_ssn())) {   /// checks for ssn
            if(monthNumber == employee[i].get_month()) {    /// checks if the month is correct
                if(yearNumber == employee[i].get_year()) {  /// checks if the year is correct
                    employee2 = employee[i];    /// if it gets through the checks then it puts the value into the return value
                }

            }
        }
    }

    return employee2; /// returns the value
}

Employee Service::findEmployeeYearlySalary(string ssn, string year) {
    int yearNumber = 0; /// int for year
    double salary = 0;  /// temp variable where it keeps the summed up salary
    double cash = 0;    /// temp variable where it keeps the salary value that gets added to the salary variable
    bool found = false;
    vector <Employee> employee;
    Employee employeeYs;    /// return value
    Repository get;
    get.getInfoInFile(employee);    /// fills the vector with all the info thats needed

    stringstream sin1(year);    /// turns year into an int
    sin1 >> yearNumber;

    for(unsigned int i = 0; i < employee.size(); i++) { /// runs through the employee vector
        if(!ssn.compare(employee[i].get_ssn())) {   /// checks if the ssn is correct
            if(yearNumber == employee[i].get_year()) {  /// checks if th year is correect
                employeeYs = employee[i];   /// if it gets through its put in the return value
                stringstream sin2(employee[i].get_salary());    /// turns the salary into a double
                sin2 >> cash;
                salary += cash; /// adds the employee yearly salary upp
                found = true;   /// marks if the employee was found

            }
        }
    }
    if(found == true) { /// if the employee was found
        employeeYs.set_salary(salary);  /// then the salary gets added to the return value
        employeeYs.set_month(0);    /// and the month gets set to 0 on the return value so it wont print the month
    }

    return employeeYs;  /// returns the found value
}

Employee Service::findHighestEmployeeYearly(string year) {
    Employee highestEmployee;   /// return value
    int yearNumber = 0; /// int value for year
    double salary = 0;  /// temp variable where it keeps the summed up salary
    double cash = 0;    /// temp variable where it keeps the salary value that gets added to the salary variable
    bool found = false;
    vector <Employee> employee; /// vector with all the info from the file
    vector <Employee> employeef;    /// vector with all the employees from a set year

    Repository get;
    get.getInfoInFile(employee);    /// gets all the info from the file
    stringstream sin1(year);        /// turns year into an int
    sin1 >> yearNumber;

    for(unsigned int i = 0; i < employee.size(); i++) { /// goes through all the employees if the file
        if(employee[i].get_year() == yearNumber) {  /// and takes out those that are marked in the year that we want
            employeef.push_back(employee[i]);   /// they get added to the vector
        }
    }

    for(unsigned int i = 0; i < employeef.size(); i++) {    /// goes through the vector with all the employees in the year that we want
        salary = 0;                             /// to check the employees with all the other inputs
        found = false;
        for(unsigned int j = 0; j < employee.size(); j++) { /// checks them with the vector that has all the employees
        if(!employeef[i].get_ssn().compare(employee[j].get_ssn())) {    /// if the ssn matches then they get added up
            if(yearNumber == employee[j].get_year()) {  /// if the year matches then they get added up
                stringstream sin2(employee[j].get_salary());    /// turns the salary into a double so it can be added up
                sin2 >> cash;
                salary += cash; /// adds all the salary upp of a given employee into the salary variable
                found = true;   /// and checks that employee as found

            }
        }
    }
    if(found == true) { /// if found
        employeef[i].set_salary(salary); /// then the salary gets set on the vector with the employee of a set year
        employeef[i].set_month(0);  /// and the month gets set to 0 so it wont be printed out
    }

    }
    double highest = 0; /// variable to keep the value of the highest salary
    for (unsigned int i = 0; i < employeef.size(); i++) {   /// goes through the vector with all the employees of a set year
        salary = 0; /// nulls salary
        stringstream sin3(employeef[i].get_salary());   ///changes salary of the employee from a string to a double
        sin3 >> salary; /// and puts it in the salary variable
        if(salary > highest) {  /// if the salary is higher then the highest value
            highestEmployee = employeef[i]; /// then the employee gets added to the highest employee value
            stringstream sin4(employeef[i].get_salary());   /// and the salary of the employee to the highest value
            sin4 >> highest;
        }
    }

    return highestEmployee; /// returns the highest employee
}
