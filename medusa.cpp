/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Medusa class is derived from Character. Medusa
**                  has a special offensive ability that allows her
**                  to immediately defeat her opponents upon rolling
**                  an attack dice of 12. Medusa has attack dice of
**                  2d6 and defense dice of 1d6. Vampire's charm
**                  trumps Medusa's glare.
*********************************************************************/
#include "medusa.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables as follows:
**                  name / attack / defense / armor / strength
**                  Attack Dice: 2d6, Defense Dice: 1d6
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
    // reset attack power to zero
    attack = 0;
    // roll attack dice
    attack = rollDice("attack");
    cout << ">>Medusa attacks!    -|---" << endl;
    cout << "Places a curse with an attack power of " << attack << " points (2d6)" << endl << endl;

    // special attack **Glare**
    specialAbility();
    if (useSpecial) {
        attack = 1000;
        useSpecial = false;
    }

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Medusa::defend() {
    cout << ">>Medusa defends!    )))" << endl;
    cout << setw(2) << strength << " - Starting strength points " << endl << endl;
    int defendValue = 0;

    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }

    // display damage received report
    cout << "Defense blocked " << defendValue << " attack points (1d6)\n";
    cout << setw(2) << attack << " - attack points\n";
    cout << setw(2) << defendValue << " - defense block (1d6)\n";
    cout << setw(2) << armor << " - armor block\n";
    cout << setw(2) << damage << " - net damage inflicted\n";
    cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // update player strength
    damageReceived = damage;
}

/*********************************************************************
** Description:     special ability allows Medusa to GLare at her
**                  opponents immediately defeating them
*********************************************************************/
void Medusa::specialAbility() {
    if (attack == 12) {
        useSpecial = true;
        cout << "Opponent has caught Medusa's glare "
                "and turned into stone!\n";
    }
}