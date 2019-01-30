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
#include "bluemen.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
**                  name / attack / defense / armor / strength
*********************************************************************/
BlueMen::BlueMen() :
    Character{"Blue Men",0,0,3,12} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[3];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
BlueMen::~BlueMen() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string BlueMen::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements
*********************************************************************/
void BlueMen::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[3];

    //initialize attack dice
    for (int index = 0; index < 2; index++) {
        attackDice[0][0] = Dice(10);
    }
    // initialize defense dice
    for (int index = 0; index < 3; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int BlueMen::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
    }
    return totalRolled;
}





