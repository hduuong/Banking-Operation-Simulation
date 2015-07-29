// file STermBond.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "STermBond.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
STermBond::STermBond(int amount){
	startingBal = amount;
	currentBal = amount;
}