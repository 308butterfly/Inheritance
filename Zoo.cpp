/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     Funcion implementaion file for Zoo class.
** Inputs:           none                                   
** Dependencies:    <iostream>, IntNumberGen.cpp, getInteger.cpp, Animal.cpp, 
**                  Tiger.cpp, Penguin.cpp, Turtle.cpp                 
** Returns:         
** File name:       Zoo.cpp
*********************************************************************************/

#include"Zoo.hpp"


using  std::cout;
using  std::cin;
using  std::endl;
using  std::string;

 Zoo::Zoo()
{
    tigerCage = new Animal*[tigerCageSize];
    penguinCage = new Animal*[penguinCageSize];
    turtleCage = new Animal*[turtleCageSize];

    for(int i = 0; i < CAGE_SIZE; i++)
    {
        tigerCage[i] = nullptr;
        penguinCage[i] = nullptr;
        turtleCage[i] = nullptr;
    }
}

Zoo::~Zoo()
{
    for(int i = 0; i < tigerPopulation; i++)
    {
        delete tigerCage[i];
        tigerCage[i] = nullptr;
    }

    delete [] tigerCage;

    tigerCage = nullptr;

    for(int i = 0; i < penguinPopulation; i++)
    {
        delete penguinCage[i];
        penguinCage[i] = nullptr;
    }

    delete [] penguinCage;

    penguinCage = nullptr;

    for(int i = 0; i < turtlePopulation; i++)
    {
        delete turtleCage[i];
        turtleCage[i] = nullptr;
    }

    delete [] turtleCage;

    turtleCage = nullptr;
    
}

/*********************************************************************************
** Function name:   startMenu  
** Date Modified:   4/20/2019
** Description:     starts Zoo Tycon simulation
** Inputs:          user inputted integers for menu selection                                    
** Dependencies:    getInteger.cpp                 
** Returns:         nothing
*********************************************************************************/


void Zoo::startMenu()
{
     string title = "Zoo Tycoon\n1-START GAME\n2-EXIT GAME\n";
     string choice1 = "START GAME\n";
     string choice2 = "EXIT GAME\n";
    
    bool flag = true;
    while(flag)
    {
        int choice = getInteger(title);

        switch(choice)
        {
            case 1:  cout << choice1;
                Zoo:gameStart();
                flag = false;   
                break;

            case 2:  cout << choice2;
                flag = false; 
                break;
            
            default:   cout << "Invalid choice!\n";
                break;
        }
    }
}

/*********************************************************************************
** Function name:   gameStart()  
** Date Modified:   4/20/2019
** Description:     body of Zoo Tycon simulation
** Inputs:          none                              
** Dependencies:    zooDrv.cpp            
** Returns:         nothing
*********************************************************************************/

void Zoo::gameStart()
{
    bool funFlag = true;

    //Set up zoo/buy animals
    

    Zoo::buyAnimals();
    
    while(funFlag)
    {   
        Zoo::animalAge();
        
        Zoo::feedAnimals();
        
        Zoo::randomEvent();

        Zoo::profit();
        
        Zoo::askToBuyAnimals();

        funFlag = Zoo::continueMenu();
    }
}

/*********************************************************************************
** Function name:   animalAge
** Date Modified:   4/24/2019
** Description:     ages all the animals one day.
** Inputs:          none                         
** Dependencies:    Animal.cpp
** Returns:         nothing
*********************************************************************************/

void Zoo::animalAge()
{
    for(int i = 0; i < tigerPopulation; i++)
    {
        tigerCage[i]->yearOlder();
    }

    for(int i = 0; i < penguinPopulation; i++)
    {
        penguinCage[i]->yearOlder();
    }

    for(int i = 0; i < turtlePopulation; i++)
    {
        turtleCage[i]->yearOlder();
    }
}

/*********************************************************************************
** Function name:   feedAnimals
** Date Modified:   4/24/2019
** Description:     Displays the cost of feeding all the animals one day and
**                  the ammount of money the zoo has.  
** Inputs:          none                         
** Dependencies:    Animal class, Tiger class, Penguin class, Turtle class
** Returns:         nothing
*********************************************************************************/

