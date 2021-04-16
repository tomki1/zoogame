/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The Zoo class holds the zoo game functions and variables.  It shows each day's menu
 * and functions. It includes functions to add and delete animamls from the zoo through use of arrays. It keeps
 * tracks of the animals in the zoo, animal ages, user's money, food costs, and profit. It also generates a random
 * event each day that may affect animal count or profit.  It also has a function that can display the number
 * of animals in the zoo and show the final results of the game.
*********************************************************************/

#include "zoo.hpp"

// default constructor
Zoo::Zoo() {

    tigerSize = 10; // initial dynamic array size for tiger
    penguinSize = 10; // initial dynamic array size for penguin
    turtleSize = 10; // initial dynamic array size for turtle

    dayCount = 1; // dayCount starts at day 1
    money = 100000; // money in bank starts at 100000
    baseFoodCost = 20; // base food cost is $20

    tigerNum = 0; // number of tigers in zoo
    penguinNum = 0; // number of penguins in zoo
    turtleNum = 0; // number of turtles in zoo

    quitFlag = false; // flag used for quitting the game

    attendance = false; // flag used for random event if attendance boom

    animalIll = false; // flag used for random event if animal is ill
    tigerIll = false; // flag used for random event if tiger is ill
    penguinIll = false; // flag used for random event if penguin is ill
    turtleIll = false; // flag used for random event if turtle is ill

    animalBorn = false; // flag used for random event if animal is born
    tigerBorn = false; // flag used for random event if tiger is born
    penguinBorn = false; // flag used for random event if penguin is born
    turtleBorn = false; // flag used for random event if turtle is born
}

// destructor to dellocate memory
Zoo::~Zoo() {
for (int b = 0; b < 3; b++) {
    delete [] animals[b];
}

    delete [] animals;
}


