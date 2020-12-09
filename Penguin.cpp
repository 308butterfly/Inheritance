/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Function definitions for Penguin class.  Inherits from Animal 
**                  Animal class
** Inputs:          Penguin's age                                  
** Dependencies:    Penguin.hpp                  
** Returns:         Penguin object
** File name:       Penguin.cpp
*********************************************************************************/

#include"Penguin.hpp"

Penguin::Penguin(int p_age) : Animal()
{
    this->setAge(p_age);
    this->cost = 1000;
    this->babies = 5;
    this->baseFoodCost = 1.0;
    this->payOff = 0.10;
}

