/*********************************************************************
** Author:          Sandro Aguilar
** Date:            Feb 15, 2019
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
#ifndef MENU_HPP
#define MENU_HPP

#include <iostream>
#include <string>
#include <cstring>
#include <sstream>
#include <iomanip>
using std::string;
using std::setw;
using std::left;
using std::cin;
using std::cout;
using std::endl;

class Menu {
public:
    void mainMenu();
    void menuSelectFighter(int player);
    int validateNumber(int min, int max);
    void menuDisplayPlayers(int fighter1, int fighter2);
    void menuRound(int round);
    void menuDeath(string type);
    void menuPlayAgain();
    void menuExitGame();

private:
};

#endif //PROJECT3_MENU_HPP