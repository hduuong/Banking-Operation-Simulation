//
//  client.h
//  lab5
//  Client class
//

#ifndef __lab5__Client__
#define __lab5__Client__

#include <iostream>
#include <ostream>
#include <iomanip>
#include <list>
#include <string>
#include "Account.h"
#include "MoneyMarket.h"
#include "PMoneyMarket.h"
#include "CVFund.h"
#include "FHIFund.h"
#include "GEFund.h"
#include "GIFund.h"
#include "STermBond.h"
#include "LTermBond.h"
#include "ValueFund.h"
#include "VSIndex.h"
#include "Owner.h"
#include "Transaction.h"

using namespace std;

//------------------------------ class Client ----------------------------------
//  Client class: contains all firm-related information of a client such as
//    ID, accounts, transaction history, with the following features:
//    -- clearing an account
//    -- handles withdrawals and deposits
//    -- retrieve history of transactions for client
//    -- retrieve client's ID
//    -- retrieve client's accounts info
//    -- comparing of client IDs
//    -- contains a stack of transactions for documentation
//  
//  Assumptions:
//    -- clearing an account sets the funds to 0
//    -- clearing an empty account does nothing
//    -- IDs must be 4 digits
//    -- deposit or withdrawal amount cannot be less than 0
//------------------------------------------------------------------------------

const int MAX_ACCT = 10;

class Client {

public:
	friend ostream& operator<<(ostream&, const Client&);
    Client(string,string,int,int,int,int,int,int,int,int,int,int,int);       // Constructor
    Client(int);
	~Client();      // Destructor
    
    int getID() const;                         // get client ID
    void getHistory() const;                   // display history
	void addHistory(char, int, int, int);      // add a successful transaction to the list of history  
	void deleteMostRecent();
    bool depositToAccount(int,int);            // deposit to a specified account
    int widthdrawlFromAccount(int,int);        // withdraw from a specified account
    void clearAccounts();                       // clear accounts
    void getOwner() const;                     // get account's owner
    bool operator>(const Client&) const;        // compares for greater ID
    bool operator<(const Client&) const;        // compares for lesser ID
    bool operator==(const Client&) const;       // compares for equal ID
    
private:
    int ID;                          // client ID number
    Account accounts[MAX_ACCT];      // array of accounts
    Owner owner;                     // owner information
    list<Transaction> history;      // history stack
};

#endif /* defined(__lab5__Client__) */
