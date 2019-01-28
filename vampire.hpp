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
using std::cin;
using std::cout;
using std::endl;

class Vampire : public Character {
public:
    Vampire();
    ~Vampire() override;
    void initializeDice() override;
    void attackPlayer(Character *defender) override;
    void defend(int attackVal) override;
    int rollDice(std::string action) override;

private:

};

#endif //PROJECT3_VAMPIRE_HPP
