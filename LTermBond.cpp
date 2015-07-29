// file LTermBond.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "LTermBond.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
LTermBond::LTermBond(int amount){
	startingBal = amount;
	currentBal = amount;
}