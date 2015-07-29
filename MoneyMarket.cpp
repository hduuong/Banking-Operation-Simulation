// file MoneyMarket.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "MoneyMarket.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
MoneyMarket::MoneyMarket(int amount){
	startingBal = amount;
	currentBal = amount;
}