void Zoo::feedAnimals()
{
    cout << "\nEATING TIME!!\n";
    cout << "The base feed cost is " << baseFeedCost << endl;
    cout << "The cost to feed the animals today is :\n";
    
    Tiger ghostTiger(0);
    double tigerFeedCost = tigerPopulation * Tiger::getBaseFoodCost() * baseFeedCost;   
    
    cout << tigerFeedCost << " dollars for the " << tigerPopulation << " tigers\n";

    Penguin ghostPenguin(0);
    double penguinFeedCost = penguinPopulation * Penguin::getBaseFoodCost() * baseFeedCost;
    
    cout << penguinFeedCost << " dollars for the " << penguinPopulation << " penguins\n";
    
    Turtle ghostTurtle(0);
    double turtleFeedCost = turtlePopulation * Turtle::getBaseFoodCost() * baseFeedCost;
    
    cout << turtleFeedCost << " dollars for the " << turtlePopulation << " turtles\n";

    bank -= (tigerFeedCost + penguinFeedCost + turtleFeedCost);

    cout << "You have " << bank << " dollars in the bank.\n";

}

/*********************************************************************************
** Function name:   randomEvent 
** Date Modified:   4/20/2019
** Description:     chooses the random event that occurs once each day in the zoo
**                  tycoon simulation.  The events are an animal dying, a boost 
**                  in zoo attendence, an animal birth, or nothing.  The random 
**                  events are determinied by a random number generator generating
**                  a number between 0 and 3.
** Inputs:          none                              
** Dependencies:    zooDrv.cpp            
** Returns:         nothing
*********************************************************************************/

void Zoo::randomEvent()
{
    cout << "RANDOM EVENT TIME!!!\n";
    int happening = IntNumberGen(0,3);

    enum RandomHappenings {animalDeath, tigerBonus, animalBirth, nothing};

    switch(happening)
    {
        case animalDeath:
            Zoo::AnimalDeath();
            break;
        
        case tigerBonus:
            attendenceBonus = true;
            Zoo::tigerBonus();
            break;

        case animalBirth:
            Zoo::animalBirth();
            break;

        case nothing:
             cout << "NOTHING HAPPENS!!\nNo news is good news!!\n";
            break;
        
        default:
            break;

    }
}

/*********************************************************************************
** Function name:   buyAnimals
** Date Modified:   4/20/2019
** Description:     Buy animals for zoo tycoon simulation.  The inital use checks 
**                  to see if the user has purcased at least one of every animal.  
**                  Every animal bought in the initial phase will only be one days
**                  old.  Every animal bought afterward will be 3 days old.
**
**                  This function does not stop the user from spending all their 
**                  money buying animals.   
**
** Inputs:          none                              
** Dependencies:    getInteger,biggerAnimalCage    
** Returns:         nothing
*********************************************************************************/

void Zoo::buyAnimals()
{
    string message1 = "What animal do you want to buy?\n"
                      "1-Tiger\n"
                      "2-Penguin\n"
                      "3-Turtle\n"
                      "4-None\n";
    string firstRoundMsg = "Please buy at least one of each animal\n";
    string animalChoices[4] = {"Tiger\n", "Penguin\n", 
                               "Turtle\n", "Nice doing business with you\n"};
    
    bool flag = true;
    int howOld;

    while(flag)
    {   
        cout << "\nYou have " << tigerPopulation << " tigers, " 
                            << penguinPopulation << " penguins, and " 
                            << turtlePopulation << " turtles.\n";
        
        cout << "\nYou currently have " << bank << " dollars.\n";

        if(firstRound)
        {
            cout << firstRoundMsg <<endl;
            howOld = 1;
        }

        else
        {
            howOld = 3;
        }
        
        int choice = getInteger(message1);  
         
        enum animalsAvailable {tiger = 1, penguin, turtle, leave};

        switch(choice)
        {
            case tiger:
            {
                cout << "You bought a " << animalChoices[0] << endl;
                tigerPopulation++;
                
                if(tigerPopulation > tigerCageSize)
                {   
                    tigerPopulation--;
                    
                    biggerAnimalCage(tigerCage, tigerCageSize, tigerPopulation);
                    
                    tigerPopulation++;
                }

                tigerCage[tigerPopulation - 1] = new Tiger(howOld);
                cout << "The tiger is in the cage\n";

                bank -= Tiger::getCost();
                break;
            }

            case penguin:
            {
                cout << "You bought a " << animalChoices[1] << endl;
                penguinPopulation++;
                
                if(penguinPopulation > penguinCageSize)
                {
                    penguinPopulation--;
                    
                    biggerAnimalCage(penguinCage, penguinCageSize, penguinPopulation);
                    
                    penguinPopulation++;
                }

                penguinCage[penguinPopulation - 1] = new Penguin(howOld);
                cout << "The penguin is in the cage\n";

                bank -= Penguin::getCost();

                break;
            }

            case turtle:
            {
                cout << "You bought a " << animalChoices[2] << endl;
                turtlePopulation++;

                if(turtlePopulation > turtleCageSize)
                {
                    turtlePopulation--;
                
                    biggerAnimalCage(turtleCage, turtleCageSize, turtlePopulation);
                    
                    turtlePopulation++;
                }

                turtleCage[turtlePopulation - 1] = new Turtle(howOld);
                cout << "The turtle is in the cage\n";

                bank -= Turtle::getCost();
                
                break;
            }

            case leave:
            {
                cout << "None \n";

                if(firstRound)
                {
                    if(tigerPopulation < 1 || penguinPopulation < 1 || turtlePopulation < 1)
                    {
                        cout << firstRoundMsg << endl;
                    }
                    else
                    {
                        cout << animalChoices[3] << endl;
                        flag = false;
                    }  
                }

                else
                {   
                    cout << animalChoices[3] << endl;
                    flag = false;
                }
                
                break;
            }

            default:
            {
                cout << "Invalid choice\n";
                break;
            }
        }
    }

    firstRound = false;
}

