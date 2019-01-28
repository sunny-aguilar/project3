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
#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "character.hpp"
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

class Barbarian : public Character {
public:
    Barbarian();
    ~Barbarian() override;
    void initializeDice() override;
    int rollDice(std::string action) override;
    void attackPlayer(Character *defender) override;
    void setAttackVal(int val) override;
    void defend() override;

private:

};

#endif //PROJECT3_BARBARIAN_HPP
