//Program #7: Crazy Eights: Hand.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Hand Class Implementation Code: Hand.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "Hand.hpp"
#include "Card.hpp"

using namespace std;

// constructor
hand::hand(){
   n_cards = 7;
   cards = new card[n_cards];
}

// destructor
hand::~hand(){
   delete [] cards;
}

// copy constructor
hand::hand(const hand& existing){
   this->n_cards = existing.n_cards;
   this->cards = new card[this->n_cards];
   for (int i = 0; i < this->n_cards; i++){
      this->cards[i] = existing.cards[i];
   }
}

// overload assignment operator
hand& hand::operator= (const hand& existing){
   delete [] this->cards;

   this->n_cards = existing.n_cards;
   this->cards = new card[this->n_cards];
   for (int i = 0; i < this->n_cards; i++){
      this->cards[i] = existing.cards[i];
   }

   return *this;
}

// getters & setters
int hand::get_n_cards(){
   return n_cards;
}

void hand::set_n_cards(int p_n_cards){
   n_cards = p_n_cards;
}

string hand::get_hand_rank(int i){
   return cards[i].get_rank();
}

string hand::get_hand_suit(int i){
   return cards[i].get_suit();
}

void hand::set_hand(int i, string p_suit, string p_rank){
   cards[i].set_rank(p_rank);
   cards[i].set_suit(p_suit);
}

// game-design functions
void hand::subtract(int avoid){
   n_cards--;
   card* cards = new card[n_cards];

   int j =0;
   for (int i = 0; i < this->n_cards + 1; i++){
      if (i != avoid){
	 cards[j].set_suit(this->cards[i].get_suit());
	 cards[j].set_rank(this->cards[i].get_rank());
	 j++;
      }
   }

   delete [] this->cards;
   this->cards = cards;
}

void hand::add(){
   n_cards++;
   card* cards = new card[n_cards];

   for (int i = 0; i < this->n_cards - 1; i++){
      cards[i].set_suit(this->cards[i].get_suit());
      cards[i].set_rank(this->cards[i].get_rank());
   }

   delete [] this->cards;
   this->cards = cards;
}