/*********************************************************************************
** Function name:   biggerAnimalCage
** Date Modified:   4/23/2019
** Description:     Creates a penguin cage twice the size for an overcrowded 
**                  penguin cage
** Inputs:          none                              
** Dependencies:    Penguin.cpp          
** Returns:         nothing
*********************************************************************************/

void Zoo::biggerAnimalCage(Animal**& animalCage, int& animalCageSize, int animalPop)
{
    animalCageSize *= 2;
    Animal** tempCage = new Animal*[animalCageSize];
    
    for(int i = 0; i < animalCageSize; i++)
    {
        tempCage[i] = nullptr;
    }

    for(int i = 0; i < animalPop; i++)
    {
        tempCage[i] = animalCage[i];
        delete animalCage[i];
    }

    delete [] animalCage;

    animalCage = tempCage;
}

/*********************************************************************************
** Function name:   killAnimal
** Date Modified:   4/22/2019
** Description:     Removes a random animal in the array of animals and replaces 
**                  it with the last animal in the array  Initially uses a random 
**                  integer, 0 -  the population of the animal - 1 to select the 
**                  animal.  
** Inputs:          pointer to Animal array, int of # of animals in array                           
** Dependencies:    Animal.hpp    
** Returns:         nothing
*********************************************************************************/

void Zoo::killAnimal(Animal**& animalCage, int& animalPopulation)
{
    //int animalMark = IntNumberGen(0, animalPopulation - 1);

    //delete animalCage[animalMark];
    //animalCage[animalMark] = animalCage[animalPopulation - 1];
    delete animalCage[animalPopulation - 1];
    animalCage[animalPopulation - 1] = nullptr;
    animalPopulation--;
}

/*********************************************************************************
** Function name:   AnimalDeath
** Date Modified:   4/22/2019
** Description:     Kills random animal in the zoo.  Initially uses a random 
**                  integer, 0 - 2 to choose between the tigers, penguins and 
**                  turtles.  Then uses another random integer between 0 and the 
**                  animal population size to choose an animal to die.  
** Inputs:          none                           
** Dependencies:    ?     
** Returns:         nothing
*********************************************************************************/

void Zoo::AnimalDeath()
{
    cout <<"OH NO!!!! An animal died\n";

    if(tigerPopulation  < 1 && penguinPopulation < 1 && turtlePopulation < 1)
    {
        cout << "But, in another zoo because there are no animals\n";
        cout << "Buy some animals!\n";
        cout << "or start putting Broneys in cages\n";
    }

    else
    {
        
        bool deathFlag = true;
        
        while(deathFlag)
        {
            int deathMark = IntNumberGen(0,2);
            enum animals{tigers, penguins, turtles};

            switch(deathMark)
            {
                case tigers:
                {
                    if(tigerPopulation > 0)
                    {   
                        cout << "It was a tiger!!!\n";
                        cout << "Harrison Ford cries!!\n";
                        
                        killAnimal(tigerCage, tigerPopulation);

                        deathFlag = false;

                    }
                    
                    break;
                }
                    

                case penguins:
                {
                    if(penguinPopulation > 0)
                    {   
                        cout << "It was a penguin!!!\n";
                        cout << "No more Happy Feet\n";

                        killAnimal(penguinCage, penguinPopulation);

                        deathFlag = false;
                    }
                    
                    break;
                }

                case turtles:
                {
                    if(turtlePopulation > 0)
                    {   
                        cout << "It was a turtle!!!\n";
                        cout << "But don't worry.  It wasn't a ninja turtle.\n";
                        
                        killAnimal(turtleCage, turtlePopulation);

                        deathFlag = false;
                    }

                    break;
                }
                
                default:
                    break;
            }
        }
    }
}

