//Program #7: Crazy Eights: Game.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Game Class Header Code: Game.hpp
#ifndef GAME_HPP
#define GAME_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.hpp"
#include "Deck.hpp"

using namespace std;

class game {
   private:
      deck cards;
      player players[2];
   public:
      // constructor & destructor
      /******************************************************************* 
       ** Function: game::game()
       ** Description: The constructor for the game function
       ** Parameters: none
       ** Pre-conditions: none (no parameters)
       ** Post-conditions: Creates the game event
       *******************************************************************/
      game();

      /******************************************************************* 
       ** Function: game::~ game()
       ** Description: The destructor for the game event
       ** Parameters: none
       ** Pre-conditions: Takes in the current game event
       ** Post-conditions: Deletes/destroys the current game event
       *******************************************************************/
      ~ game();

      // game-design functions
      /******************************************************************* 
       ** Function: void game::create()
       ** Description: Creates the game by initializing the Deck and Hands, and begins the game by holding all of the function calls for the rest of the functions to the used between the user and computer turns
       ** Parameters: none
       ** Pre-conditions: Makes calls to the deck cards and the players[2] player (which houses the hands)
       ** Post-conditions: Shuffles the deck, and deals out the cards to each of the players
       *******************************************************************/
      void create();

      /******************************************************************* 
       ** Function: void game::first()
       ** Description: Determines if the player would like to go first or not
       ** Parameters: int &turn 
       ** Pre-conditions: Takes in the turn counter
       ** Post-conditions: Modifies the turn counter to either 0 or 1 based on the user's desire to go first or not (every even number is counted as a user turn)
       *******************************************************************/
      void first (int &);

      /******************************************************************* 
       ** Function: void game::initialize()
       ** Description: Creates the face-up pile, and deals the computer and player hands
       ** Parameters: none
       ** Pre-conditions: takes in the unmodified face-up pile, and each of the players' hands
       ** Post-conditions: initializes the face-up pile with the top card of the deck, and takes 7 cards from the deck to modify the players' hands
       *******************************************************************/
      void initialize();

      /******************************************************************* 
       ** Function: void game::player_hand()
       ** Description: Sets the player's hand, and prints it out to the console
       ** Parameters: none
       ** Pre-conditions: Takes in the unmodified player hand, along with the deck of shuffled 52 cards
       ** Post-conditions: Takes the next 7 cards in the deck, and assigns it to the player's hand
       *******************************************************************/
      void player_hand();

      /******************************************************************* 
       ** Function: void game::computer_hand()
       ** Description: Sets the computer's hand, and prints it out to the console
       ** Parameters: none
       ** Pre-conditions: Takes in the unmodified computer  hand, along with the deck of shuffled 52 cards
       ** Post-conditions: Takes the next 7 cards in the deck, and assigns it to the player's hand
       *******************************************************************/
      void computer_hand();

      /******************************************************************* 
       ** Function: void game::top()
       ** Description: Sets the top card (the top most card of the face-up pile)
       ** Parameters: none
       ** Pre-conditions: Takes in the empty face-up array, along with the deck of shuffled 52 cards
       ** Post-conditions: Takes the next card in the deck, and assigns it to the face-up card
       *******************************************************************/
      void top();

      /******************************************************************* 
       ** Function: void game::human_play()
       ** Description: Holds all of the function calls for the human's turn move
       ** Parameters: none
       ** Pre-conditions: Contains the previous turn's human hand, along with the current deck pile
       ** Post-conditions: Changes the human hand and the current deck pile
       *******************************************************************/
      void human_play();

      /******************************************************************* 
       ** Function: void game::computer_play()
       ** Description: Holds all of the function calls for the computer's turn move
       ** Parameters: none
       ** Pre-conditions: Contains the previous turn's computer  hand, along with the current deck pile
       ** Post-conditions: Changes the computer  hand and the current deck pile
       *******************************************************************/
      void computer_play();

      /******************************************************************* 
       ** Function: void game::human_choose()
       ** Description: Determines if the human player has inputed a correct value for what choice they want (error handling)
       ** Parameters: int &choice
       ** Pre-conditions: It takes in the choice that the player decided on
       ** Post-conditions: Either reprompts for a new input, or changes the int choice depending on its validity
       *******************************************************************/
      void human_choose(int &);

