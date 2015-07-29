//
//  LTermBond.h
//  lab5
//  Long-Term Bond account class
//

#ifndef lab5_LTermBond_h
#define lab5_LTermBond_h
#include "Account.h"
#include "STermBond.h"
using namespace std;

//------------------------------ class LTermBond -------------------------------
//  LTermBond class: inherits Account class. Has all standard account 
//    behaviors. In addition, if account is overdrawn, the amount overdrawn will
//    be moved from StermBond to this account.
//
//  Assumptions:
//    -- can be overdrawn if sufficient funds exist in StermBond
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class LTermBond: public Account {
    
public:
	LTermBond(int = 0);            // constructor
};

#endif
