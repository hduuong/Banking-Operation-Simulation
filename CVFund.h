//
//  CVFund.h
//  lab5
//  Capital Value Fund account class
//

#ifndef lab5_CVFund_h
#define lab5_CVFund_h
#include "Account.h"
using namespace std;

//------------------------------ class CVFund ----------------------------------
//  CVFund class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class CVFund: public Account {
    
public:
    CVFund(int = 0);       // constructor
};
#endif
