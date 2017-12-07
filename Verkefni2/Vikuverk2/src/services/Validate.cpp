#include "Validate.h"

/// Validate how many employees the user wants to create, maximum 10, and if it is a digit,
bool Validate::validateInput(string input){
    for(unsigned int i = 0; i < input.length(); i++) {  /// goes through the string,
        if(!isdigit(input[i])){     /// checks if it is only digits, if not
            throw(InvalidInputExc("Invalid input - (digits only)"));  /// it throws the invalid inputexception message
        }
    }
    int tmpInput = 0;
    stringstream sin1(input);
    sin1 >> tmpInput;           /// convert the string to int
    if (tmpInput >= 1 && tmpInput <= 10){           /// checks if it is 1 to 10
        return true;
    }
    else {
        throw(InvalidInputExc("Invalid input - (1 to 10)"));  /// if not, throws another invalid inputexception message
    }

}

/// validates the salary
bool Validate::validateSalary(string salary)
{
    for (unsigned int i = 0; i < salary.length(); i++){ /// goes through the string, check if only digit
        if (!isdigit(salary[i])){
            throw(InvalidSalaryExc("Invalid input - (digits only)")); /// if not, throws invalidsalaryexception message
        }
    }
return true;
}

/// To validate the SSN
bool Validate::validateSSN(string ssn)
{
    if (ssn.length() == 10)     /// checks the strings length, must be length of 10
    {
        for (unsigned int i = 0; i < ssn.length(); i++)     /// goes through the string, check if only digit
        {
            if (!isdigit(ssn[i]))
            {
                throw(InvalidSsnExc("Invalid input - (10 - digits only)"));   /// if not, throws an error message, only digits
            }
        }
    }
    else {
        throw(InvalidSsnExc("Invalid lenght - (10 - digits)"));   /// throws another error if it is not the correct length
    }
return true;
}

/// to Validate month
bool Validate::validateMonth(string month)
{
    for(unsigned int i = 0; i < month.length(); i++) {  /// check if only digit
        if(!isdigit(month[i])){
            throw(InvalidMonthExc("Invalid input - (digits only)"));  /// throws an error if it is not
        }
    }
    int tmpMonth = 0;
    stringstream sin1(month);
    sin1 >> tmpMonth;       /// converts to integer
    if (tmpMonth <= 12 && tmpMonth >= 1){   /// check if it is from 1 to 12
        return true;
    }
    else{
        throw(InvalidMonthExc("Invalid input - (1 to 12)"));  /// throws error, must be 1 to 12
    }
}

/// to validate the  name
bool Validate::validateName(string name)
{
    for (unsigned int i = 0; i < name.length(); i++)    /// check if it is only letter
    {
        if (!isalpha(name[i]) && name[i] != ' ')    /// string can have whitespace
        {
            throw(InvalidNameExc("Invalid input - (letters only)"));  /// throws error, if it contains digit
        }
    }
    if (name[0] == ' '){    /// checks if the first letter is not a whitespace, throws an error message
        throw(InvalidNameExc("Invalid input - (must start with a letter)"));
    }
return true;
}

/// to validate the year
bool Validate::validateYear(string year)
{
    for(unsigned int i = 0; i < year.length(); i++) {   /// checks if it contains only digits
        if(!isdigit(year[i])){
            throw(InvalidYearExc("Invalid input - (digits only)"));   /// throws an error message
        }
    }
    int tmpYear = 0;
    if(year.length() != 4) {    /// checks if it is only 4 digits in length
        throw(InvalidYearExc("Invalid input - (4 - digits only)"));   /// throws an error message
    }
    stringstream sin1(year);
    sin1 >> tmpYear;    /// converts the string to integer
    if (tmpYear >= 1900 && tmpYear <= 2017) /// check if it is between 1900 and 2017
    {
            return true;
    }
    else
    {
        throw(InvalidYearExc("Invalid input - (1900 to 2017)"));  /// throws an error message
    }
throw(InvalidYearExc("Invalid input"));
}