/*********************************************************************************
** Function name:   tigerBonus
** Date Modified:   4/22/2019
** Description:     Determines the amount of bonus received from a boost in zoo
**                  attendence base on the numbers of tigers present in the zoo
**                  and a random integer between 250 and 500
** Inputs:          none                           
** Dependencies:    IntNumberGen    
** Returns:         double
*********************************************************************************/

void Zoo::tigerBonus()
{    

    randomTigerBonus = IntNumberGen(250, 500);

    cout << "Wow, the zoo is packed today\n";
    cout << "Everybody must be here to see tigers.\n";
    

    cout << "The penguins and turtles are jealous.\n";
    cout << "But, the zoo gets a bonus from the " << tigerPopulation << " tigers"
         << " at " << randomTigerBonus  << " dollars a tiger.\n";

    randomTigerBonusTotal = tigerPopulation * randomTigerBonus;

    cout << "That is " << randomTigerBonusTotal << " dollars.\n";

}

/*********************************************************************************
** Function name:   animalBirth
** Date Modified:   4/22/2019
** Description:     Randomly selects an animal to have a baby.  If the animal is
**                  not over 3 days old, another animal is randomly selected to 
**                  have a baby, if no animals can have a baby, then no babies are
**                  had.   Assumes that an animal exists to have a baby.
** Inputs:          none                           
** Dependencies:    IntNumberGen, doubleTigerCage, doublePenguinCage, 
**                  doubleTurtleCage    
** Returns:         nothing
*********************************************************************************/

void Zoo::animalBirth()
{
    bool flag = true;

    cout << "The stork is coming ... ";
    
    //checks if any animals can have babies
    if(tigerPopulation > 0)
    {
        for(int i = 0; i < tigerPopulation; i++)
        {
            if(tigerCage[i]->getAge() >= ADULT)
            {
                tigerBaby = true;
            }
        }
    }

    if(penguinPopulation > 0)
    {
        for(int i = 0; i < penguinPopulation; i++)
        {
            if(penguinCage[i]->getAge() >= ADULT)
            {
                penguinBaby = true;
            }
        }
    }

    if(turtlePopulation >0)
    {
        for(int i = 0; i < turtlePopulation; i++)
        {
            if(turtleCage[i]->getAge() >= ADULT)
            {
                turtleBaby = true;
            }
        }
    }

    //No animals can have babies
    if(!tigerBaby && !penguinBaby && !turtleBaby)
    {
        cout << " and flew away.\nNo babies today.\n:(\n";
    }

    //repeat until an adult animal is found
    else
    {
        while(flag)
        {
            int fate = IntNumberGen(0,2);

            enum animals {tiger, penguin, turtle};

            switch (fate)
            {
                case tiger:
                {
                    if(tigerBaby)
                    {
                        cout << " and drops off a baby tiger!!\n";
                        cout << "Harrison Ford rejoices!!\n";
                        
                        tigerPopulation += Tiger::getBabies();

                        if(tigerPopulation > tigerCageSize)
                        {   
                            tigerPopulation -= Tiger::getBabies();
                            biggerAnimalCage(tigerCage, tigerCageSize, tigerPopulation);
                        }

                        for(int i = tigerPopulation - Tiger::getBabies(); i < tigerPopulation; i++)
                        {
                            tigerCage[i] = new Tiger(BABY);
                        }

                        tigerPopulation += Tiger::getBabies();
                        tigerBaby = false;
                        flag = false;
                    }

                    break;
                }

                case penguin:
                {
                    if(penguinBaby)
                    {
                        cout << " and drops off 5 baby penguins!!\n";
                        cout << "The penguins from Madagascar have competition.\n";
                        
                        penguinPopulation += Penguin::getBabies();

                        if(penguinPopulation > penguinCageSize)
                        {   
                            penguinPopulation -= Penguin::getBabies();
                            biggerAnimalCage(penguinCage, penguinCageSize, penguinPopulation);
                        }

                        for(int i = penguinPopulation; i < penguinPopulation + Penguin::getBabies(); i++)
                        {
                            penguinCage[i] = new Penguin(BABY);
                        }

                        penguinPopulation += Penguin::getBabies();
                        penguinBaby = false;
                        flag = false;

                    }
                    break;
                }

                case turtle:
                {
                    if(turtleBaby)
                    {
                        cout << " and drops off 10 baby turtles!!\n";
                        cout << "One more and it's a football team.\n";
                        
                        turtlePopulation += Turtle::getBabies();
                        
                        if(turtlePopulation > turtleCageSize)
                        {
                            turtlePopulation -= Turtle::getBabies();
                            biggerAnimalCage(turtleCage, turtleCageSize, turtlePopulation);
                        }
                        
                        for(int i = turtlePopulation ; i < turtlePopulation + Turtle::getBabies(); i++ )
                        {
                            turtleCage[i] = new Turtle(BABY);
                        }

                        turtlePopulation += Turtle::getBabies();
                        turtleBaby = false;
                        flag = false;
                    }
                    break;
                }

                default:
                    break;
            }   
        }
    }
}

