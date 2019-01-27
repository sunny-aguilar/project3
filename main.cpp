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
#include "game.hpp"
#include <iostream>

int main() {
    auto seed = static_cast<unsigned int>(time(nullptr));
    srand(seed);                // create random number generator
    Game game;                  // create game object
    game.playGame();            // play the game

    return 0;
}