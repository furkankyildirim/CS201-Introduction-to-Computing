#include "dice.h"
#include "randgen.h"

// implementation of dice class
// written Jan 31, 1994, modified 5/10/94 to use RandGen class
// modified 3/31/99 to move RandGen class here from .h file

Dice::Dice(int sides)
// postcondition: all private fields initialized     
{
    myRollCount = 0;
    mySides = sides;
}

int Dice::Roll()
// postcondition: number of rolls updated
//                random 'die' roll returned     
{
    RandGen gen;    // random number generator
    
    myRollCount= myRollCount + 1;         // update # of times die rolled
    return gen.RandInt(1,mySides);        // in range [1..mySides]
}

int Dice::NumSides() const
// postcondition: return # of sides of die     
{
    return mySides;
}

int Dice::NumRolls() const
// postcondition: return # of times die has been rolled     
{
    return myRollCount;
}

