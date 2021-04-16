/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The header file for zoo.cpp.
*********************************************************************/

#ifndef CS162PROJECT2_Zoo_HPP
#define CS162PROJECT2_Zoo_HPP

#include<cstdlib>
#include<ctime>
#include<sstream>
#include<iostream>

#include "animal.hpp"
#include "tiger.hpp"
#include "penguin.hpp"
#include "turtle.hpp"
#include"inputValidation.hpp"

using std::string;
using std::stringstream;
using std::cout;
using std::cin;
using std::endl;


class Zoo {

private:
    int tigerSize; // initial Tiger array size
    int penguinSize; // initial Penguin array size
    int turtleSize; // initile Turtle array size

    int dayCount; // keep track of what day it is
    int money; // keep track of user's money
    int baseFoodCost; // close of base food

    int tigerNum; // total number of tigers
    int penguinNum; // total number of penguins
    int turtleNum; // total number of turtles

    int babyTigerNum; // total number of baby tigers
    int babyPenguinNum; // total number of baby penguins
    int babyTurtleNum; // total number of baby turtles

    int newTigerNum; // number of tigers after tiger death
    int newPenguinNum; // number of penguins after penguin death
    int neTurtleNum; // number of turtles safter turtle death

    bool quitFlag; // flag to check if user wants to quit game
    bool attendance; // flag to check if there is a boom in attendance
    bool animalIll; // flag to check if an animal is ill
    bool tigerIll; // flag to check if tiger is ill
    bool penguinIll; // flag to check if penguin is ill
    bool turtleIll; // flag to check if turtle is ill
    bool animalBorn; // flag to check fi animal is to beb orn
    bool tigerBorn; // flag to check if tiger is to be born
    bool penguinBorn; // flag to check if penguin is to be born
    bool turtleBorn; // flag to check if turtle is to be born

    Animal **animals; // a 2D array of animals that will hold the Tiger, Penguin, and Turtle arrays

public:
    Zoo(); // default constructor
    ~Zoo(); // destructor
    void startGame(); // start game function with instructions and begining options
    int showMoney(); // return user's money in bank
    void nextDay(); // next day function used to cycle through the functions of each day in the game
    void increaseAnimalAge(); // increase animal age by one day
    void buyMoreAnimal(); // shows menu to buy more animals and adds purchased animal
    void babyAnimalCount(); // calculates number of baby animals
    void showZooStats(int babyTigerNum, int babyPenguinNum, int babyTurtleNum); // prints animal counts
    void FoodCost(); // calculates food cost and subtracts cost from user's bank
    void animalPayoff(); // calculates the payoff of each animal and adds amount to user's bank
    void randomEvent(); // randomly generates 1 0f 4 random events to occur
    void attendanceBoom(); // switches attendance flag to true
    int animalBornRandomGenerator(); // randomly generates which animal has babies
    void babyBorn(); // determines if randomly generated animal type can have baby, if not generates another animal
    void addBabyAnimal(); // adds baby animal(s) to zoo
    void animalSickness(); // determines if randomly generated animal type can die, if not, generates sanother animal
    int animalRandomSicknessGenerator(); // randomly generates which animal is sick
    void deleteAnimal(); // delete an animal if animal dies
};

#endif