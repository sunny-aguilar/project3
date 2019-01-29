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
#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include "character.hpp"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

class Vampire : public Character {
public:
    Vampire();
    ~Vampire() override;
    string getName() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void setAttackVal(int val) override;
    void defend() override;
    void strengthUpdate() override;
    void checkStrength() override;
    bool playerStatus() override;
    void specialAbility() override;

private:

};

#endif //PROJECT3_VAMPIRE_HPP
