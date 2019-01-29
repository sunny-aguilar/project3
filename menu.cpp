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
#include "menu.hpp"

/*********************************************************************
** Description:     displays the main menu
*********************************************************************/
void Menu::mainMenu() {
    cout << "+---------------------------------------------------------+\n"
            "|                     /                                   |\n"
            "|            *//////{<>==================-                |\n"
            "|                     \\    WIZARD WARS                    |\n"
            "|                                                         |\n"
            "+---------------------------------------------------------+\n";
    cout << " 1. Start Game\n";
    cout << " 2. Exit\n";
    cout << " >> ";
}

/*********************************************************************
** Description:     displays the menu of characters to choose from
*********************************************************************/
void Menu::menuSelectFighter(int player) {
    cout << "\n SELECT TWO CHARACTERS TO FIGHT\n"
            "+--------------------------------------------------+\n";
    cout << "   1. Vampire class\n";
    cout << "   2. Barbarian class\n";
    cout << "   3. Blue Men class\n";
    cout << "   4. Medusa class\n";
    cout << "   5. Harry Potter class\n";
    cout << "   Player " << player << " >> ";
}

/*********************************************************************
** Description:     displays characters chosen for battle
*********************************************************************/
void Menu::menuDisplayPlayers(int first, int second) {
    string fighterArray[] = {"Vampire", "Barbarian", "Blue Men",
                             "Medusa", "Harry Potter"};

    cout << "\nFirst Combatant - " << fighterArray[first - 1] << endl;
    cout << "Second Combatant - " << fighterArray[second - 1] << endl << endl;
}

/*********************************************************************
** Description:     g
*********************************************************************/
void Menu::menuRound(int round) {
    cout << "\n COMBAT ROUND " << round << "        ====)-------------\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     g
*********************************************************************/
void Menu::menuDeath(string type) {
    cout << "\n >>" << type << " has died!\n"
            "+------- -------------------------------------------+\n\n";
    cout << "                          .\n"
            "                         -|-\n"
            "                          |\n"
            "                     .-'~~~~~~`-.\n"
            "                   .'            `.\n"
            "                   |   R  I  P    |\n"
            "                   |              |\n";
    if (type == "Harry Potter") {
        cout << "                   | " << left << setw(12) << "Harry Potter |\n";
    }
    else {
        cout << "                   |   " << left << setw(9) << type << "  |\n";
    }
    cout << "                   |              |\n"
            "                 \\\\|              |//\n"
            "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n";
}

/*********************************************************************
** Description:     g
*********************************************************************/
void Menu::menuExitGame() {
    cout << "\n EXITING GAME - THANKS FOR PLAYING!\n"
            "+--------------------------------------------------+\n";
}

/*********************************************************************
** Description:     general validator where the parameters are the
**                  min and max numbers acceptable
*********************************************************************/
int Menu::validateNumber(int min, int max) {
    char choice[100];
    int validatedChoice = 0;
    std::stringstream convert;
    bool tooLong = false;
    bool isNotDigit = false;
    bool notInRange = false;

    // determine # of digits in max value acceptable
    long unsigned length = std::to_string(max).length();

    do {
        // store user input
        cin.getline(choice, 100);

        // reject any input that has more than digits than max parameter
        tooLong = false;
        if (strlen(choice) > length) {
            tooLong = true;
            cout << "enter only one number!\n";
        }

        // check if all characters entered are digits
        isNotDigit = false;
        for (unsigned i = 0; i < strlen(choice); i++) {
            // if digit is not a digit, then set it true so that
            // loop will repeat
            if (!isdigit(choice[i])) {
                isNotDigit = true;
            }
        }
        if (isNotDigit) {
            // prompt user to enter only digits
            cout << "enter only digits!\n";
        }

        // check if characters entered are within range
        notInRange = false;
        if (!isNotDigit && !tooLong) {
            convert.clear();
            convert << choice;
            convert >> validatedChoice;

            if (validatedChoice < min || validatedChoice > max) {
                notInRange = true;
                cout << "enter a number between "
                     << min << " or " << max << endl;
            }
        }
    } while (tooLong || isNotDigit || notInRange);

    return validatedChoice;
}