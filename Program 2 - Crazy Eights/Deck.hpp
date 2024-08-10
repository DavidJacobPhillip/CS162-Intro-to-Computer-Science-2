//Program #7: Crazy Eights: Deck.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Deck Class Header Code: Deck.hpp
#ifndef DECK_HPP
#define DECK_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Card.hpp"

using namespace std;

class deck {
   private:
      // holds all of the face-down cards
      card facedown[52];
      // holds all of the face-up cards
      card faceup[1];
      int n_cards;

      // this is used to simply access functions within the card class for implementation in the deck class
      card modifier;
   public:
      // constructor & destructor
      /******************************************************************* 
       ** Function: deck::deck()
       ** Description: The constructor for the deck class 
       ** Parameters: none
       ** Pre-conditions: Takes in the empty facedown array of card that has no assigned rank / suit for each card
       ** Post-conditions: Assigns each of the card elements in the facedown array a rank and suit that corresponds with a traditional deck of cards (2-10 + Q, K, A, J for rank, and H, S, C, D for suit)
       *******************************************************************/
      deck();

      /******************************************************************* 
       ** Function: deck::~deck()
       ** Description: The destructor for the deck class
       ** Parameters: none
       ** Pre-conditions: Takes in the empty deck object
       ** Post-conditions: Deletes the specific deck object instantiation
       *******************************************************************/
      ~deck();

      // getters & setters
      /******************************************************************* 
       ** Function: int deck::get_n_cards()
       ** Description: Gets the int n_cards member of the deck class
       ** Parameters: none
       ** Pre-conditions: Takes in the n_cards member of the deck class
       ** Post-conditions: Returns the n_cards member of the deck class
       *******************************************************************/
      int get_n_cards();

      /******************************************************************* 
       ** Function: void deck::set_n_cards()
       ** Description: Sets the int n_cards member of the deck class
       ** Parameters: int p_n_cards
       ** Pre-conditions: Takes in the p_n_cards integer
       ** Post-conditions: Assigns the p_n_cards integer to the n_cards member of the deck class
       *******************************************************************/
      void set_n_cards(int);

      /******************************************************************* 
       ** Function: string deck::get_facedown_rank()
       ** Description: Gets the rank of a specific facedown array member of the deck class
       ** Parameters: int i
       ** Pre-conditions: Takes in the facedown array containing all of the card object elements
       ** Post-conditions: Returns the specific rank of an array member of facedown at i, from the deck class
       *******************************************************************/
      string get_facedown_rank(int);

      /******************************************************************* 
       ** Function: string deck::get_facedown_suit()
       ** Description: Gets the suit of a specific facedown array member of the deck class
       ** Parameters: int i
       ** Pre-conditions: Takes in the facedown array containing all of the card object elements
       ** Post-conditions: Returns the specific suit of an array member of facedown at i, from the deck class
       *******************************************************************/
      string get_facedown_suit(int);

      /******************************************************************* 
       ** Function: void deck::set_facedown()
       ** Description: Sets the rank and suit of a specific facedown array member of the deck class
       ** Parameters: int i, string p_suit, string p_rank
       ** Pre-conditions: Takes in the specific array index i, a string p_suit for suit, and a string p_rank for rank
       ** Post-conditions: Assigns p_suit to the suit member and p_rank to the rank member of the hand class at the specified i for the facedown array
       *******************************************************************/
      void set_facedown(int, string,  string);

      /******************************************************************* 
       ** Function: string deck::get_faceup_rank()
       ** Description: Gets the rank of a specific faceup  array member of the deck class
       ** Parameters: int i
       ** Pre-conditions: Takes in the faceup array containing all of the card object elements
       ** Post-conditions: Returns the specific rank of an array member of faceup at i, from the deck class
       *******************************************************************/
      string get_faceup_rank(int);

      /******************************************************************* 
       ** Function: string deck::get_faceup_suit()
       ** Description: Gets the suit of a specific faceup array member of the deck class
       ** Parameters: int i
       ** Pre-conditions: Takes in the faceup array containing all of the card object elements
       ** Post-conditions: Returns the specific suit of an array member of faceup  at i, from the deck class
       *******************************************************************/
      string get_faceup_suit(int);

      /******************************************************************* 
       ** Function: void deck::set_faceup()
       ** Description: Sets the rank and suit of a specific faceup  array member of the deck class
       ** Parameters: int i, string p_suit, string p_rank
       ** Pre-conditions: Takes in the specific array index i, a string p_suit for suit, and a string p_rank for rank
       ** Post-conditions: Assigns p_suit to the suit member and p_rank to the rank member of the hand class at the specified i for the faceup array
       *******************************************************************/
      void set_faceup(int, string, string);

      // game-play functions
      /******************************************************************* 
       ** Function: void deck::shuffle()
       ** Description: Shuffles all of the array elements (cards) in the deck of cards
       ** Parameters: none
       ** Pre-conditions: Takes in the ordered array of facedown, containing "cards" in order
       ** Post-conditions: Swaps the cards randomly within the array, effectively "shuffling the cards" in  a game
       *******************************************************************/
      void shuffle();
};

#endif