// function to hold main game functions
void Zoo::startGame() {

    cout << "***Current Day: " << dayCount << "***" << endl;
    cout << "You have $100000. You need to buy animals and food to start your zoo." << endl;
    cout << "Base Food cost is $20.  You need to feed each animal once per day.  Tiger food costs " << endl;
    cout << "$100 per tiger, penguin food costs $20 per penguin, and turtle food costs $10 per turtle. " << endl;
    cout << "Food costs will be subtracted from your balance at the end of each day." << endl;
    cout << "Each day, a random event may occur which could result in bonus payoff, animal births, or an animal death."
            << endl;
    cout << "Your animals generate profit each day. One tiger generates $2000 each day, one penguins generates" << endl;
    cout << "$100 each day, and one turtle generates $5 each day." << endl;
    cout << "You may also purchase one animal at the end of each day." << endl;
    cout << "If your money goes below $0, you are bankrupt and the game ends. Good luck!" << endl;
    cout << "You must buy a quantity of  1-2 of each animal on Day 1." << endl;
    cout << endl;
    cout << "Animal Costs:" << endl;
    cout << "Tiger: $10000" << endl;
    cout << "Penguin: $1000" << endl;
    cout << "Turtle: $100" << endl;
    cout << endl;

    // create Animal 2D array of 3 to hold the 3 animal arrays
    animals = new Animal *[3];

    cout << "How many tigers would you like to buy?" << endl;
    tigerNum = checkAnimalPurchase(tigerNum);
    animals[0] = new Tiger[10]; // create new tiger array of size 10
    for (int b = 0; b < tigerNum; b++) {
        animals[0][b] = Tiger(1); // put new tigers in array and set new tiger age to 1
    }


    cout << "How many penguins would you like to buy?" << endl;
    penguinNum = checkAnimalPurchase(penguinNum);
    animals[1] = new Penguin[10]; // create new penguin array of size 10
    for (int b = 0; b < penguinNum; b++) {
        animals[1][b] = Penguin(1); // put new penguins in array and set new penguin age to 1
    }


    cout << "How many turtles would you like to buy?" << endl;
    turtleNum = checkAnimalPurchase(turtleNum);
    animals[2] = new Turtle[10]; // create new turtle array of size 10
    for (int b = 0; b < turtleNum; b++) {
        animals[2][b] = Turtle(1); // put new turtles in array and set new turtle age to 1
    }


// subtract purchases from bank
    money = money - (10000 * tigerNum) - (1000 * penguinNum) - (100 * turtleNum); // subtract animal cost from bank
    cout << endl;
    cout << "Remaining balance after purchase of animals $" << showMoney() << endl;

    cout << "***Food Costs***" << endl;
    FoodCost(); // calculate and subtract food costs from bank
    cout << endl;
    randomEvent(); // generate random event and impelement
    cout << endl;
    animalPayoff(); // calculate animal payoff and add to bank
    cout << endl;

    babyAnimalCount(); // count amount of adult and baby animals and print
    cout << endl;


    cout << "Do you want to continue to next day or quit the game?" << endl;
    cout << "1. Continue to next day" << endl;
    cout << "2. Quit" << endl;
    cout << "Enter Choice: " << endl;

// obtain user's choice and perform input validation on choice
    bool errFlag = false;
    string input;
    int validInteger1;
    do {
        getline(cin, input);
        stringstream sStream(input);

        if (sStream >> validInteger1 && !(sStream >> input)) {

            if (validInteger1 != 1 && validInteger1 != 2) {
                cout << "please enter 1 or 2" << endl;
            } else {
                errFlag = true;
            }
        } else {
            cout << "Please enter 1 or 2" << endl;
        }

    } while (errFlag == false);

    if (validInteger1 == 1) {
        validInteger1 = 1;
    } else if (validInteger1 == 2) {
        cout << "You have selected to quit the game." << endl;
        validInteger1 = 2;
    }

    // if user wants to continue game, call next day function if not bankrupt
    if (validInteger1 == 1) {
        do {
            nextDay(); // call to next day function

        } while ((money > 0) && (quitFlag == false));

        if (showMoney() <= 0) { // if user has less than $0, display bankrupt message and final results
            cout << "You are bankrupt. The game is over." << endl;
        }

        cout << endl;
        cout << "****Final Results****" << endl;
        cout << "Your zoo was opened for " << dayCount << " days." << endl;
        cout << "Your balance: $" << showMoney() << endl;
        babyAnimalCount(); // call to animal count function which prints animal count
        cout << "Thank you for playing Zoo Tycoon. Goodbye." << endl;

    }
    // if user wants to quit game, display final results
    else if (validInteger1 == 2) {
        cout << endl;
        cout << "****Final Results****" << endl;
        cout << "Your zoo was opened for " << dayCount << " days." << endl;
        cout << "Your balance: $" << showMoney() << endl;
        babyAnimalCount(); // call to animal count function which prints animal count
        cout << "Thank you for playing Zoo Tycoon. Goodbye." << endl;
    }
}

// return user's bank account balance
int Zoo::showMoney() {

    return money;

}

// starts the next day and continues until user is bankrupt or quits the game
void Zoo::nextDay() {
dayCount++;
    cout << endl;
    cout << "***Current day: " << dayCount << "***" << endl;
    cout << "Starting budget for the day: $" << showMoney() << endl;
    increaseAnimalAge(); // increase age of animals buy 1 day
    FoodCost(); // calculate and subtract food costs from bank
    cout << endl;
    randomEvent();   // generate random event and impelement
    cout << endl;
    animalPayoff(); // calcualte animal payoff and add to bank account
    cout << endl;
    buyMoreAnimal(); // ask user if they would like to buy 1 adult animal
    cout << endl;
    babyAnimalCount(); // count amount of adult and baby animals and print
    cout << endl;

    cout << endl;
    cout << "Do you want to continue to next day or quit the game?" << endl;
    cout << "1. Continue to next day" << endl;
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

    if (validInteger == 1) {
        quitFlag = false;
    }
    else if (validInteger == 2) {
        cout << "You have selected to quit the game." << endl;
        quitFlag = true;
    }

}

