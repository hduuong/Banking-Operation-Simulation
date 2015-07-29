//
//  500IFund.h
//  lab5
//  500 Index Fund account class
//

#ifndef lab5__00IFund_h
#define lab5__00IFund_h
#include "Account.h"
using namespace std;

//------------------------------ class FHIFund ---------------------------------
//  FHIFund class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class FHIFund: public Account {
    
public:
    FHIFund(int = 0);       // constructor
};

#endif
