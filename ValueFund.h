//
//  ValueFund.h
//  lab5
//  Value Fund account class
//

#ifndef lab5_ValueFund_h
#define lab5_ValueFund_h
#include "Account.h"
using namespace std;

//------------------------------ class ValueFund ------------------------------
//  ValueFund class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class ValueFund: public Account {
    
public:
    ValueFund(int balance = 0);       // constructor
};

#endif
