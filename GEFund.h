//
//  GEFund.h
//  lab5
//  Growth Equity Fund account class
//

#ifndef lab5_GEFund_h
#define lab5_GEFund_h
#include "Account.h"
using namespace std;

//------------------------------ class GEFund ----------------------------------
//  GEFund class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class GEFund: public Account {
    
public:
    GEFund(int = 0);       // constructor
};

#endif
