#include "Validate.h"
#include <string>
#include <iostream>

using namespace std;

/// Boolean function, that validates the name input in the manager UI
bool Validate::validateName(string name){
    bool isSpace = false;   /// checks if there is a space in the string example (Pizza sauce)
    int tempPos;    /// to set the position of the whitespace
    int countSpace = 0; /// counts the number of spaces in the string
    if(name == ""){ /// checks if the string is empty - throws an error
        throw(InvalidNameException("| Invalid Input - Empty string not allowed"));
    }
    if (name[0] == ' '){    /// checks if the string starts with a whitespace, throws an error
        throw(InvalidNameException("| Invalid Input - Name must start with a letter"));
    }
    if (name[name.length()-1] == ' '){ /// checks if the string ends with a whitespace, throws an error
        throw(InvalidNameException("| Invalid Input - Name cannot end with space"));
    }
    for(unsigned int i = 1; i < name.length(); i++){    /// goes through the string, checking for whitespace
        if(name[i] == ' '){
            isSpace = true; /// sets a boolean if there is a space
            countSpace++;   /// counts the spaces
        }
    }
    if(countSpace > 1) {    /// must be only 1 space, throws an error if not
        throw(InvalidNameException("| Invalid Input - Name must be 1 or 2 words"));
    }
    if(isSpace) {   /// if the string contains a space
        tempPos = name.find(" ");   /// sets the position of it
        name.erase(tempPos,1);  /// erases the space
        for(unsigned int i = 0; i < name.length(); i++){
            if(!isalpha(name[i])){  /// checks the string for digits - throws an error if so
            throw(InvalidNameException("| Invalid Input - Name must be letters only"));
            }
        }
        name.insert(tempPos," ");   /// puts the space back in its position
        return true;
    }
    for(unsigned int i = 0; i < name.length(); i++){    /// if hte name is only 1 word, check if digits
        if(!isalpha(name[i])){              /// throws an error if so
            throw(InvalidNameException("| Invalid Input - Name must be letters only"));
        }
    }
return true;
}

/// to validate numbers
bool Validate::validateNum(string number){  
    if(number == ""){       /// checks if string is empty - throws an error if so
        throw(InvalidNumExceptions("| Invalid Input - Empty string not allowed"));
    }
    for(unsigned int i = 0; i < number.length(); i++){  /// checks if the string contains only digits, 
        if(!isdigit(number[i])){    /// throws an error if so
            throw(InvalidNumExceptions("| Invalid Input - Must be digits only"));
        }
    }
return true;
}

/// function to validate the location
bool Validate::validateLocation(string location){
    string tempStreet;  /// to hold only the street name
    string tempNum; /// to hold only the street address
    string delimiter = " "; /// to find the split
    int num_of_delimiters = 0;  /// count the splitters
    unsigned int pos = 0;
    if(location.empty()){   /// check if string is empty
        throw(InvalidLocationException("| Invalid Input - Empty string not allowed"));
    }
    if(location[0] == ' '){ /// checks if string starts with a space
        throw(InvalidLocationException("| Invalid Input - Must start with a letter"));
    }
    for(size_t i = 0; i < location.length(); i++) { /// checks the number of spaces
        if(location[i] == ' '){
            num_of_delimiters++;
        }
    }
    if(num_of_delimiters == 0){ /// if there is no spaces, this checks if only letters
        for(size_t i = 0; i < location.length(); i++) {
            if(isdigit(location[i])){
                throw(InvalidLocationException("| Invalid Input - Street name must be only letters"));
            }
        }       /// this is to add locations with only name, no number
        return true;
    }
    if(num_of_delimiters > 1) { /// if spaces are more than 1, it throws an error
        throw(InvalidLocationException("| Invalid Input - Only street name followed by a number"));
    }
    pos = location.find(delimiter);     /// marks the position of the space
    tempStreet = location.substr(0, pos);   /// puts the street name to a tempstring
    location.erase(0, pos + delimiter.length());    /// erases the first part of the string
    tempNum = location.substr(0, location.length());    /// puts the street number to a tmpstring
    for(size_t i = 0; i < tempStreet.length();i++){ 
        if(!isalpha(tempStreet[i])){    /// checks if the name only contains letters
            throw(InvalidLocationException("| Invalid Input - Street name must be only letters"));
        }
    }
    for(size_t i = 0; i < tempNum.length(); i++){   
        if(!isdigit(tempNum[i])) {      /// checks if the street number only contains digits
            throw(InvalidLocationException("| Invalid Input - Street number must be only digits"));
        }
    }   /// returns true if everything is right
return true;
}


