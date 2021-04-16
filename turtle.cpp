/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The Turtle class is a derived class of the Animal class. It inherits variables
 * of the Animal class.
*********************************************************************/

#include "turtle.hpp"

// default constructor that inherits the variables of the Animal class
Turtle::Turtle() {
    this->age=1;
    this->cost=100;
    this->babyCount=10;
    this->baseFoodCost=10;
    this->payoff=5;
}

// destructor
Turtle::~Turtle() {

}

// constructor that takes age as a parameter
Turtle::Turtle(int age) : Animal(age, 100, 10, 10, 5) {

}
