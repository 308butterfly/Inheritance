/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/19/2019
** Description:     Function definitions for Animal class.  This class holds the   
**                  age, cost, number of babies, base feed cost and the payoff of
**                  an animal at the zoo.
** Inputs:                                              
** Dependencies:    Animal.hpp                  
** Returns:         
** File name:       Animal.cpp
*********************************************************************************/

#include"Animal.hpp"

int Animal::cost;
int Animal::babies;
double Animal::baseFoodCost;
double Animal::payOff;

Animal::Animal()
{
    this -> age = -1;
    this -> cost = -1;
    this -> babies = -1;
    this -> baseFoodCost = -1;
    this -> payOff = -1;
}

Animal::Animal(int animalAge)
{
    this -> age = animalAge;
    this -> cost = -1;
    this -> babies = -1;
    this -> baseFoodCost = -1;
    this -> payOff = -1;
}

int Animal::getAge()
{
    return age;
}

int const Animal::getCost()
{
    return cost;
}

int const Animal::getBabies()
{
    return babies;
}

double const Animal::getBaseFoodCost()
{
    return baseFoodCost;
}

double const Animal::getPayoff()
{
    return payOff;
}

void Animal::setAge(int infoAge)
{
    this -> age = infoAge;
}

void Animal::yearOlder()
{
    this -> age++;
}