      /******************************************************************* 
       ** Function: void game::choice_printer()
       ** Description: Prints out all of the choices for the player's move (all of the cards they have, along with the (1) option of drawing a card)
       ** Parameters: none
       ** Pre-conditions: none (nothing is getting modified)
       ** Post-conditions: the console screen is printed with all of the player's options
       *******************************************************************/
      void choice_printer();

      /******************************************************************* 
       ** Function: void game::human_option()
       ** Description: Determines if the human player's choice of placing down a specific card is valid, and has function calls for drawing a card, or activating a crazy-eight's move.
       ** Parameters: int& option, int player, bool &valid
       ** Pre-conditions: Takes in the option, the current player, and the bool valid to determine if the player's input choice is valid or needs to be changed
       ** Post-conditions: Returns a true if the inputed option chosen by the user is appropriate, and returns a false if the user's input is invalid
       *******************************************************************/
      void human_option(int&, int, bool &);

      /******************************************************************* 
       ** Function: void game::computer_option()
       ** Description: Determines if the computer's random choice of placing down a specific card is valid, and has function calls for drawing a card, or activating a crazy-eight's move.
       ** Parameters: int& option, int player, bool &valid
       ** Pre-conditions: Takes in the option, the current player, and the bool valid to determine if the computer's  input choice is valid or needs to be changed
       ** Post-conditions: Returns a true if the inputed option chosen by the computer is appropriate, and returns a false if the user's input is invalid
       *******************************************************************/
      void computer_option(int&, int, bool &);

      /******************************************************************* 
       ** Function: void game::change_top()
       ** Description: changes the top card of the face-up pile
       ** Parameters: int option, int player
       ** Pre-conditions: It takes in the card played by either the user or the computer
       ** Post-conditions: The top card of the face-up pile is modified to match the card played by the user / computer
       *******************************************************************/
      void change_top(int, int);

      /******************************************************************* 
       ** Function: void game::remove_hand(){
       ** Description: removes the card that the user has inputed down on the pile
       ** Parameters: int option, int player
       ** Pre-conditions: Takes in the option that the player chose, along with the player whose turn it is right now
       ** Post-conditions: Removes the card of the player which they chose to put down on the face-down pile
       *******************************************************************/
      void remove_hand(int, int);

      /******************************************************************* 
       ** Function: void game::card_draw()
       ** Description: draws the top most card from the face-down deck pile and puts it into the player's hand
       ** Parameters: int player
       ** Pre-conditions: Takes in the current player, their hand, along with the current deck
       ** Post-conditions: Adds the drawn card from the deck pile to the current player's hand
       *******************************************************************/
      void card_draw(int);

      /******************************************************************* 
       ** Function: void game::human_eights()
       ** Description: Determines what suit the human player would like their crazy-eight card to be (it also contains error handling to prevent a randomized suit)
       ** Parameters: int option
       ** Pre-conditions: Takes in the current chosen card of the human player that has it's set rank and suit
       ** Post-conditions: Changes the suit of the chosen card of the human player based on the user's input
       *******************************************************************/
      void human_eights(int option);

      /******************************************************************* 
       ** Function: void game::computer_eights()
       ** Description: Randomly selects a suit for the computer's crazy eight card
       ** Parameters: int option
       ** Pre-conditions: Takes in the current chosen card of the computer that has it's set rank and suit
       ** Post-conditions: Changes the suit of the chosen card of the computer  player randomly
       *******************************************************************/
      void computer_eights(int option);

      /******************************************************************* 
       ** Function: bool game::win_check()
       ** Description: Determines if there is a win based on three factors: (1) if the computer's hand is empty, they win (2) if the player's hand is empty they win, (3) if the deck is empty the person with the least cards win (if they both have equal cards then it is a tie)
       ** Parameters: none
       ** Pre-conditions: Takes in the deck and the hands of each of the players
       ** Post-conditions: Returns a false if there is a winner and prints out the winner, or returns a true if the winner cannot be declared with the current turn
       *******************************************************************/
      bool win_check();
};

#endif



