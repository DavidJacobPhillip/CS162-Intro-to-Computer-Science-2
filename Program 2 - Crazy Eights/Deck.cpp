//Program #7: Crazy Eights: Deck.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Deck Class Implementation Code: Deck.cpp
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include "Deck.hpp"
#include "Card.hpp"

using namespace std;

// constructor & destructor
deck::deck(){
   n_cards = 52;
   string temp = "";

   // setting the rank & suit of each of the cards in the deck
   for (int i = 0; i < 13; i++){
      facedown[i].set_suit("H");
      temp = modifier.converter(i);
      facedown[i].set_rank(temp);
   }
   for (int i = 13; i < 26; i++){
      facedown[i].set_suit("D");
      temp = modifier.converter(i-13);
      facedown[i].set_rank(temp);
   }
   for (int i = 26; i < 39; i++){
      facedown[i].set_suit("C");
      temp = modifier.converter(i-26);
      facedown[i].set_rank(temp);
   }
   for (int i = 39; i < 52; i++){
      facedown[i].set_suit("S");
      temp = modifier.converter(i-39);
      facedown[i].set_rank(temp);
   }

   // suits 0-3 represents hearts, diamonds, clubs and spades respectively
   // ranks 0-12 represents the ranks 2-9, jacks, queens, kings, ace respectively 
}

deck::~deck(){

}

// getters & setters
int deck::get_n_cards(){
   return n_cards;
}

void deck::set_n_cards(int p_n_cards){
   n_cards = p_n_cards;
}

string deck::get_facedown_rank(int i){
   return facedown[i].get_rank();
}

string deck::get_facedown_suit(int i){
   return facedown[i].get_suit();
}

void deck::set_facedown(int i, string p_suit, string p_rank){
   facedown[i].set_rank(p_rank);
   facedown[i].set_rank(p_suit);
}

string deck::get_faceup_rank(int i){
   return faceup[i].get_rank();
}

string deck::get_faceup_suit(int i){
   return faceup[i].get_suit();
}

void deck::set_faceup(int i, string p_suit, string p_rank){
   faceup[i].set_rank(p_rank);
   faceup[i].set_suit(p_suit);
}

// game-play functions
// shuffling the deck of cards
void deck::shuffle(){
   string temp_suit = "";
   string temp_rank = "";
   int number = 0;

   for (int i = 0; i < 52; i++){
      number = (rand() % 51) + 1;

      temp_suit = facedown[i].get_suit();
      temp_rank = facedown[i].get_rank();
      facedown[i].set_suit(facedown[number].get_suit());
      facedown[i].set_rank(facedown[number].get_rank());
      facedown[number].set_suit(temp_suit);
      facedown[number].set_rank(temp_rank);
   }

   // functionality to print out all of the cards
   cout << endl;

   /*
      cout << "Printing out all of the cards" << endl;
      for (int i = 0; i < 52; i++){
      cout << "Card #" << i + 1 << ": " << facedown[i].get_suit() << ", " << facedown[i].get_rank() << endl;
      }
      */

}







