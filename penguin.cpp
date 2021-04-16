/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The Penguin class is a derived class of the Animal class. It inherits variables
 * of the Animal class.
*********************************************************************/

#include "penguin.hpp"

// default constructor that inherits the variables of the Animal class
Penguin::Penguin() {

    this->age=1;
    this->cost=1000;
    this->babyCount=5;
    this->baseFoodCost=20;
    this->payoff=100;

}

// destructor
Penguin::~Penguin() {

}

// constuctor that takes age as a parameter
Penguin::Penguin(int age) : Animal(age, 1000, 5, 20, 100) {

}