// increase age of animals by one day
void Zoo::increaseAnimalAge() {

    for (int b = 0; b < tigerNum; b++) {
        animals[0][b].addOneAge();
    }


    for (int b = 0; b < penguinNum; b++) {
        animals[1][b].addOneAge();
    }

    for (int b = 0; b < turtleNum; b++) {
        animals[2][b].addOneAge();
    }

}

// ask user if they would like to buy 1 adult animal and add their selection to the zoo
void Zoo::buyMoreAnimal() {
    cout << "It is the end of the day. You may purchase 1 adult animal." << endl;
    cout << "Your current balance is: $" << showMoney() << endl;
    cout << "1. Purchase tiger for $10000" << endl;
    cout << "2. Purchase penguin for $1000" << endl;
    cout << "3. Purchase turtle for $100" << endl;
    cout << "4. do not purchase any animals" << endl;
    cout << "Enter Choice: " << endl;

    bool errFlag = false;
    string input;
    int validInteger;
    do {
        getline(cin, input);
        stringstream sStream(input);

        if (sStream >> validInteger && !(sStream >> input)) {

            if (validInteger != 1 && validInteger != 2 && validInteger != 3 && validInteger != 4) {
                cout << "please enter 1, 2, 3 or 4" << endl;
            } else {
                errFlag = true;
            }
        } else {
            cout << "Please enter 1, 2, 3, or 4" << endl;
        }

    } while (errFlag == false);

    switch (validInteger) {

        // if tiger is bought, subtract tiger cost from bank account and add 1 adult tiger to zoo
        case 1: {
            money -= 10000;
            cout << endl;
            cout << "Your purchased 1 adult tiger. Your new balance is: $" << showMoney() << endl;

            tigerNum += 1;


            // resize array if tigers is greater than original array
            if (tigerNum > tigerSize) {

                int newSize = 2 * tigerSize;
                tigerSize = newSize;
                Animal *newArray = new Tiger[tigerSize]; // create new Tiger array
                for (int b = 0; b < tigerNum; b++) {
                    newArray[b] = animals[0][b]; // move old array entries to new array

                }
                delete[] animals[0]; // delete old array
                animals[0] = newArray; // replace old array with new array

            }


            animals[0][tigerNum - 1] = Tiger(3); // set age of new tiger to adult
            break;

        }

        // if penguin is bought, subtract penguin cost from bank account and add 1 adult penguin to zoo
        case 2: {
            money -= 1000;
            cout << endl;
            cout << "Your purchased 1 adult penguin. Your new balance is: $" << showMoney() << endl;

            penguinNum += 1;

            // resize array if penguin is greater than original array
            if (penguinNum > penguinSize) {

                int newSize = 2 * penguinSize;
                penguinSize = newSize;
                Animal *newArray = new Penguin[penguinSize]; // create new Penguin array
                for (int b = 0; b < penguinNum; b++) {
                    newArray[b] = animals[1][b]; // move old array entries to new array

                }
                delete[] animals[1]; // delete old array
                animals[1] = newArray; // replace old array with new array
            }

                animals[1][penguinNum - 1] = Penguin(3); // set age of new penguin to adult
                break;

            }

        // if turtle is bought, subtract penguin cost from bank account and add 1 turtle penguin to zoo
        case 3: {
            money -= 100;
            cout << endl;
            cout << "Your purchased 1 adult turtle. Your new balance is: $" << showMoney() << endl;

            turtleNum += 1;

        // resize array if turtle is greater than original array
        if (turtleNum > turtleSize) {

            int newSize = 2 * turtleSize;
            turtleSize = newSize;
            Animal *newArray = new Turtle[turtleSize]; // create new Tutle array
            for (int b = 0; b < turtleNum; b++) {
                newArray[b] = animals[2][b]; // move old array entries to new array

            }

            delete[] animals[2]; // delete old array
            animals[2] = newArray; // replace old array with new array
        }
            animals[2][turtleNum - 1] = Turtle(3); // set age of new turtle to adult
            break;

        }

        // purchase no animals
        case 4: {
            cout << "You do not want to purchase any animals today" << endl;
            break;

        }

        default: {
            cout << "Invalid menu choice, choose again." << endl;
            break;

                }
            }
        }


