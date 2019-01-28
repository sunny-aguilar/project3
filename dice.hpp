/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 2019
** Description:     PROJECT 3
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/
#ifndef DICE_HPP
#define DICE_HPP

#include <iostream>
#include <ctime>
#include <vector>
using std::vector;

class Dice {
public:
    Dice();                          // default constructor
    Dice(int num);                   // 1-arg constructor
    int randomInt();                // returns a random integer
    void setSides(int sides);       // setter that sets die sides
    int getSides();                 // getter that returns die sides

protected:
    int N;                          // number of sides on the die
};

#endif //PROJECT3_DICE_HPP
