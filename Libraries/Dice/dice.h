#ifndef _DICE_H
#define _DICE_H

//  class for simulating a die (object "rolled" to generate
//                              a random number)
//
//  Dice(int sides) -- constructor, sides specifies number of "sides"
//               for the die, e.g., 2 is a coin, 6 is a 'regular' die
//
//  int Roll() -- returns the random "roll" of the die, a uniformly
//                distributed random number between 1 and # sides
//    
//  int NumSides() -- access function, returns # of sides
//
//  int NumRolls() -- access function, returns # of times Roll called
//                    for an instance of the class

class Dice
{
  public:
    Dice(int sides);           // constructor
    int Roll();                // return the random roll
    int NumSides() const;      // how many sides this die has
    int NumRolls() const;      // # times this die rolled
    
  private:
    int myRollCount;           // # times die rolled
    int mySides;               // # sides on die
};

#endif    /* _DICE_H not defined */