// show total amount of animals, including how many baby animals and how many adult animals
void Zoo::showZooStats(int babyTigerNum, int babyPenguinNum, int babyTurtleNum) {
    cout << endl;
    cout << "***Zoo stats at the end of day " << dayCount << "***" << endl;
    cout << "Number of Tigers: " << tigerNum << endl;
    cout << "Adult Tigers: " << tigerNum - babyTigerNum << "   " << "Baby Tigers: " << babyTigerNum << endl;
    cout << endl;
    cout << "Number of Penguins: " << penguinNum << endl;
    cout << "Adult Penguins: " << penguinNum - babyPenguinNum << "   " << "Baby Penguins: " << babyPenguinNum << endl;
    cout << endl;
    cout << "Number of Turtles: " << turtleNum << endl;
    cout << "Adult Turtles: " << turtleNum - babyTurtleNum << "   " << "Baby Turtles: " << babyTurtleNum << endl;
    cout << endl;


}

// keep track of how many baby animals are in the zoo
void Zoo::babyAnimalCount() {

    babyTigerNum = 0;
    babyPenguinNum = 0;
    babyTurtleNum = 0;

    for (int b = 0; b < tigerNum; b++) {
        if (animals[0][b].getAge() < 3) {
            babyTigerNum++;
        }
    }

    for (int b = 0; b < penguinNum; b++) {
        if (animals[1][b].getAge() < 3) {
            babyPenguinNum++;
        }
    }

    for (int b = 0; b < turtleNum; b++) {
        if (animals[2][b].getAge() < 3) {
            babyTurtleNum++;
        }
    }

    showZooStats(babyTigerNum, babyPenguinNum, babyTurtleNum); // print zoo stats after counting baby animals
}

// calculate the cost of food for each animal, then subtract the daily cost from bank account
void Zoo::FoodCost() {
    int tigerFoodCost = 0;
    int penguinFoodCost = 0;
    int turtleFoodCost = 0;
    int totalFoodCost = 0;

    for (int b = 0; b < tigerNum; b++) {
        tigerFoodCost += animals[0][b].getBaseFoodCost();
    }

    cout <<"Today's tiger food cost: $" << tigerFoodCost << endl;

    for (int b = 0; b < penguinNum; b++) {
        penguinFoodCost += animals[1][b].getBaseFoodCost();
    }

    cout <<"Today's penguin food cost: $" << penguinFoodCost << endl;

    for (int b = 0; b < turtleNum; b++) {
        turtleFoodCost += animals[2][b].getBaseFoodCost();
    }

    cout <<"Today's turtle food cost: $" << turtleFoodCost << endl;

    totalFoodCost += tigerFoodCost + penguinFoodCost + turtleFoodCost;

    money -= totalFoodCost;

    cout << "Total money spent on food for the day: $" << totalFoodCost << endl;
    cout << "Remaining budget: $" << showMoney() << endl;

}

