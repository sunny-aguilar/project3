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
#include "Dice.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the number
**                  of sides on the die
*********************************************************************/
Die::Die() : N{0} {}

/*********************************************************************
** Description:     1-arg constructor that takes an int parameter to
**                  set the number of sides on the die
*********************************************************************/
Die::Die(int num) : N{num} {}

/*********************************************************************
** Description:     returns a random integer from 1 to N
*********************************************************************/
int Die::randomInt() {
    int randomNum;              // hold random number
    randomNum = rand() % N + 1; // computer random # from 1 to N
    return randomNum;           // return random integer
}

/*********************************************************************
** Description:     setter that takes an int parameter to set the
**                  sides of N
*********************************************************************/
void Die::setSides(int sides) {
    N = sides;
}

/*********************************************************************
** Description:     getter that returns N
*********************************************************************/
int Die::getSides() {
    return N;
}