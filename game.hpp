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
#include <ctime>

enum Fighter {UNSET, VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER};

class Game {
public:
    Game();
    void playGame();
    void startGame(int sel);
    void gameFlow();

private:
    Menu menu;
    Fighter fighterType[2];
    Character *playerOne;
    Character *playerTwo;

};

#endif //PROJECT3_GAME_HPP
