/*********************************************************************
** Program name: Project 2
** Author: Kimberly Tom
** Date: 4/24/18
** Description: The header file for tiger.cpp.
*********************************************************************/

#ifndef CS162PROJECT2_TIGERS_HPP
#define CS162PROJECT2_TIGERS_HPP

#include "animal.hpp"

class Tiger: public Animal { // Tiger class is a derived class of Animal class

private:

public:
    Tiger(); // default constructor
    ~Tiger(); // destructor
    Tiger(int age); // constructor that takes age as a parameter
};


#endif