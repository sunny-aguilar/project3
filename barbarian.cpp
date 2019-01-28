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
**                  attack / defense / armor / strength
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
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[2];

    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    for (int index = 0; index < 2; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

int Barbarian::rollDice(std::string action) {
//    cout << "Barbarian Attack Dice One " << attackDice[0][0].randomInt() << endl;
//    cout << "Barbarian Attack Dice Two " << attackDice[0][1].randomInt() << endl;
//    cout << "Barbarian Defense Dice One " << defenseDice[0][0].randomInt() << endl;
//    cout << "Barbarian Defense Dice One " << defenseDice[0][1].randomInt() << endl;

    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
        totalRolled += attackDice[0][1].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
        totalRolled += defenseDice[0][1].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d6.
*********************************************************************/
void Barbarian::attackPlayer(Character *defender) {
    cout << "Barbarian attacks!" << endl;
    int attackVal = 0;

    // roll dice
    attackVal = rollDice("attack");
    cout << "Attack value " << attackVal << endl << endl;
    attackValue = attackVal;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Barbarian::defend() {
    cout << "Barbarian defends!" << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");
    cout << "Damage blocked " << defendValue << endl << endl;

    int damage = attackValue - defendValue - armor;
    if (damage < 0) { damage = 0; }
    cout << "Damage sustained " << damage << endl;
}