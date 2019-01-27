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

class Game {
public:
    Game();
    void playGame();
    void gameFlow();

private:
    Menu menu;
    int p1CharType;
    int p2CharType;
    Character *playerOne;
    Character *playerTwo;

};

#endif //PROJECT3_GAME_HPP
