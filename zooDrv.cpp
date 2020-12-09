/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/19/2019
** Description:     Driver for Project 2 Zoo Tycoon game.  A simple simulation of 
**                  owning and operating a zoo.  
** Inputs:          none                                   
** Dependencies:    zoo.hpp                  
** Returns:         none
** File name:       zooDrv.cpp
*********************************************************************************/

#include <iostream> 

#include"Zoo.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;

int main()
{
    srand(time(0));
    Zoo tycoon1;
    tycoon1.startMenu();
    
    return 0;
}