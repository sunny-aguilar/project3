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
#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "character.hpp"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

class Medusa : public Character {
public:
    Medusa();
    ~Medusa() override;
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

#endif //PROJECT3_MEDUSA_HPP
