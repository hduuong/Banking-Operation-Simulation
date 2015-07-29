// file ValueFund.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "ValueFund.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
ValueFund::ValueFund(int amount){
	startingBal = amount;
	currentBal = amount;
}