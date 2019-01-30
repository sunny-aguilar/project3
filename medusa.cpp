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

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
Medusa::~Medusa() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string Medusa::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 2d6, defense 1d6.
*********************************************************************/
void Medusa::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[1];

    //initialize attack dice
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    // initialize defense dice
    for (int index = 0; index < 1; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int Medusa::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
        totalRolled += attackDice[0][1].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d10.
*********************************************************************/
void Medusa::attackPlayer(Character *defender) {
    cout << ">>Medusa attacks!    -|---" << endl;
    attack = 0;

    // roll dice
    attack = rollDice("attack");
    cout << "Gets ready to deal " << attack << " attack points (1d12)" << endl << endl;

    // special attack **Glare**
    specialAbility();
    if (useSpecial) {
        attack = 1000;
    }

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     sets the attack damage received. If Medusa rolls
 *                  a 12, then she uses her *Glare* special ability
*********************************************************************/
void Medusa::setAttackVal(int val) {
    attack = val;
}

/*********************************************************************
** Description:     special ability
*********************************************************************/
void Medusa::specialAbility() {
    if (attack == 12) {
        useSpecial = true;
        cout << "Opponent has caught Medusa's glare "
                "and turned into stone!\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Medusa::defend() {
    cout << ">>Medusa defends!    )))" << endl;
    cout << "Strength points " << strength << endl << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }
    cout << "Defense blocked " << defendValue << " attack points\n";

    cout << setw(2) << attack << " - attack points\n";
    cout << setw(2) << defendValue << " - defense block (1d6)\n";
    cout << setw(2) << armor << " - armor block\n";
    cout << setw(2) << damage << " - damage inflicted\n";
    cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Medusa::strengthUpdate() {
    strength -= damageReceived;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Medusa::checkStrength() {
    if (strength < 1) {
        playerDead = true;
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool Medusa::playerStatus() {
    return playerDead;
}