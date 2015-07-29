//
//  Transaction.h
//  lab5
//  Transaction class
//

#ifndef __lab5__Transaction__
#define __lab5__Transaction__

#include <iostream>
#include <iomanip>
#include <ostream>
#include <string>
using namespace std;
//------------------------------ class Transaction ----------------------------
//  Transaction class: stores the transactions to be made on each clients
//    account.
//
//  Assumptions:
//    -- Client IDs must be valid
//    -- Transactions must contain a transaction type, client ID, account number 
//       and transaction amount.
//    -- Cannot withdraw a negative amount
//    -- There only 3 datas in a bad line of command with invalid type.
//    
//------------------------------------------------------------------------------

class Transaction {
public:
	Transaction();
    Transaction(char, int, int = 0, int = 0);      // Constructor
	friend ostream& operator<<(ostream&, const Transaction&);

    char getTranType() const;              // return transaction type
    int getSourceAcct() const;             // return source account ID
    int getToAcct() const;                 // return destination account ID
    int getAmount() const;                 // return transaction amount
    
private:
    char transType;     // transaction type
    int sourceAcct;     // source account id
    int toAcct;         // destination account id
    int amount;         // transaction amount
};

#endif /* defined(__lab5__Transaction__) */