// calculate payoff for each animal and add it to bank account
void Zoo::animalPayoff() {
    int tigerPayoff = 0;
    int penguinPayoff = 0;
    int turtlePayoff = 0;
    int totalPayoff = 0;
    int randAtt = 0;

    // if random event generates attendance, calculate bonus for each tiger and add to bank account
    if (attendance) {

        static bool errFlag = true;
        if (errFlag) {
            errFlag = false;
        }

        randAtt = 250 + rand() % ((500 + 1) - 250);



        cout << "***RANDOM EVENT: A boom in zoo attendance occurs. Each tiger you own generates a payoff of "
                "an additional $" << randAtt << " today. Total bonus payoff for today: $" << randAtt*tigerNum <<
                "***" << endl;
        attendance = false; // set attendance back to false after implementing the bonus
    }

    // tiger payoff calculation
    for (int b = 0; b < tigerNum; b++) {
        tigerPayoff += animals[0][b].getPayoff();
    }

    // bonus payoff calculation and add to tiger payoff
    tigerPayoff += randAtt*tigerNum;

    cout << endl;
    cout << "***Payoff***" << endl;
    cout <<"Today's tiger payoff: $" << tigerPayoff << endl;

    // penguin payoff calculation
    for (int b = 0; b < penguinNum; b++) {
        penguinPayoff += animals[1][b].getPayoff();
    }

    cout <<"Today's penguin payoff: $" << penguinPayoff << endl;

    // turtle payoff calculation
    for (int b = 0; b < turtleNum; b++) {
        turtlePayoff += animals[2][b].getPayoff();
    }

    cout <<"Today's turtle payoff: $" << turtlePayoff << endl;

    // total payoff calculation
    totalPayoff += tigerPayoff + penguinPayoff + turtlePayoff;
    money += totalPayoff;
    cout << "Today's total payoff: $" << totalPayoff << endl;
    cout << "Current budget: $" << showMoney() << endl;


}

// function that uses random generator to generate a number for 1 of 4 random events
void Zoo::randomEvent() {


    int randEvent = 0;
    static bool errRand = true;
    if (errRand) {
        errRand = false;
    }
    randEvent = 1 + rand() % ((4 + 1) - 1);

    // one animal gets sick and dies
    if (randEvent == 1) {

        animalSickness();

    }

    // monetary bonus for each tiger in zoo added to tiger total payoff
    else if (randEvent == 2) {

        attendanceBoom();

    }

    // baby animal(s) born to adult animal
    else if (randEvent == 3) {

        babyBorn();

    }

    // no significant happening in zoo
    else if (randEvent == 4) {

        cout << "***RANDOM EVENT: Nothing significant happens at your zoo today.***" << endl;
    }

}

// set attendance flag to true if attendance boom event occurs
void Zoo::attendanceBoom() {

    attendance = true;

}

// function used if animal birth event occurs
int Zoo::animalBornRandomGenerator() {
    int random1 = 0;
    static bool errFlag2 = true;
    if (errFlag2) {
        errFlag2 = false;
    }

    random1 = 1 + rand() % ((3 + 1) - 1);
    return random1;
}

// if random event is baby born, randomly generate an adult animal to give birth and check to see if valid
void Zoo::babyBorn() {
    animalBorn = true; // animal born flag set to true

    int randInt = 0;
    bool errFlag = false;
    do {

        randInt = animalBornRandomGenerator(); // randomly generate adult animal to give birth

        // if no adult animals, no animal gives birth
        if ((tigerNum - babyTigerNum <= 0) && (penguinNum - babyPenguinNum <= 0)
            && (turtleNum - babyTurtleNum <= 0)) {
            animalBorn = false;
            errFlag = true;
            randInt = 0;
        }

        // if no adult tigers, return false
        else if (randInt == 1 && tigerNum - babyTigerNum <= 0) {
            errFlag = false;

        }

        // if no adult penguins, return false
        else if (randInt == 2 && penguinNum - babyPenguinNum <= 0) {
            errFlag = false;

        }

        // if no adult turtles, return false
        else if (randInt == 3 && turtleNum - babyTurtleNum <= 0) {
            errFlag = false;

        }

        else {
            errFlag = true;
        }

    } while (errFlag == false);  // randomly generate another number until returns true


    // if no adult animals, set tiger, penguin, and turtle born flags to false
    if (randInt == 0) {
        cout << "***RANDOM EVENT: If you had an adult animal in your zoo, one would have given birth today.  "
                "Unfortunately, you do not have any adult animals.***" << endl;
        tigerBorn = false;
        penguinBorn = false;
        turtleBorn = false;
    }

    // if baby tiger is to be born, set tiger born flag to true
    else if (randInt == 1) {
        cout << "***RANDOM EVENT: A baby tiger is born.***" << endl;
        tigerBorn = true;
        penguinBorn = false;
        turtleBorn = false;

    }

    // if baby penguins are to be born, set penguin born flag to true
    else if (randInt == 2) {
        cout << "***RANDOM EVENT: 5 baby penguins are born.***" << endl;
        penguinBorn = true;
        tigerBorn = false;
        turtleBorn = false;

    }

    // if baby turtles are to be born, set turtle born flag to true
    else if (randInt == 3) {
        cout << "***RANDOM EVENT: 10 baby turtles are born.***" << endl;
        turtleBorn = true;
        tigerBorn = false;
        penguinBorn = false;


    }

    addBabyAnimal(); // call to add baby animal function

    animalBorn = false; // set animal born flag back to false after adding baby animal
}

