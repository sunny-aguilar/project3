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
#include "barbarian.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Barbarian::Barbarian() : Character{1,1,0,12} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[2];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Barbarian::~Barbarian() {}


/*********************************************************************
** Description:     d
*********************************************************************/
void Barbarian::initializeDice() {

}

void Barbarian::rollDice() {
    cout << "Barbarian Attack Dice One " << attackDice[0][0].randomInt() << endl;
    cout << "Barbarian Attack Dice Two " << attackDice[0][1].randomInt() << endl;
    cout << "Barbarian Defense Dice One " << defenseDice[0][0].randomInt() << endl;
    cout << "Barbarian Defense Dice One " << defenseDice[0][1].randomInt() << endl;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d6.
*********************************************************************/
void Barbarian::attack() {
    cout << "Barbarian attacks!" << endl;
}