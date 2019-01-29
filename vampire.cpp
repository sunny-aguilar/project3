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
    Character{0,0,1,18} {
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
    attack = 0;

    // roll dice
    attack = rollDice("attack");
    cout << "Attack value " << attack << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     sets the attack damage received
*********************************************************************/
void Vampire::setAttackVal(int val) {
    attack = val;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::defend() {
    cout << "Vampire defends!" << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }
    cout << "Damage Calc: Attack " << attack
         << " - Defense " << defendValue << " - armor "
         << armor << endl;

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::strengthUpdate() {
    cout << "Damage sustained " << damageReceived << endl;
    strength -= damageReceived;
    cout << "Strength remaining " << strength << endl;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::checkStrength() {
    if (strength < 1) {
        playerAlive = false;
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool Vampire::playerStatus() {
    return playerAlive;
}

