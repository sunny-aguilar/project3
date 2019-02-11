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
*********************************************************************/
#include "harrypotter.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
**                  name / attack / defense / armor / strength
*********************************************************************/
HarryPotter::HarryPotter() :
    Character{"Harry Potter",0,0,0,10},
    hogwartsUsed{false} {
    attackDice = new Dice*[2];
    defenseDice = new Dice*[3];
}

/*********************************************************************
** Description:     virtual destructor
*********************************************************************/
HarryPotter::~HarryPotter() { hogwartsUsed = false; }

/*********************************************************************
** Description:     d
*********************************************************************/
string HarryPotter::getName() {
    return name;
}

/*********************************************************************
** Description:     initializes dice based on character dice
**                  requirements. Attack dice 2d6, defense 2d6.
*********************************************************************/
void HarryPotter::initializeDice() {
    attackDice[0] = new Dice[2];
    defenseDice[0] = new Dice[2];

    //initialize attack dice - 2d6
    for (int index = 0; index < 2; index++) {
        attackDice[0][index] = Dice(6);
    }
    // initialize defense dice - 2d6
    for (int index = 0; index < 2; index++) {
        defenseDice[0][index] = Dice(6);
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
int HarryPotter::rollDice(std::string action) {
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
void HarryPotter::attackPlayer(Character *defender) {
    cout << ">>Harry Potter attacks!    -|---" << endl;
    attack = 0;

    // roll dice
    attack = rollDice("attack");
    cout << "Gets ready to deal " << attack << " attack points (2d6)" << endl << endl;

    // send attack value to defender object
    defender->setAttackVal(attack);
}

/*********************************************************************
** Description:     d
*********************************************************************/
void HarryPotter::defend() {
    cout << ">>Harry Potter defends!    )))" << endl;
    cout << setw(2) << strength << " - Strength points " << endl << endl;
    int defendValue = 0;



    // roll dice
    defendValue = rollDice("defend");

    // calculate net damage received
    int damage = attack - defendValue - armor;
    if (damage < 0) { damage = 0; }
    cout << "Defense blocked " << defendValue << " attack points (2d6)\n";

    cout << setw(2) << attack << " - attack points\n";
    cout << setw(2) << defendValue << " - defense block\n";
    cout << setw(2) << armor << " - armor block\n";
    cout << setw(2) << damage << " - damage inflicted\n";
    cout << setw(2) << strength - damage << " - ending strength points\n\n";

    // special defense **Hogwarts**
    if ((strength - damage < 1) && !hogwartsUsed) {
        specialAbility();
        cout << "Harry Potter's strength points have dropped below 1 and has died!\n";
        cout << "Harry Potter has used Hogwarts and is alive again with strength 20!\n";
        strength = 20;
        hogwartsUsed = true;
    }
    else {
        // update player strength
        damageReceived = damage;

        // if Hogwarts ability already used, prompt user
        if (hogwartsUsed) {
            cout << "Harry Potter cannot used Hogwarts again!\n";
        }
    }


}

/*********************************************************************
** Description:     special ability
*********************************************************************/
void HarryPotter::specialAbility() {
    useSpecial = true;
}