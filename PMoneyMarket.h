//
//  PMoneyMarket.h
//  lab5
//  Prime Money Market account class
//

#ifndef lab5_PrimeMoneyMarket_h
#define lab5_PrimeMoneyMarket_h
#include <iostream>
#include "Account.h"
using namespace std;

//------------------------------ class PMoneyMarket ---------------------------
//  PMoneyMarket class: inherits Account class. Has all standard account 
//    behaviors. In addition, if account is overdrawn, the amount overdrawn will
//    be moved from MoneyMarket to this account.
//
//  Assumptions:
//    -- can be overdrawn if sufficient funds exist in MoneyMarket
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class PMoneyMarket: public Account {
    
public:
    PMoneyMarket(int = 0);       // constructor
};

#endif
