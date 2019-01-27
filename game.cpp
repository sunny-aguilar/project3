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

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game(): fighterType{0} {}

/*********************************************************************
** Description:     this function is called from main to get the game
**                  started.
**                  d
**                  d
**                  d
**                  d
**                  d
*********************************************************************/
void Game::playGame() {

    gameFlow();
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::gameFlow() {
    // initialize fighters chosen to fight
    for (int player: {0,1}) {
        menu.mainMenu();
        fighterType[player] = menu.validateNumber(1,5);
    }

    for (int player: {0,1}) {
        cout << "Fighter type " << fighterType[player] << " ";
    }

}
