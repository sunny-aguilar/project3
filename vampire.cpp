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
    attackDice[0] = new Dice[1];
    defenseDice[0] = new Dice[1];

    for (int index = 0; index < 1; index++) {
        attackDice[0][0] = Dice(12);
    }

    for (int index = 0; index < 1; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

int Vampire::rollDice(std::string action) {
//    cout << "Vampire Attack Dice " << attackDice[0][0].randomInt() << endl;
//    cout << "Vampire Defense Dice " << defenseDice[0][0].randomInt() << endl;

    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 1d12.
*********************************************************************/
void Vampire::attack(Character *defender) {
    cout << "Vampire attacks!" << endl;
    int attackValue = 0;

    // roll dice
    attackValue = rollDice("attack");
    cout << "Attack value " << attackValue << endl;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::defend() {
    cout << "Vampire defends!" << endl;
    int defendValue = 0;

}