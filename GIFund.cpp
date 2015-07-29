// file GIFund.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "GIFund.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
GIFund::GIFund(int amount){
	startingBal = amount;
	currentBal = amount;
}