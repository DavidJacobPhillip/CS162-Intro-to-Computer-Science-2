#ifndef ZOOTYCOON_HPP
#define ZOOTYCOON_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Zoo.hpp"

using namespace std;

/*******************************************************************
** Function: game()
** Description: Contains all of the calls for the game to start and finish
** Parameters: n/a
** Pre-conditions: none (no parameters)
** Post-conditions: prints out items into the console based on function calls
*******************************************************************/
void game();

/*******************************************************************
** Function: animals()
** Description: Determines if the user would like to buy an animal, what type of animal the user would like to buy, and how many animals (with error-handling)
** Parameters: Zoo &creation
** Pre-conditions: Takes in the zoo creation object, and the animal-child class arrays
** Post-conditions: Modifies the animal-child class arrays by increasing them respectively, for every animal bought
*******************************************************************/
void animals(Zoo &);

/*******************************************************************
** Function: animal_numbers()
** Description: Determines the number of animals the user wants to buy (with error handling)
** Parameters: int &numbers
** Pre-conditions: Takes in the undefiend numbers intger
** Post-conditions: Modifies the numbers integer according the user-response
*******************************************************************/
void animal_numbers(int &);

/*******************************************************************
** Function: food_type();
** Description: Determines what type of food the user would like to take in
** Parameters: int &sickness, Zoo &creation, bool &alive, int turn
** Pre-conditions: takes in the sickness probability integer, the zoo creation object, bool alive, and integer turn
** Post-conditions: modifies the sicknesss probability based on the food-type chosen, and if there is no more money in the bank it ends the game through the boolean
*******************************************************************/
void food_type(int &, Zoo&, bool &, int);

/*******************************************************************
** Function: quit()
** Description: Determines if the user has money in their bank and if they would like to keep playing
** Parameters: bool &alive, int turn, Zoo &creation
** Pre-conditions: Takes in the bool alive, int turn, and zoo object creation
** Post-conditions: Changes alive to true or false depending on whether the user wants to play another round / if they have enough money to keep playing
*******************************************************************/
void quit(bool&, int, Zoo&);

/*******************************************************************
** Function: special()
** Description: Activates a special event
** Parameters: Zoo &creation, int sickness
** Pre-conditions: Takes in the zoo creation object, and the sickness probability
** Post-conditions: Randomly calls to a special event
*******************************************************************/
void special(Zoo&, int&);

#endif