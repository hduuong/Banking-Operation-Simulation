//  Owner.h
//  lab5
//  Owner class
//

#ifndef __lab5__Owner__
#define __lab5__Owner__

#include <iostream>
#include <string>

using namespace std;

//--------------------------------- class Owner --------------------------------
//  Owner class: contains the personal information of the client (first, last
//    name)
//
//  Assumptions:
//    -- owner must have first and last name
//    -- last and first name cannot contain spaces within either
//------------------------------------------------------------------------------

class Owner {

public:
	Owner();                  // default constructor  
    Owner(string, string);    // Constructor takes 2 arguments
	friend ostream& operator<<(ostream&, const Owner&);

    string getFirstName() const;    // returns owner first name
    string getLastName() const;     // return owner last name
    bool setLastName(string);       // set owner last name
    bool setFirstName(string);      // set owner first name
    
private:
    string lastName;               
    string firstName;
};

#endif /* defined(__lab5__Owner__) */
