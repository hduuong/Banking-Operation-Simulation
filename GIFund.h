//
//  GIFund.h
//  lab5
//  Growth Index Fund account class
//

#ifndef lab5_GrowthIndexFund_h
#define lab5_GrowthIndexFund_h
#include "Account.h"
using namespace std;

//------------------------------ class GIFund ----------------------------------
//  GIFund class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class GIFund: public Account {
    
public:
    GIFund(int = 0);       // constructor
};

#endif