// function to add a baby animal(s) after birth random event
void Zoo::addBabyAnimal() {

    // add one tiger if adult tiger gives birth
    if (tigerBorn) {
        tigerNum++; // increase tiger count

        // increase array size if tiger count is greater than array size
        if (tigerNum > tigerSize) {
            int newSize = 2 * tigerSize;
            tigerSize = newSize;
            Animal *newArray = new Tiger[tigerSize]; // create new tiger array
            for (int b = 0; b < tigerNum; b++) {
                newArray[b] = animals[0][b]; // move old array entries to new array

            }

            delete[] animals[0]; // delete old array
            animals[0] = newArray; // replace old array with new array

        }

        animals[0][tigerNum - 1] = Tiger(0); // set age of new baby tiger to 0

        tigerBorn = false; // set tiger born flag back to false

    }

    // add 5 penguins if adult penguin gives birth
    if (penguinBorn) {
        penguinNum += 5; // increase penguin count by 5

        // increase array size if penguin count is greater than array size
        if (penguinNum > penguinSize) {
            int newSize = 2 * penguinSize;
            penguinSize = newSize;
            Animal *newArray = new Penguin[penguinSize]; // create new penguin array
            for (int b = 0; b < penguinNum; b++) {
                newArray[b] = animals[1][b]; // move old array entries to new array

            }
            delete[] animals[1]; // delete old array
            animals[1] = newArray; // replace old array with new array

        }

        for (int b = 0; b < 5; b++) {
            animals[1][penguinNum - 5 + b] = Penguin(0); // set age of new baby penguin to 0
        }

        penguinBorn = false; // set penguin born flag back to false
    }

    // add 10 turtles if adult turtle gives birth
    if (turtleBorn) {

        turtleNum += 10; // increase turtle amount by 10

        // increase array size if turtle count is greater than array size
        if (turtleNum > turtleSize) {
            int newSize = 2 * turtleSize;
            turtleSize = newSize;
            Animal *newArray = new Turtle[turtleSize]; // create new turtle array
            for (int b = 0; b < turtleNum; b++) {
                newArray[b] = animals[2][b]; // move old array entries to new array

            }

            delete[] animals[2]; // delete old array
            animals[2] = newArray; // replace old array with new array
        }
        for (int b = 0; b < 10; b++) {
            animals[2][turtleNum - 10 + b] = Turtle(0); // set age of new baby turtle to 0
        }

        turtleBorn = false; // set turtle born flag back to false
    }
}

