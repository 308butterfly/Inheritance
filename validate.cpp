/*********************************************************************************
** Author:          Andrew Thiele
** Date Modified:   4/20/2019
** Description:     A collection of functions to validate, integer input,
**                  integer input within a designated range
** Inputs:          integers from user                          
** Dependencies:    See Below         
** Returns:         
** File name:       validate.hpp
*********************************************************************************/

#include"validate.hpp"

using std::cout;
using std::cin;
using std::endl;
using std::string;


/*********************************************************************************
** Function name:   getinteger
** Date Modified:   4/22/2019
** Description:     Asks for and validates integer input.               
** Depenencies:     cstring, iostream, limits, ios libraries
** Inputs:          predefined string to assist in valid input, and a user integer
** Returns:         a user inputted integer.
*********************************************************************************/

#include <cstring>
#include <iostream> 
#include <limits>
#include <ios>

int getInteger(string message)
{
    while(true)
    {   
        cout<< message;
        int integer;
        cin >> integer;

        if(cin.fail())
        {
            //https://www.geeksforgeeks.org/clearing-the-input-buffer-in-cc/
            //to clear input buffer
            cin.clear();
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            cout << "Invalid Input!\n\n"; 
        }

        else
        {
            cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            return integer;
        }   
    }
}

/*********************************************************************************
** Function name:   IntNumberGen
** Date Modified:   4/20/2019
** Description:     A random integer generator
** Arguments:       2 signed integers to set the minimum and maximum value with
**                  minimum < maximum
** Dependencies:    ctime, cstdlib libraries.  srand(time(0)) must be used outside
**                  function
** Returns:         random signed integer in range of arguments
*********************************************************************************/

#include<ctime>
#include<cstdlib>
#include<cstdio>

int IntNumberGen(int minimum, int maximum)
{
    return (rand()%(maximum - minimum + 1)) + minimum;
}

/*********************************************************************************
** Function name:   intRangeCheck
** Date Modified:   4/20/2019
** Description:     This function checks if an entered integer is within a desired 
**                  range.  If it is not, the getInteger function is called again
**                  using a string to specify desired input.
**
** Inputs:          the minimum bound, the maximum bound, integer value 
**                  to be checked, and a string for to be passed to the getInteger 
**                  function.
**
** Dependencies:    cstring, climits, getInteger.cpp
**                  
** Returns:         the entered integer if it is in range
*********************************************************************************/

#include<climits>

int intRangeCheck(int leftBound, int rightBound,  int value, std::string message )
{
    bool flag = true;
    
    while(flag)
    {
        if((value >= leftBound) && (value <= rightBound))
        {
            flag = false;   
        }

        else
        {
            std::cout << "NOT IN RANGE!\n";
            value  = getInteger(message);
        }   
    }
    return value;
}