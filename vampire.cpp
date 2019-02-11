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
#include "vampire.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
**                  name / attack / defense / armor / strength
*********************************************************************/
Vampire::Vampire() :
    Character{"Vampire",0,0,1,18} {
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
string Vampire::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 1d12, defense 1d6.
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

/*********************************************************************
** Description:     d
*********************************************************************/
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
    cout << ">>Vampire attacks!    -|---" << endl;
    attack = 0;

    // roll dice
    attack = rollDice("attack");
    cout << "Gets ready to deal " << attack << " attack points (1d12)" << endl << endl;

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
    cout << ">>Vampire defends!    )))" << endl;
    cout << strength << " - Strength points " << endl << endl;
    int defendValue = 0;

    // special defense **CHARM**
    specialAbility();

    // display damage received report
    if (useSpecial) {
        attack = 0;
        cout << "Vampire has charmed his opponent and was not attacked!\n";
        cout << strength << " - ending strength points\n\n";
        // reset special ability after use
        useSpecial = false;
    }
    else if (!useSpecial) {

        // roll dice
        defendValue = rollDice("defend");

        // calculate net damage received
        int damage = attack - defendValue - armor;
        if (damage < 0) { damage = 0; }
        cout << "Defense blocked " << defendValue << " attack points (1d6)\n";

        cout << setw(2) << attack << " - attack points\n";
        cout << setw(2) << defendValue << " - defense block (1d6)\n";
        cout << setw(2) << armor << " - armor block\n";
        cout << setw(2) << damage << " - damage inflicted\n";
        cout << setw(2) << strength - damage << " - ending strength points\n\n";

        // update player strength
        damageReceived = damage;
    }
}

/*********************************************************************
** Description:     special ability
*********************************************************************/
void Vampire::specialAbility() {

    Dice dice(2);
    int num = dice.randomInt();
    if (num == 1) {
        useSpecial = true;
    }
    else if (num == 2) {
        useSpecial = false;
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::strengthUpdate() {
    strength -= damageReceived;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Vampire::checkStrength() {
    if (strength < 1) {
        playerDead = true;
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool Vampire::playerStatus() {
    return playerDead;
}

