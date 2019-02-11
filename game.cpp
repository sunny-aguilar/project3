/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
** Description:     Game class holds various classes in it and is the
**                  main driver behind the game. The game flow is
**                  controlled with various functions here and
**                  the menu and character objects live inside the
**                  Game class. Enums are used to provide for more
**                  readable code where possible.
*********************************************************************/
#include "game.hpp"

/*********************************************************************
** Description:     no-args default constructor that sets the member
**                  variables
*********************************************************************/
Game::Game(): fighterType{UNSET}, rounds{0} {}

/*********************************************************************
** Description:     destructor
*********************************************************************/
Game::~Game() {
    // delete players
    delete playerOne;
    delete playerTwo;
}

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
    do {
        // select player
        selectPlayer();

        // create combatant dice
        playerOne->initializeDice();
        playerTwo->initializeDice();

        // start combat
        startCombat();
    } while (playAgain());
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
                {
                    fighterType[player] = VAMPIRE;
                    if (player == 0) {
                        playerOne = new Vampire;
                    }
                    else if (player == 1) {
                        playerTwo = new Vampire;
                    }
                }
                break;
            case 2:
                {
                    fighterType[player] = BARBARIAN;
                    if (player == 0) {
                        playerOne = new Barbarian;
                    }
                    else if (player == 1) {
                        playerTwo = new Barbarian;
                    }
                }
                break;
            case 3:
                {
                    fighterType[player] = BLUEMEN;
                    if (player == 0) {
                        playerOne = new BlueMen;
                    }
                    else if (player == 1) {
                        playerTwo = new BlueMen;
                    }
                }
                break;
            case 4:
                {
                    fighterType[player] = MEDUSA;
                    if (player == 0) {
                        playerOne = new Medusa;
                    }
                    else if (player == 1) {
                        playerTwo = new Medusa;
                    }
                }
                break;
            case 5:
                {
                    fighterType[player] = HARRYPOTTER;
                    if (player == 0) {
                        playerOne = new HarryPotter;
                    }
                    else if (player == 1) {
                        playerTwo = new HarryPotter;
                    }
                }
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
void Game::startCombat() {
    bool playerDead = false;

    do {
        // display banner for each round played
        rounds++;
        menu.menuRound(rounds);

        // first player attacks
        if (!playerDead) {
            playerOne->attackPlayer(playerTwo);
            playerTwo->defend();
            playerTwo->strengthUpdate();
            playerTwo->checkStrength();
            playerDead = checkDeath(playerTwo);
        }
        cout << endl;

        // second player attacks
        if (!playerDead) {
            playerTwo->attackPlayer(playerOne);
            playerOne->defend();
            playerOne->strengthUpdate();
            playerOne->checkStrength();
            playerDead = checkDeath(playerOne);
        }

        // pause between rounds
        cout << "\nHit [ENTER] to continue to next round\n";
        cin.ignore();

    } while (!playerDead);
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool Game::checkDeath(Character *defender) {
    bool playerDied = false;
    if (defender->playerStatus()) {
        menu.menuDeath(defender->getName());
        playerDied = true;
    }
    return playerDied;
}

/*********************************************************************
** Description:     d
*********************************************************************/
bool Game::playAgain() {
    bool selection = false;
    menu.menuPlayAgain();
    switch (menu.validateNumber(1,2)) {
        case 1:
            selection = true;
            rounds = 0;
            break;
        case 2:
            selection = false;
            break;
        default:
            cout << "Unable to determine your choice!\n";
    }
    return selection;
}

/*********************************************************************
** Description:     d
*********************************************************************/
void Game::exitGame() {
    menu.menuExitGame();
}