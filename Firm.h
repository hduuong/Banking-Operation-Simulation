//
//  firm.h
//  lab5
//  Firm class
//

#ifndef __lab5__Firm__
#define __lab5__Firm__

#include <iostream>
#include <iomanip>
#include <fstream>
#include <queue>
#include <string>
#include "BSTree.h"
#include "Client.h"

using namespace std;

//------------------------------ class Firm ---------------------------------
//  Firm class: contains a binary search tree of pointers to clients sorted
//    by id number, with additional features:
//    -- add a new client to the Firm
//    -- delete a client and all of their accounts
//    -- withdraw, and deposit funds from one account, and transfer funds
//       from one account to another
//    -- output of transaction history of a client
//    -- output of the end-of-day report of all transactions within the Firm
//
//  Assumptions:
//    -- A firm can hold 0 to multiple clients (cannot have negative Clients)
//    -- BSTree contains nodes with pointers to Client objects (where all
//       client and account info is stored)
//    -- ID numbers must be 4 digits
//    -- instantiated account balances cannot be negative
//---------------------------------------------------------------------------

class Firm {
static const int MAXLENGTH = 30;                 // maximum character in a string
public:
    Firm();     // Constructor
    ~Firm();    // Destructor
    
    void readClientFile(ifstream&);              // read in client data
	bool addClient(Client*);                      // add a client to the firm
    void displayEOD() const;                     // display firm transaction history (REPORT)
    void getClientHistory(int) const;            // display client account history
    bool readTransaction(ifstream&);             // load processor from file
	bool processTransaction();                   // process the transaction queue
    bool moveFunds(int, int, int);               // transfer funds between accounts
   
private:
	BSTree<Client> clients;                     // tree of clients
	queue<Transaction> transactions;            // queue of transactions
};

#endif /* defined(__lab5__Firm__) */
