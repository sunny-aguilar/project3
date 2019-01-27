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
Game::Game(): fighterType{UNSET} {}

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
    // show main menu
    menu.mainMenu();
    startGame(menu.validateNumber(1,2));

    // start game
    gameFlow();
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::startGame(int sel) {
    switch () {
        
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::gameFlow() {
    // initialize fighters chosen to fight
    for (int player: {0,1}) {
        menu.menuSelectFighter(player+1);
        switch (menu.validateNumber(1,5)) {
            case 1:
                fighterType[player] = VAMPIRE;
                break;
            case 2:
                fighterType[player] = BARBARIAN;
                break;
            case 3:
                fighterType[player] = BLUEMEN;
                break;
            case 4:
                fighterType[player] = MEDUSA;
                break;
            case 5:
                fighterType[player] = HARRYPOTTER;
                break;
            default:
                cout << "Unable to determine fighter type\n";
        }
    }

    for (int player: {0,1}) {
        cout << "Fighter type " << fighterType[player] << " ";
    }

}
