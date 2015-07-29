// file VSIndex.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"
#include "VSIndex.h"
//-----------------------------------------------------------------------
// constructor
// give values to the balances
// @param amount amount of the staring balance
VSIndex::VSIndex(int amount){
	startingBal = amount;
	currentBal = amount;
}