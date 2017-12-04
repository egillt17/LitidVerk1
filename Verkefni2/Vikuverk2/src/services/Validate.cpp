#include "Validate.h"

Validate::Validate()
{
    //ctor
}

bool Validate::validateSalary(double salary)
{
    if (salary >= 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Validate::validateSSN(string ssn)
{
    bool isSSN = false;
    if (ssn.size() == 10)
    {
        for (unsigned int i = 0; i < ssn.length() -1; i++)
        {
            if (!isdigit(ssn[i]))
            {
                isSSN = false;
                break;
            }
            else
            {
                isSSN = true;
            }
        }
    }
    return isSSN;
}

bool Validate::validateMonth(int month)
{
    if (month <= 12 && month >= 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Validate::validateName(string name)
{
    bool isName = false;
    for (unsigned int i = 0; i < name.length(); i++)
    {
        if (!isalpha(name[i]) && name[i] != ' ')
        {
            isName = false;
            break;
        }
        else
        {
            isName = true;
        }
    }
    if (!isalpha(name[0]))
    {
        isName = false;
    }
    return isName;
}

bool Validate::validateYear(int year)
{
    if (year == 2017)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Validate::validateAll(string name, string ssn, double salary, int month, int year)
{
    if (validateName(name) && validateSSN(ssn) && validateSalary(salary) && validateMonth(month) && validateYear(year))
    {
        return true;
    }
    else
    {
        return false;
    }
}
