//
//  VSIndex.h
//  lab5
//  Value Stock Index account class
//

#ifndef lab5_VSIndex_h
#define lab5_VSIndex_h
#include "Account.h"
using namespace std;

//------------------------------ class VSIndex --------------------------------
//  VSIndex class: inherits Account class. Has all standard functionality of
//    Account. No additional functionality
//
//  Assumptions:
//    -- account cannot be overdrawn
//    -- if overdraw attempts, no action will occur
//    -- withdraw amounts must be greater than -1
//    -- withdrawal of 0 has no effect
//------------------------------------------------------------------------------

class VSIndex: public Account {
    
public:
    VSIndex(int balance = 0);       // constructor
};

#endif
