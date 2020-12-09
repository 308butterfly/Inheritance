/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/7/2019
** Description:     Function definitions for Tiger class.  Inherits from Animal 
**                  Animal class
** Inputs:          age of tiger                                    
** Dependencies:    Tiger.hpp                  
** Returns:         Tiger object
** File name:       Tiger.cpp
*********************************************************************************/

#include"Tiger.hpp"

Tiger::Tiger(int t_age) : Animal()
{
   setAge(t_age); 
   this->cost = 10000;
   this->babies = 1;
   this->baseFoodCost = 5;
   this->payOff = 0.20;
}
