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
#ifndef GAME_HPP
#define GAME_HPP

#include "menu.hpp"
#include "character.hpp"
#include "vampire.hpp"
#include "barbarian.hpp"
#include "bluemen.hpp"
#include "medusa.hpp"
#include <ctime>

enum Fighter {UNSET, VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER};

class Game {
public:
    Game();
    void playGame();
    void startGame();
    void gameFlow();
    void selectPlayer();
    void startCombat();
    bool checkDeath(Character *defender);
    bool playAgain();
    void exitGame();

private:
    Menu menu;
    Fighter fighterType[2];
    Character *playerOne;
    Character *playerTwo;
    int rounds;

};

#endif //PROJECT3_GAME_HPP