/*********************************************************************************
** Function name:   profit
** Date Modified:   4/22/2019
** Description:     Finds the profit of the zoo for one day.  It is based on the 
**                  population of an animal along with it's cost factor and 
**                  profit factor.
** Inputs:                                    
** Dependencies:    
** Returns:         zoo profits as a double
*********************************************************************************/

void Zoo::profit()
{


    double ammount = 0; 
    
    cout << "Today's revenue from the zoo is:\n";
    
    Tiger soullessTiger(0);
    
    double tigerMoney = tigerPopulation * (Tiger::getCost())
                      * (Tiger::getPayoff());
    
    cout << tigerMoney << " dollars from the " << tigerPopulation << " tigers... \n";
    
    Penguin soullessPenguin(0);

    double penguinMoney = penguinPopulation * (Penguin::getCost())
                        * (Penguin::getPayoff());

    cout << penguinMoney << " dollars from the " << penguinPopulation << " penguins...\n";

    Turtle soullessTurtle(0);

    double turtleMoney = turtlePopulation * (Turtle::getCost()) 
                       * (Turtle::getPayoff());
    
    cout << turtleMoney << " and dollars from the " << turtlePopulation << " turtles...\n";   
                 
    ammount = tigerMoney + penguinMoney + turtleMoney; 

    if(attendenceBonus)
    {
        ammount += randomTigerBonusTotal;

        cout << " and with the " << randomTigerBonusTotal << " dollars"
                " bonus from the incresed zoo attendence makes \n";
    }

    cout << ammount << " for the day\n";
    
    bank += ammount;

    cout << "The bank has " << bank << " dollars\n.";

    attendenceBonus = false;   
}

/*********************************************************************************
** Function name:   askToBuyAnimals
** Date Modified:   4/27/2019
** Description:     Menus to prompt the user to continue zoo tycoon or to end
** Inputs:          user inputed integers                         
** Dependencies:    getInteger  
** Returns:         nothing
*********************************************************************************/

void Zoo::askToBuyAnimals()
{
     string title = "Would you like to buy an animal?\n1-YES!\n2-NO!\n";
     string choice1 = "YES!\n";
     string choice2 = "NO!\n";
    
    bool flag = true;

    while(flag)
    {
        int choice = getInteger(title);

        switch(choice)
        {
            case 1:  cout << choice1;
                Zoo::buyAnimals();
                flag = false;   
                break;

            case 2:  cout << choice2;
                flag = false; 
                break;
            
            default:   cout << "Invalid choice!\n";
                break;
        }
    }

    
}
/*********************************************************************************
** Function name:   continueMenu
** Date Modified:   4/22/2019
** Description:     Menus to prompt the user to continue zoo tycoon or to end
** Inputs:          user inputed integers                         
** Dependencies:    getInteger  
** Returns:         nothing
*********************************************************************************/


bool Zoo::continueMenu()
{
     string title = "Continue??\n1-YES!\n2-NOPE!\n";
     string choice1 = "YES!\n";
     string choice2 = "NOPE!\n";
    
    bool flag;

    if(bank <= 0)
    {
        flag = false;
        cout << "You ran out of money.  The game is over.\n";
    }

    else
    {
        flag = true;
    }

    bool continueFlag = false;

    while(flag)
    {
        int choice = getInteger(title);

        switch(choice)
        {
            case 1:  cout << choice1;
                continueFlag = true;
                flag = false;   
                break;

            case 2:  cout << choice2;
                flag = false; 
                break;
            
            default:   cout << "Invalid choice!\n";
                break;
        }
    }

    return continueFlag;
}