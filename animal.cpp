/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The Animal class holds the age, cost, baby birth count, base food cost, and payoff of the
 * animal object.  It is the parent class of the Tiger, Penguin, and Turtle classes.
*********************************************************************/

#include "animal.hpp"


// default constructor
Animal::Animal() {

}

// constructor that takes parameters
Animal::Animal(int age, int cost, int babyCount, int baseFoodCost, int payoff) {

    this->age=age;
    this->cost=cost;
    this->babyCount=babyCount;
    this->baseFoodCost=baseFoodCost;
    this->payoff=payoff;
}

// destructor
Animal::~Animal() {

}

// set age of animal
void Animal::setAge(int animalAge) {
    age = animalAge;
}

// get age of animal
int Animal::getAge() {
    return age;
}

// set cost of animal
void Animal::setCost(int animalCost) {
    cost = animalCost;
}

// get cost of animal
int Animal::getCost() {
    return cost;
}

// set number of babies of animal
void Animal::setBabies(int babyNumber) {
    babyCount = babyNumber;
}

// get number of babies of animal
int Animal::getBabies() {
    return babyCount;
}

// set base food cost
void Animal::setBaseFoodCost(int foodCost) {
    baseFoodCost = foodCost;
}

// get base food cost
int Animal::getBaseFoodCost() {
    return baseFoodCost;
}

// set payoff
void Animal::setPayoff(int money) {
    payoff = money;
}

// get payoff
int Animal::getPayoff() {
    return payoff;
}

// increase animal age by one
void Animal::addOneAge() {
age++;
}


