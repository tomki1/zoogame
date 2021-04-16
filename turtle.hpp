/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The header file for turtle.cpp.
*********************************************************************/

#ifndef CS162PROJECT2_TURTLE_HPP
#define CS162PROJECT2_TURTLE_HPP

#include "animal.hpp"

class Turtle: public Animal { // Turtle class is a derived class of Animal class

private:

public:
    Turtle(); // default constructor
    ~Turtle(); // destructor
    Turtle(int age); // constructor that takes age as a parameter
};


#endif