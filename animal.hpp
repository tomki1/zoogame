/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The header file for animal.cpp.
*********************************************************************/

#ifndef CS162PROJECT2_ANIMAL_HPP
#define CS162PROJECT2_ANIMAL_HPP


class Animal {

protected:
    int age; // age of animal
    int cost; // cost of animal
    int babyCount; // number of babies of animal
    int baseFoodCost; // base food cost
    int payoff; // payoff from animals


public:
    Animal(); // default constuctor
    Animal(int age, int cost, int babyCount, int baseFoodCost, int payoff); // constructor that takes parameters
    ~Animal(); // destructor
    void setAge(int animalAge); // set animal age
    int getAge(); // get animal age
    void addOneAge(); // add one day to animal age
    void setCost(int animalCost); // set animal cost
    int getCost(); // get animal cost
    void setBabies(int babyNumber); // set baby count
    int getBabies(); // get baby count
    void setBaseFoodCost(int foodCost); // set base food cost
    int getBaseFoodCost(); // get base food cost
    void setPayoff(int money); // set payoff
    int getPayoff(); // get payoff


};


#endif
