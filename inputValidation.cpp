/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: Input Validation holds a function to check if user's initial animal purchase is valid.
*********************************************************************/

#include "inputValidation.hpp"
#include "zoo.hpp"
#include "animal.hpp"
#include<iostream>
#include<sstream>


using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;

// checks if initial animal purchase is either a quantity of 1 or 2
int checkAnimalPurchase(int animalCount) {
    bool errFlag = false;
    string input;
    do {
        getline(cin, input);
        stringstream sStream(input);

        if (sStream >> animalCount && !(sStream >> input)) {

            if (animalCount < 1 || animalCount > 2) {
                cout << "invalid, please select either 1 or 2 animals to purchase." << endl;
            } else {
                errFlag = true;
            }
        } else {
            cout << "invalid, please select either 1 or 2 animals to purchase." << endl;
        }

    } while (errFlag == false);
    return animalCount;
}

