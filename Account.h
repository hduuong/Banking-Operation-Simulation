//
//  Account.h
//  lab5
//  Account class
//

#ifndef __lab5__Account__
#define __lab5__Account__

#include <iostream>

using namespace std;

//------------------------------ class Account ---------------------------------
//  Account class: stores a monetary balance and provides basic functionality:
//    -- withdraw or deposit funds from account
//    -- clear an account's balance
//    -- retrieve an account's balance
//    -- check if account is empty
//    -- transfer funds between accounts
//
//  Assumptions:
//    -- balance cannot be negative (cannot overdraw)
//    -- cannot withdraw a negative amount
//    -- clearing an account sets the total funds to 0
//------------------------------------------------------------------------------

class Account {
    
public:
    Account(int = 0);               // constructor
    
    bool deposit(int);              // make a deposit
    bool withdraw(int);              // withdraw from account
    bool clearAcct();               // empty account
    int getBalance() const;         // get balance
	int getStartBalance() const;    // get starting balance
    bool isEmpty() const;           // see if account is empty
//	Account& operator=(const Account &);
protected:
    int startingBal;         // account's starting amount
    int currentBal;          // account's end of transaction amount
};

#endif /* defined(__lab5__Account__) */
