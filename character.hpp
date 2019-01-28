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
#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "dice.hpp"

class Character {
public:
    Character();
    Character(int attacks, int defense, int armor, int strength);
    virtual ~Character();
    virtual void initializeDice() = 0;
    virtual void attack(Character *defender) = 0;
    virtual void defend() = 0;
    virtual int rollDice(std::string action) = 0;

protected:
    int attacks;
    int defense;
    int armor;
    int strength;
    Dice **attackDice;
    Dice **defenseDice;

private:

};

#endif //PROJECT3_CHARACTER_HPP
