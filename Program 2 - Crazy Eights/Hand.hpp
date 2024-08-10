//Program #7: Crazy Eights: Hand.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Hand Class Header Code: Hand.hpp
#ifndef HAND_HPP
#define HAND_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Card.hpp"

using namespace std;

class hand{
   private:
      card* cards;
      int n_cards; // number of cards
   public:
      // big three
      /******************************************************************* 
       ** Function: hand::hand()
       ** Description: The constructor for the hand class
       ** Parameters: none
       ** Pre-conditions: Takes in the uninitialized cards array and the n_cards member variable
       ** Post-conditions: Initializes the cards array to 7 elements, and the n_cards to 7
       *******************************************************************/
      hand();

      /******************************************************************* 
       ** Function: hand::~hand()
       ** Description: The destructor for the hand class
       ** Parameters: none
       ** Pre-conditions: takes in the hand object
       ** Post-conditions: deletes the cards array created on the heap in the constructor
       *******************************************************************/
      ~hand();

      /******************************************************************* 
       ** Function: hand::hand()
       ** Description: The copy constructor for the hand class
       ** Parameters: const hand& existing
       ** Pre-conditions: Takes in the constant hand address of the existing hand object
       ** Post-conditions: Copies over the hand's member variables to the newly created hand object instantiation
       *******************************************************************/
      hand(const hand&);

      /******************************************************************* 
       ** Function: hand& hand::operator= ()
       ** Description: The assignment overload operator for the hand class
       ** Parameters: const hand& existing
       ** Pre-conditions: Takes in the constant hand address of the existing hand object
       ** Post-conditions: Assigns over the hand's member variables to a new hand object
       *******************************************************************/
      hand& operator= (const hand&);

      // setters & getters
      /******************************************************************* 
       ** Function: int hand::get_n_cards()
       ** Description: The getter for the n_cards member of the hand class
       ** Parameters: none
       ** Pre-conditions: Gets the n_cards member of the hand class
       ** Post-conditions: Returns the n_cards member
       *******************************************************************/
      int get_n_cards();

      /******************************************************************* 
       ** Function: void hand::set_n_cards()
       ** Description: The setter for the n_cards member of the hand class
       ** Parameters: int p_n_cards
       ** Pre-conditions: takes in the integer p_n_cards
       ** Post-conditions: sets the member variable n_cards to p_n_cards
       *******************************************************************/
      void set_n_cards(int);

      /******************************************************************* 
       ** Function: string hand::get_hand_rank()
       ** Description: The getter for the rank of the specific (at i) hand array's class
       ** Parameters: int i
       ** Pre-conditions: Gets the rank of the specific hand array's element at i
       ** Post-conditions: Returns the rank of the specific hand array's element at i
       *******************************************************************/
      string get_hand_rank(int);

      /******************************************************************* 
       ** Function: string hand::get_hand_suit()
       ** Description: The getter for the suit of a specific (at i) hand array class
       ** Parameters: int i
       ** Pre-conditions: Gets the suit of the specific hand array's element at i
       ** Post-conditions: Returns the suit of the specific hand array's element at i
       *******************************************************************/
      string get_hand_suit(int);

      /******************************************************************* 
       ** Function: void hand::set_hand()
       ** Description: The setter for both the suit and rank of a specific hand
       ** Parameters: int i, string p_suit, string p_rank
       ** Pre-conditions: Takes int the i representing the specific array element, and the p_suit and p_rank representing the new suit and rank respectively
       ** Post-conditions: Sets both the suit and the rank of the specific hand array's element at i
       *******************************************************************/
      void set_hand(int, string, string);

      // game-design functions
      /******************************************************************* 
       ** Function: void hand::subtract()
       ** Description: Takes away a specific hand array element by reassigning the pointer
       ** Parameters: int avoid
       ** Pre-conditions: Takes in the current hand with n_cards
       ** Post-conditions: Decrements  n_cards, and takes away the element that is needed to be avoided by creating a new dynamic array on the heap and deletes the old heap array; it also reassigns the pointer
       *******************************************************************/
      void subtract(int);

      /******************************************************************* 
       ** Function: void hand::add()
       ** Description: Adds a new array element at the end of the hand array by reassigning the pointer
       ** Parameters: none
       ** Pre-conditions: Takes in the current hand with n_cards
       ** Post-conditions: Increments n_cards, and adds an element more at the end of the hand array by creating a new dynamic array on the heap; it also reassigns the pointer
       *******************************************************************/
      void add();
};

#endif


