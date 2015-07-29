// file MoneyMarket.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "PMoneyMarket.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
PMoneyMarket::PMoneyMarket(int amount){
	startingBal = amount;
	currentBal = amount;
}