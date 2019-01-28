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

class Character {
public:
    Character();
    Character(int attacks, int defense, int armor, int strength);
    virtual ~Character();
    virtual void attack() = 0;

protected:
    int attacks;
    int defense;
    int armor;
    int strength;

private:

};

#endif //PROJECT3_CHARACTER_HPP
