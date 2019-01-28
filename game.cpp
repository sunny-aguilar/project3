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
    startGame();

//    if () {
//
//    }
//
//
//    // start game
//    gameFlow();
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::startGame() {
    int sel = menu.validateNumber(1,2);
    switch (sel) {
        case 1:
            // play game
            gameFlow();
            break;
        case 2:
            // quit game
            exitGame();
            break;
        default:
            cout << "Unable to determine your selection!\n";
    }
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::gameFlow() {
    // select player
    selectPlayer();



}



/*********************************************************************
** Description:     d
*********************************************************************/
void Game::selectPlayer() {
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

    // confirm players with user
    int type[2] = {};
    for (int player: {0,1}) {
        type[player] = fighterType[player];
    }
    menu.menuDisplayPlayers(type[0], type[1]);

}


/*********************************************************************
** Description:     d
*********************************************************************/
void Game::exitGame() {
    menu.menuExitGame();
}