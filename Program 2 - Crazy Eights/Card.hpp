//Program #7: Crazy Eights: Card.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Card Class Header Code: Card.hpp
#ifndef CARD_HPP
#define CARD_HPP
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class card {
   private:
      int rank;
      int suit;
   public:
      // constructor & destructor
      /******************************************************************* 
       ** Function: card::card()
       ** Description: The constructor for the card class
       ** Parameters: none
       ** Pre-conditions: Takes in the uninitialized rank and suit for each card
       ** Post-conditions: Initializes the rank and suit for each card to be an integer 0
       *******************************************************************/
      card();

      /******************************************************************* 
       ** Function: card::~card()
       ** Description: The destructor for the card class 
       ** Parameters: none
       ** Pre-conditions: Takes in an instance of the card object
       ** Post-conditions: Deletes the card object instantiation(s)
       *******************************************************************/
      ~card();

      // getters & setters
      /******************************************************************* 
       ** Function: string card::get_rank()
       ** Description: Gets the rank member of the card
       ** Parameters: none
       ** Pre-conditions: Takes in the rank member for a card
       ** Post-conditions: Converts the corresponding  rank member into a string, and returns the string "convert"
       *******************************************************************/
      string get_suit();

      /******************************************************************* 
       ** Function: string card::get_suit()
       ** Description: Gets the suit member of the card
       ** Parameters: none
       ** Pre-conditions: Takes in the suit  member for a card
       ** Post-conditions: Converts the corresponding suit member into a string, and returns the string "convert"
       *******************************************************************/
      string get_rank();

      /******************************************************************* 
       ** Function: void card::set_suit()
       ** Description: Sets the suit member of the card
       ** Parameters: string p_suit
       ** Pre-conditions: Takes in the string p_suit representing the suit of the card
       ** Post-conditions: Converts the string p_suit back into a corresponding integer, and assigns the integer to the suit element of the card class
       *******************************************************************/
      void set_suit(string);

      /******************************************************************* 
       ** Function: void card::set_rank()
       ** Description: Sets the rank member of the card
       ** Parameters: string p_rank
       ** Pre-conditions: Takes in the string p_rank  representing the rank of the card
       ** Post-conditions: Converts the string p_rank back into a corresponding integer, and assigns the integer to the rank element of the card class
       *******************************************************************/
      void set_rank(string);

      // game-play functions
      /******************************************************************* 
       ** Function: string card::converter()
       ** Description: Converts an integer rank into a string rank
       ** Parameters: int p_rank
       ** Pre-conditions: Takes in an integer p_rank
       ** Post-conditions: Returns a corresponding string convert based on p_rank
       *******************************************************************/
      string converter(int);
};

#endif

