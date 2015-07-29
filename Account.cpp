// file Account.cpp
// @author Duong H Chau
// @version LAB5

#include "Account.h"

//-----------------------------------------------------------------------
// Constructor
// Takes in an integer for the balance
// @param balance the starting balance of the account
Account::Account(int balance){
	currentBal = balance;
	startingBal = balance;
}

//-----------------------------------------------------------------------
// deposit
// deposit a amount of money into the current balance
// @param amount a amount of money need to be deposited
// @return true when successfully deposit, false if not
bool Account::deposit(int amount){
	currentBal += amount;
	return true;
}
//-----------------------------------------------------------------------
// withdraw
// withdraw a amount of money into the current balance
// @param amount a amount of money need to be withdrawed
// @return true when successfully withdraw, false if not
bool Account::withdraw(int amount){
	if(amount > currentBal) return false;
	currentBal -= amount;
	return true;
}
//-----------------------------------------------------------------------
// clearAcctn
// clear all the account information
// @return true when successfully clear the account
bool Account::clearAcct(){
	currentBal = 0;
	startingBal = 0;
	return true;
}
//-----------------------------------------------------------------------
// getBalance
// get the current balance of the account
// @return current balance of the account
int Account::getBalance()const{
	return currentBal;
}
//-----------------------------------------------------------------------
// getStartBalance
// get the starting balance of the account
// @return Starting balance of the account
int Account::getStartBalance()const{
	return startingBal;
}
//-----------------------------------------------------------------------
// isEmpty
// check whether the account is empty or not
// using the current balance to check, empty when 0
// @return true if it is empty, false if is not
bool Account::isEmpty()const{
	return currentBal == 0;
}
