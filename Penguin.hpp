/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Header file for Penguin class.  Hold's Penguins name, age, cost, 
**                   to buy, births, base food cost, and pay off. 
** Inputs:          Penguin's age                                    
** Dependencies:    Animal.cpp                 
** Returns:         Penguin object
** File name:       Penguin.hpp
*********************************************************************************/

#ifndef PENGUIN_HPP
#define PENGUIN_HPP

#include"Animal.hpp"

class Penguin: virtual public Animal
{
    public:
        Penguin(int p_age);
};

#endif
