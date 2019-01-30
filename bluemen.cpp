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
#include "bluemen.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
**                  name / attack / defense / armor / strength
*********************************************************************/
BlueMen::BlueMen() :
    Character{"Blue Men",0,0,3,12} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[3];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
BlueMen::~BlueMen() {}

/*********************************************************************
** Description:     d
*********************************************************************/
string BlueMen::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements
*********************************************************************/
void BlueMen::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[3];

    //initialize attack dice
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(10);
    }
    // initialize defense dice
    for (int index = 0; index < 3; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int BlueMen::rollDice(std::string action) {
    int totalRolled = 0;
    if (action == "attack") {
        totalRolled += attackDice[0][0].randomInt();
        totalRolled += attackDice[0][1].randomInt();
    }
    else if (action == "defend") {
        totalRolled += defenseDice[0][0].randomInt();
        totalRolled += defenseDice[0][1].randomInt();
        totalRolled += defenseDice[0][2].randomInt();
    }
    return totalRolled;
}

/*********************************************************************
** Description:     polymorphic function for attacking. Attack value
**                  is 2d10.
*********************************************************************/
void BlueMen::attackPlayer(Character *defender) {
    cout << ">>Blue Men attacks!    -|---" << endl;
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
void BlueMen::setAttackVal(int val) {
    attack = val;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BlueMen::defend() {
    cout << ">>Blue Men defends!    )))" << endl;
    cout << "Strength points " << strength << endl << endl;
    int defendValue = 0;

    // special defense **Mob**
    // blue men loses 1 dice for every 4 points of damage
    specialAbility();


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
** Description:     special ability
*********************************************************************/
void BlueMen::specialAbility() {
    useSpecial = true;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BlueMen::strengthUpdate() {
    strength -= damageReceived;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void BlueMen::checkStrength() {
    if (strength < 1) {
        playerDead = true;
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool BlueMen::playerStatus() {
    return playerDead;
}



