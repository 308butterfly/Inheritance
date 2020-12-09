/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Header file for Turtle class.  Hold's turtles name, age, cost, 
**                   to buy, births, base food cost, and pay off. 
** Inputs:          Turtle's age                                    
** Dependencies:    Animal.cpp                 
** Returns:         Turtle object
** File name:       Turtle.hpp
*********************************************************************************/

#ifndef TURTLE_HPP
#define TURTLE_HPP

#include "Animal.hpp"

class Turtle: virtual public Animal
{
    public:

        Turtle(int t_ge);
};

#endif
