/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Header file for Animal class.  This class holds the   
**                  age, cost, number of babies, base feed cost and the payoff of
**                  an animal at the zoo.
** Inputs:          Age of anime                                   
** Dependencies:    <iostream>,                 
** Returns:         Animal object
** File name:       Animal.hpp
*********************************************************************************/

#include <iostream>

#ifndef ANIMAL_HPP
#define ANIMAL_HPP

class Animal
{
    protected:
        int age;
        static int cost;
        static int babies;
        static double baseFoodCost;
        static double payOff;
    
    public:
        Animal();
        Animal(int a_age);
        
        int getAge();
    
        static const int getCost();
        static const int getBabies();
        static const double getBaseFoodCost();
        static const double getPayoff();

        void setAge(int infoAge);
        void yearOlder();
};

#endif
