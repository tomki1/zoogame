/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The Tiger class is a derived class of the Animal class. It inherits variables
 * of the Animal class.
*********************************************************************/

#include "tiger.hpp"

// default constructor that inherits the variables of the Animal class
Tiger::Tiger() {
    this->age=1;
    this->cost=10000;
    this->babyCount=1;
    this->baseFoodCost=100;
    this->payoff=2000;
}

// destructor
Tiger::~Tiger() {

}

// constructor that takes age as a parameter
Tiger::Tiger(int age) : Animal(age, 10000, 1, 100, 2000) {

}
