#ifndef IMPLEMENTATION_HPP
#define IMPLEMENTATION_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.hpp"
#include "Node.hpp"

using namespace std;

/*******************************************************************
** Function: start();
** Description: Starts the entire program, making calls to the rest of the functionality of a linked list.
** Parameters: none
** Pre-conditions: n/a (no parameters)
** Post-conditions: creates the linked lists that the user interacts with
*******************************************************************/
void start();

/*******************************************************************
** Function: repeat();
** Description: Determines if the user would like to repeat the program
** Parameters: bool &again
** Pre-conditions: Takes in the boolean which is true, which is controlling a while loop for repeating
** Post-conditions: Returns a true or false for the again boolean based on the user's desire to repeat the program or not.
*******************************************************************/
void repeat(bool &again);

/*******************************************************************
** Function: list();
** Description: Determins which type of list the user would like to use for the program.
** Parameters: int &type
** Pre-conditions: Takes in the type of list (current not set to anything).
** Post-conditions: Changes the type to (1) for unsigned or (2) for signed based on the user's decision. 
*******************************************************************/
void list(int &type);

/*******************************************************************
** Function: signed_list();
** Description: Contains the functionality for the signed list (all the calls regarding interactions with the signed LinkedList instantiation. )
** Parameters: LinkedList<signed int>& s, int &length
** Pre-conditions: Takes in the empty signed LinkedList, with 0 length
** Post-conditions: Adds numbers to the linked list at various places based on the user's input
*******************************************************************/
void signed_list(LinkedList<signed int>& s, int &length);

/*******************************************************************
** Function: unsigned_list();
** Description: Contains the functionality for the unsigned list (all the calls regarding interactions with the unsigned LinkedList instantiation. )
** Parameters: LinkedList<signed int>& u, int &length
** Pre-conditions: Takes in the empty unsigned LinkedList, with 0 length
** Post-conditions: Adds numbers to the linked list at various places based on the user's input
*******************************************************************/
void unsigned_list(LinkedList<unsigned int>& u, int &length);

/*******************************************************************
** Function: numbers();
** Description: Determines what numbers the user wants to input, if they are valid, and where the user would like to place the numbers within the list. 
** Parameters: unsigned int &u_number, signed int &s_number, int &place, int &length, int type
** Pre-conditions: Takes in the empty number and place integers, along with the type and length
** Post-conditions: Modifies number and place based on the user's decision to place a number at a specific place within the linked list. 
*******************************************************************/
void numbers(unsigned int &u_number, signed int &s_number, int &place, int &length, int type);

#endif


