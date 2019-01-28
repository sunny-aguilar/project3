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
#include "character.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Character::Character() {}

/*********************************************************************
** Description:     constructor that sets the member variables
*********************************************************************/
Character::Character(int attacks, int defense, int armor, int strength) :
    attacks{attacks}, defense{defense}, armor{armor}, strength{strength}{
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Character::~Character() {}

