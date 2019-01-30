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











