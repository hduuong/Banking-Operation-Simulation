// file Owner.cpp
// @author Duong H Chau
// @version LAB5

#include "Owner.h"

//-----------------------------------------------------------------------
// default constructor
// set default values to the private members
Owner::Owner(){
	firstName = "";
	lastName = "";
}
//-----------------------------------------------------------------------
// constructor
// set values to the the private members
// @param first the firstname
// @param last the lastname
Owner::Owner(string first, string last){
	firstName = first;
	lastName = last;
}
//-----------------------------------------------------------------------
// operator<<
// overload the << operator to display the full name of an owner
// @param output the output objeect
// @param owner the owner that get printed
// @return the output object
ostream& operator<<(ostream& output, const Owner& owner){
	output << owner.getFirstName() << " " << owner.getLastName();

	return output;
}
//-----------------------------------------------------------------------
// getFirstName
// get the first name of the owner
// @return the first name of the owner
string Owner::getFirstName()const{
	return firstName;
}
//-----------------------------------------------------------------------
// getLastName
// get the last name of the owner
// @return the last name of the owner
string Owner::getLastName()const{
	return lastName;
}
//-----------------------------------------------------------------------
// setFirstName
// set the first name of the owner
// @param name the first name of the owner
bool Owner::setFirstName(string name){
	if(firstName.compare(name) == 0) return false;
	firstName = name;
	return true;
}
//-----------------------------------------------------------------------
// setLastName
// set the last name of the owner
// @param name the last name of the owner
bool Owner::setLastName(string name){
	if(lastName.compare(name) == 0) return false;
	lastName = name;
	return true;
}