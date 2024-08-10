//Program #7: Crazy Eights: CrazyEights.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Header/Interface File Code: CrazyEights.hpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "Game.hpp"

using namespace std;

/******************************************************************* 
 ** Function: start();
 ** Description: This function begins the game by starting the random time seed, and creating the game event
 ** Parameters: none
 ** Pre-conditions: none (the game hasn't begun yet)
 ** Post-conditions: has the functionality to create and destroy the event game
 *******************************************************************/
void start();

/******************************************************************* 
 ** Function: repeat();
 ** Description: Determines if the user would like to repeat the game or not, with error handling
 ** Parameters: bool &
 ** Pre-conditions: Takes in the boolean valid, which it will modify based on the user's desire to repeat the game or not
 ** Post-conditions: Modifies the boolean based on the user input
 *******************************************************************/
void repeat(bool &);





