//
// Created by Sandro on 1/29/2019.
//

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "character.hpp"
#include <iostream>
#include <iomanip>
using std::cin;
using std::cout;
using std::endl;
using std::setw;

class HarryPotter : public Character {
public:
    HarryPotter();
    ~HarryPotter() override;
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

#endif //PROJECT3_HARRYPOTTER_HPP
