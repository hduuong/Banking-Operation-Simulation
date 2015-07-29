// file FHIFund.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "FHIFund.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
FHIFund::FHIFund(int amount){
	startingBal = amount;
	currentBal = amount;
}