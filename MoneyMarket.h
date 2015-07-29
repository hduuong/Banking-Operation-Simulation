//
//  MoneyMarket.h
//  lab5
//  Money Markey account class
//

#ifndef lab5_MoneyMarket_h
#define lab5_MoneyMarket_h
#include "Account.h"
#include "PMoneyMarket.h"
using namespace std;

//------------------------------ class MoneyMarket -----------------------------
//  MoneyMarket class: inherits Account class. Has all standard account 
//    behaviors. In addition, if account is overdrawn, the amount overdrawn will
//    be moved from PMoneyMarket to this account.
//
//  Assumptions:
//    -- can be overdrawn if sufficient funds exist in PMoneyMarket
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class MoneyMarket: public Account {
    
public:
	MoneyMarket(int = 0);                 // constructor
};

#endif
