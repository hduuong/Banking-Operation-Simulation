// file GEFund.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "GEFund.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
GEFund::GEFund(int amount){
	startingBal = amount;
	currentBal = amount;
}