// if animal sickness random event occurs, randomly generate animal to die
void Zoo::animalSickness() {
    animalIll = true; // animal ill flag set to true
    int randInt = 0;
    bool errFlag = false;

    do {
        randInt = animalRandomSicknessGenerator(); // randomly generate animal to die

        // if zoo has no animals, no animals will die
        if (tigerNum <= 0 && penguinNum <= 0 && turtleNum <= 0) {
            animalIll = false; // animal ill flag set to false
            errFlag = true;
            randInt = 0; // set randInt to 0
        }

        // if tiger chosen to die but no tigers, set flag to false
        else if (randInt == 1 && tigerNum <= 0) {
            errFlag = false;

        }

        // if penguin chosen to die but no penguinz, set flag to false
        else if (randInt == 2 && penguinNum <= 0) {
            errFlag = false;

        }

        // if turtle chosen to die but no turtles, set  flag to false
        else if (randInt == 3 && turtleNum <= 0) {
            errFlag = false;

        }
        else {
            errFlag = true;
        }
    } while (errFlag == false); // randomly generate another number until returns true

    // if no animals in zoo that can die, set animaIll flag back to false
    if (randInt == 0) {
        cout << "***RANDOM EVENT: An outbreak of sickness has hit zoos, but you have no animals, so none of your "
                "animals die.***" << endl;
        animalIll = false;
    }

    // if tiger is to die, set tigerIll flag to true
    else if (randInt == 1) {
        cout << "***RANDOM EVENT: A sickness occurs to one of your tigers.  One tiger has died.***" << endl;
        tigerIll = true;
        penguinIll = false;
        turtleIll = false;
    }

    // if penguin is to die, set penguinIll flag to true
    else if (randInt == 2) {
        cout << "***RANDOM EVENT: A sickness occurs to one of your penguins.  One penguin has died.***" << endl;
        penguinIll = true;
        tigerIll = false;
        turtleIll = false;
    }

    // if turtle is to die, set tirtuleIll flag to true
    else if (randInt == 3) {
        cout << "***RANDOM EVENT: A sickness occurs to one of your turtles.  One turtle has died.***" << endl;
        turtleIll = true;
        tigerIll = false;
        penguinIll = false;
    }
    deleteAnimal(); // call to delete animal function
    animalIll = false; // set animalIll flag back to false after deletion of animal

}

// generate number for which animal to die
int Zoo::animalRandomSicknessGenerator() {
    int random = 0;
    static bool errFlag1 = true;
    if (errFlag1) {
        errFlag1 = false;
    }

    random = 1 + rand() % ((3 + 1) - 1);
    return random;
}


// delete ill animal from zoo
void Zoo::deleteAnimal() {

    // if tiger is ill, remove one tiger from tiger array
    if (tigerIll) {

        int newTigerNum = --tigerNum; // decrease tiger number by 1
        cout << "Removed 1 tiger from zoo." << endl;
        cout << "Remaining tigers in your zoo: " << newTigerNum << endl;

        Animal *newArray = new Tiger[tigerSize]; // create new tiger array
        for (int b = 0; b < newTigerNum; b++) {
            newArray[b] = animals[0][b]; // move old arrray to new array, with exception of last tiger entry

        }

        delete[] animals[0]; // delet old array
        animals[0] = newArray; // replace old array with new array

        tigerIll = false; // set tigerIll flag back to false

    }

    // if penguin is ill, remove one penguin from penguin array
    if (penguinIll) {
        int newPenguinNum = --penguinNum; // decrease penguin total by 1

        cout << "Removed 1 penguin from zoo." << endl;
        cout << "Remaining penguins in your zoo:  " << newPenguinNum << endl;

        Animal *newArray = new Penguin[penguinSize]; // create new penguin array
        for (int b = 0; b < newPenguinNum; b++) {
            newArray[b] = animals[1][b]; // move old arrray to new array, with exception of last penguin entry

        }

        delete[] animals[1]; // delete old array
        animals[1] = newArray; // replace old array with new array

        penguinIll = false; // set penguinIll flag back to false

    }

    // if turtle is ill, remove one turtle from turtle array
    if (turtleIll) {
        int newTurtleNum = --turtleNum; // decrease turtle number by 1
        cout << "Removed 1 turtle from zoo." << endl;
        cout << "Remaining turtles in your zoo: " << newTurtleNum << endl;

        Animal *newArray = new Turtle[turtleSize]; // create new turtle array
        for (int b = 0; b < newTurtleNum; b++) {
            newArray[b] = animals[2][b]; // move old arrray to new array, with exception of last turtle entry

        }

        delete[] animals[2]; // delete old array
        animals[2] = newArray; // replace old array with new array

        turtleIll = false; // set turtleIll flag back to false

    }
}

