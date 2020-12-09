/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Function definitions for Turtle class.  Inherits from Animal 
**                  Animal class
** Inputs:          Turtle's age                                  
** Dependencies:    Turtle.hpp                  
** Returns:         Turtle object
** File name:       Turtle.cpp
*********************************************************************************/

#include"Turtle.hpp"

Turtle::Turtle(int t_age) : Animal()

{
    this->setAge(t_age);
    this->cost = 100;
    this->babies = 10;
    this->baseFoodCost = 0.50;
    this->payOff = 0.05;
}