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
#include "medusa.hpp"
/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
**                  name / attack / defense / armor / strength
*********************************************************************/
Medusa::Medusa() :
    Character{"Medusa",0,0,3,8} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[3];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Medusa::~Medusa() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string Medusa::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 2d6, defense 1d6.
*********************************************************************/
void Medusa::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[3];

    //initialize attack dice
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    // initialize defense dice
    for (int index = 0; index < 3; index++) {
        defenseDice[0][index] = Dice(6);
    }
}







