/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The header file for penguin.cpp.
*********************************************************************/

#ifndef CS162PROJECT2_PENGUIN_HPP
#define CS162PROJECT2_PENGUIN_HPP

#include "animal.hpp"

class Penguin: public Animal { // Penguin class is a derived class of the Animal class

private:

public:
    Penguin(); // default constructor
    ~Penguin(); // destructor
    Penguin(int age); // constructor that takes age as a parameter
};


#endif
