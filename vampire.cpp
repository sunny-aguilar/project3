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
**                  attack / defense / armor / strength
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
void Vampire::attackPlayer(Character *defender) {
    cout << "Vampire attacks!" << endl;
    int attackVal = 0;

    // roll dice
    attackVal = rollDice("attack");
    cout << "Attack value " << attackVal << endl << endl;
    attackValue = attackVal;
    cout << "Attack value " << attackVal << endl << endl;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::defend(int attackVal) {
    cout << "Vampire defends!" << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");
    cout << "Damage blocked " << defendValue << endl;

    int damage = attackValue - defendValue - armor;
    if (damage < 0) { damage = 0; }
    cout << "Damage Calc: Attack " << attackValue << " - Defense " << defendValue << " - armor " << armor << endl;
    cout << "Damage sustained " << damage << endl;
}