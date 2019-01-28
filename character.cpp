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
Character::Character(int attack, int defense, int armor, int strength) :
    attack{attack},
    defense{defense},
    armor{armor},
    strength{strength},
    attackReceived{0},
    damageInflicted{0} {
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Character::~Character() {}

