//Program #7: Crazy Eights: prog.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Driver File Code: Prog.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "CrazyEights.hpp"

using namespace std;

/**********************************************************
 ** Program: CrazyEights.cpp
 ** Author: Santosh Ramesh
 ** Date: 2-4-20
 ** Description: This program is a crazy eights game that allows a user to play against the computer. The game works by dealing each player a hand of 7 cards at the beginning, creating one face-up deck, and one face-down deck. The goal is to get rid of all your cards by either placing the same suit/rank card on the face-up pile, or by placing a crazy-eights wild-card which can be placed on any other card. If the user doesn't have a card to place on the face-up pile, they take one from the face-down deck. The game ends when either all the cards in the deck are finished, or when a user's hand runs out.
 ** Inputs: Determining who wants to go first, the option to play for a move (i.e the card to be placed on the face-up pile, or to draw a card), choosing a suit for the crazy eights, and repeating the game. 
 ** Output: The game-board itself, which displays the face-up card, and each player's hand.
 **********************************************************/
int main(){
   start();
}



