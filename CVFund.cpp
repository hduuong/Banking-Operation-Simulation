// file CVFund.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "CVFund.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
CVFund::CVFund(int amount){
	startingBal = amount;
	currentBal = amount;
}