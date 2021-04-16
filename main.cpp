/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: This program runs a Zoo Tycoon game.  User can purchase animals to have in their zoo.
 * User must feed their animals once per day, and random events can occur which bring in more profit,
 * have animal births that increase zoo population, and have animal deaths that decrease zoo population.
 * Each day, the zoo's profit is calculated, then the user can purchase more animals and contineu to
 * next day or quit the game. If the user's bank account os below $0 after the day ends, then user is bankrupt
 * and the game is over.
*********************************************************************/

#include <iostream>
#include<sstream>
#include "zoo.hpp"
#include<cstdlib>
#include<ctime>

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;


int main() {

    srand(time(NULL)); // used to set time for random function

    cout << "*****Zoo Tycoon Main Menu*****" << endl;
    cout << "1. Start Zoo Tycoon" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter Choice: " << endl;

// obtain user's choice and perform input validation on choice
    bool errFlag = false;
    string input;
    int validInteger;
    do {
        getline(cin, input);
        stringstream sStream(input);

        if (sStream >> validInteger && !(sStream >> input))
        {

            if (validInteger != 1 && validInteger != 2)
            {
                cout << "please enter 1 or 2" << endl;
            }
            else
            {
                errFlag = true;
            }
        }
        else
        {
            cout << "Please enter 1 or 2" << endl;
        }

    } while (errFlag == false);

    switch (validInteger) {

        case 1: {
            cout << "Start Zoo Tycoon Game was selected" << endl;
            cout << endl;
            Zoo *newGame = new Zoo; // create new Zoo object
            newGame->startGame(); // start the game
            delete newGame; // deallocate memory
            break;
        }
        case 2: {
            cout << "Zoo Tycoon Game is quitting. Goodbye." << endl;
            break;
        }
        default: {
            cout << "Invalid menu choice, choose again." << endl;
            break;

        }
    }
return 0;
}
