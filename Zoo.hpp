/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Header file for Zoo class.  This class implements a zoo tycoon 
**                  game.  
** Inputs:          none                                  
** Dependencies:    <iostream>, IntNumberGen.cpp, getInteger.cpp, Animal.cpp, 
**                  Tiger.cpp, Penguin.cpp, Turtle.cpp                 
** Returns:         
** File name:       Zoo.hpp
*********************************************************************************/
#include <iostream>

#include"validate.hpp"

#include "Animal.hpp"
#include "Tiger.hpp"
#include "Penguin.hpp"
#include "Turtle.hpp"

#ifndef ZOO_HPP
#define ZOO_HPP

const int BABY = 0;
const int ADULT = 3;
const int CAGE_SIZE = 10;

class Zoo
{
    private:
        double bank = 100000;
        double randomTigerBonusTotal = 0;
        double baseFeedCost = 10;
        
        

        int tigerPopulation = 0;
        int penguinPopulation = 0;
        int turtlePopulation = 0;

        int randomTigerBonus = 0;
        
        int tigerCageSize = CAGE_SIZE;
        int penguinCageSize = CAGE_SIZE;
        int turtleCageSize = CAGE_SIZE;

        bool firstRound = true;

        bool tigerBaby = false;
        bool penguinBaby = false;
        bool turtleBaby = false;

        bool attendenceBonus = false;

        Animal** tigerCage = nullptr;
        Animal** penguinCage = nullptr;
        Animal** turtleCage = nullptr;

    public:
        Zoo();
        ~Zoo();
        int getBank();
        void startMenu();
        void gameStart();
        void randomEvent();
        void buyAnimals();

        void biggerAnimalCage(Animal**&, int&, int);
        void AnimalDeath();
        void killAnimal(Animal**&, int&);
        void tigerBonus();
        void animalBirth();
        void profit();
        void animalAge();
        void feedAnimals();
        void askToBuyAnimals();
        bool continueMenu();    
};

#endif
