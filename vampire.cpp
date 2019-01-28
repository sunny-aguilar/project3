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
#include "vampire.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Vampire::Vampire() :
    Character{1,1,1,18} {
    attackDice = new Dice*[1];
    defenseDice = new Dice*[1];
}


/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Vampire::~Vampire() {}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::initializeDice() {

}

void Vampire::rollDice() {
//    cout << "Vampire Random Int " << attackDice->randomInt() << endl;
//    cout << "Vampire Random Int " << defenseDice->randomInt() << endl;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 1d12.
*********************************************************************/
void Vampire::attack() {
    cout << "Vampire attacks!" << endl;
}