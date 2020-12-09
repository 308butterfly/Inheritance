/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/24/2019
** Description:     Header file for Tiger class.  Hold's Tigers name, age, cost, 
**                   to buy, births, base food cost, and pay off. 
** Inputs:          Tiger's age                                    
** Dependencies:    Animal.cpp                 
** Returns:         Tiger object
** File name:       Tiger.hpp
*********************************************************************************/

#ifndef TIGER_HPP
#define TIGER_HPP

#include "Animal.hpp"

class Tiger: virtual public Animal
{   
    public:
        Tiger(int t_age);      
};

#endif
