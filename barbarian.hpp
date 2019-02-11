/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Barbarian class is derived from Character class.
**                  Barbarian has no special abilities to call.
*********************************************************************/
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

class Barbarian : public Character {
public:
    Barbarian();
    ~Barbarian() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void defend() override;
    void specialAbility() override;

private:

};

#endif //PROJECT3_BARBARIAN_HPP