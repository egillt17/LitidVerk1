#ifndef VALIDATE_H
#define VALIDATE_H
/// Include the service.h
#include "Service.h"
/// include all the Invalid---Exceptions.h files
#include "InvalidNameExc.h"
#include "InvalidMonthExc.h"
#include "InvalidSalaryExc.h"
#include "InvalidSsnExc.h"
#include "InvalidYearExc.h"
#include "InvalidInputExc.h"
/// to be able to use stringstream, conversion from string
#include <sstream>

/// validation class, to validate the input from the users, 

class Validate
{
    public:
        /// to validate how many employee user want's to write to the records
        bool validateInput(string input);
        /// Validate how the salary is input, if it is only digits or, is a letter 
        bool validateSalary(string salary);
        /// validates the lenght of the ssn, and if it is only digits
        bool validateSSN(string ssn);
        /// validates month input if it is only digits, and if it is/or between 1 - 12
        bool validateMonth(string month);
        /// validate name input checks if the name does not contain digits, or if it begins with a whitespace
        bool validateName(string name);
        /// validate year checks if the input is digits only, four digits, and must be between 1900 and 2017
        bool validateYear(string year);

    private:
};

#endif // VALIDATE_H
