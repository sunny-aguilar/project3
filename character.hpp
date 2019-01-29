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
#include <string>
using std::string;

class Character {
public:
    Character();
    Character(string name, int attack, int defense, int armor, int strength);
    virtual ~Character();
    virtual string getName() = 0;
    virtual void initializeDice() = 0;
    virtual int rollDice(std::string action) = 0;
    virtual void attackPlayer(Character *defender) = 0;
    virtual void setAttackVal(int val) = 0;
    virtual void defend() = 0;
    virtual void strengthUpdate() = 0;
    virtual void checkStrength() = 0;
    virtual bool playerStatus() = 0;

protected:
    string name;
    int attack;
    int defense;
    int armor;
    int strength;
    int damageReceived;
    bool playerDead;
    Dice **attackDice;
    Dice **defenseDice;

private:

};

#endif //PROJECT3_CHARACTER_HPP
