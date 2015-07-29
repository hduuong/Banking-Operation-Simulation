//
//  STermBond.h
//  lab5
//  Short-Term Bond account class
//

#ifndef lab5_STermBond_h
#define lab5_STermBond_h
#include "Account.h"
using namespace std;

//------------------------------ class STermBond ------------------------------
//  STermBond class: inherits Account class. Has all standard account 
//    behaviors. In addition, if account is overdrawn, the amount overdrawn 
//    will be moved from LtermBond to this account.
//
//  Assumptions:
//    -- can be overdrawn if sufficient funds exist in LtermBond
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class STermBond: public Account {
    
public:

    STermBond(int = 0);                // constructor
};

#endif
