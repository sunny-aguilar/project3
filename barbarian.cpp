/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
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
Barbarian::Barbarian() :
    Character{"Barbarian",0,0,0,12} {
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
string Barbarian::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 2d6, defense 2d6.
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

/*********************************************************************
** Description:     d
*********************************************************************/
int Barbarian::rollDice(std::string action) {
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
    cout << ">>Barbarian attacks!    -|---" << endl;
    attack = 0;

    // roll dice
    attack = rollDice("attack");
    cout << "Deals " << attack << " attack points (2d6)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Barbarian::defend() {
    cout << ">>Barbarian defends!    )))" << endl;
    cout << setw(2) << strength << "- Strength points " << endl << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }

    // display damage received report
    cout << "Defense blocked " << defendValue << " attack points (2d6)\n";

    cout << setw(2) << attack << " - attack points\n";
    cout << setw(2) << defendValue << " - defense block\n";
    cout << setw(2) << armor << " - armor block\n";
    cout << setw(2) << damage << " - damage inflicted\n";
    cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Barbarian::specialAbility() {
    // barbarian has no special ability
}