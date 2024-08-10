//Program #7: Crazy Eights: Game.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Game Class Implementation Code: Game.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "Game.hpp"
#include "Deck.hpp"

using namespace std;

// constructor & destructor
game::game(){

}

game::~ game(){

}

// game design functions
void game::create(){
   int turn = 0;
   bool winner = true;

   cout << "Initializing the Deck and Hands" << endl;
   cards.shuffle();
   initialize();

   game::first(turn);

   while (winner){
      cout << endl;
      cout << "--------------------------------------------------------------------------------------------" << endl;
      cout << "TURN: " << turn + 1 << endl;
      cout << "TOP CARD: Suit: " << cards.get_faceup_suit(0) << "  Rank: " << cards.get_faceup_rank(0) << endl;
      cout << "--------------------------------------------------------------------------------------------" << endl;

      if (turn % 2 == 0){
	 // player's turn
	 human_play();


      } else{
	 // computer's turn
	 computer_play();
      }

      winner = win_check();
      turn++;
   }
}

bool game::win_check(){
   if (players[0].get_person().get_n_cards() == 0){
      cout << "The user has won!" << endl;
      return false;
   } else if (players[1].get_person().get_n_cards() == 0){
      cout << "The computer has won!" << endl;
      return false;
   } else if (cards.get_n_cards() == 0){
      if (players[0].get_person().get_n_cards() < players[1].get_person().get_n_cards()){
	 cout << "The user has won!" << endl;
	 return false;
      } else if (players[0].get_person().get_n_cards() > players[1].get_person().get_n_cards()){
	 cout << "The computer has won!" << endl;
	 return false;
      } else{
	 cout << "It's a tie!" << endl;
      }
   } else{
      return true;
   }
}

void game::computer_play(){
   cout << "Computer's turn" << endl;
   cout << endl;

   bool valid = true;
   int suit = 0;
   int rank = 0;
   int option = players[1].get_person().get_n_cards() - 1;

   // printing the computer's cards
   cout << "(1) Draw a card" << endl;
   for (int i = 0; i < players[1].get_person().get_n_cards(); i++){
      cout << "(" << i + 2 << ") Suit: " <<  players[1].get_person().get_hand_suit(i);
      cout  << "   Rank: " <<  players[1].get_person().get_hand_rank(i) << endl;
   }

   while(valid){
      // cout << "option: " << option + 1 << endl;
      game::computer_option(option, 0, valid);
      option--;
   }
}

void game::computer_option(int& option, int player, bool &valid){
   if (option == -1){
      cout << "Drawing a card" << endl;
      game::card_draw(1);
      valid = false;
   } else{
      // calls upon the "eights-choice" function for the crazy-eights functionality
      if (players[1].get_person().get_hand_rank(option) == "8"){
	 cout << "Crazy Eights activated by the computer!!" << endl;
	 game::computer_eights(option);
	 game::change_top(option, 1);
	 game::remove_hand(option, 1);
	 valid = false;
      }

      // calls upon other functions to resize the hand and change the top card
      else if (players[1].get_person().get_hand_suit(option) == cards.get_faceup_suit(0) || players[1].get_person().get_hand_rank(option) == cards.get_faceup_rank(0)){
	 game::change_top(option, 1);
	 game::remove_hand(option, 1);
	 valid = false;
	 cout << "Using option " << option + 2 << endl;
      } 
   }
}

void game::computer_eights(int option){
   int random = rand() % 4;
   string suit = "";

   if (random == 0){
      suit = "H";
   } else if (random == 1){
      suit = "D";
   } else if (random == 2){
      suit = "S";
   } else if (random == 3){
      suit = "C";
   }

   string rank = players[1].get_person().get_hand_rank(option);
   players[1].get_person().set_hand(option, suit, rank); 
}

void game::human_play(){
   cout << "Player's turn" << endl;
   cout << endl;

   bool valid = true;
   int suit = 0;
   int rank = 0;
   int option= 0;

   game::choice_printer();
   while(valid){
      game::human_choose(option);
      game::human_option(option, 0, valid);
   }
}

void game::human_option(int& option, int player, bool &valid){
   if (option == -1){
      cout << "Drawing a card" << endl;
      game::card_draw(0);
      valid = false;
   } else{
      // calls upon the "eights-choice" function for the crazy-eights functionality
      if (players[0].get_person().get_hand_rank(option) == "8"){
	 cout << "Crazy Eights!" << endl;
	 game::human_eights(option);
	 game::change_top(option, 0);
	 game::remove_hand(option, 0);
	 valid = false;
      }

      // calls upon other functions to resize the hand and change the top card
      else if (players[0].get_person().get_hand_suit(option) == cards.get_faceup_suit(0) || players[0].get_person().get_hand_rank(option) == cards.get_faceup_rank(0)){
	 cout << "You entered a good card" << endl;
	 game::change_top(option, 0);
	 game::remove_hand(option, 0);
	 valid = false;
      } 

      // informs the user that their choice was incorrect
      else{
	 cout << "Your choice was invalid; it cannot be placed on top of the face-up card" << endl;
      }
   }
}

void game::human_eights(int option){
   bool valid = true;
   string input = "";

   cout << "What suit would you like your Crazy-Eight card to be?" << endl;
   while(valid){
      cout << "Choose a 'H' for hearts, 'S' for spades, 'C' for clubs, and 'D' for diamonds" << endl;
      cin >> input;
      if (input != "H" && input != "D" && input != "S" && input != "C"){
	 cout << "Your choice was invalid, please try again" << endl;
      } else{
	 cout << "Good choice!" << endl;
	 valid = false;
      }
   }
   string suit = input;
   string rank = players[0].get_person().get_hand_rank(option);

   players[0].get_person().set_hand(players[0].get_person().get_n_cards()-1, suit, rank); 
}

void game::card_draw(int player){
   string suit = cards.get_facedown_suit(cards.get_n_cards()-1);
   string rank = cards.get_facedown_rank(cards.get_n_cards()-1);

   players[player].get_person().add();
   players[player].get_person().set_hand(players[player].get_person().get_n_cards()-1, suit, rank); 
   cards.set_n_cards(cards.get_n_cards()-1);
}

void game::remove_hand(int option, int player){
   players[player].get_person().subtract(option);
}

void game::change_top(int option, int player){
   cards.set_faceup(0, players[player].get_person().get_hand_suit(option), players[player].get_person().get_hand_rank(option));
}

void game::choice_printer(){
   cout << "(1) Draw a card" << endl;
   for (int i = 0; i < players[0].get_person().get_n_cards(); i++){
      cout << "(" << i + 2 << ") Suit: " <<  players[0].get_person().get_hand_suit(i);
      cout  << "   Rank: " <<  players[0].get_person().get_hand_rank(i) << endl;
   }
}

void game::human_choose(int &choice){
   bool valid = true;
   int non_digits = 0;
   string input = "";
   int potential = 0;

   cout << endl;
   cout << "Choose an option between (1) and (" << players[0].get_person().get_n_cards() + 1 << ") " << endl;
   while (valid){
      cin >> input;

      for (int i = 0; i < input.length(); i++){
	 if (input[i] < 48 || input[i] > 57){
	    non_digits++;
	 }
      }

      if (non_digits != 0){ 
	 cout << "You have entered a non-integer response, please enter a new input" << endl;
      } else{
	 potential = atoi(input.c_str());

	 if (potential < 1 || potential > players[0].get_person().get_n_cards() + 1){
	    cout << "You have not entered a choice in the given range, please enter a new input" << endl;
	 } else{
	    valid = false;
	    choice = potential - 2;
	 }
      }
      non_digits = 0;
   } 
}

void game::initialize(){
   cout << "Dealing the face-up pile" << endl;
   top();
   cout << "Dealing the computer's cards" << endl;
   computer_hand();
   cout << "Dealing the player's cards" << endl;
   player_hand();

}

void game::top(){
   string suit = "";
   string rank = "";
   int j = 0;

   cout << "Printing the face-up pile:" << endl;

   suit = cards.get_facedown_suit(cards.get_n_cards()-1);
   rank = cards.get_facedown_rank(cards.get_n_cards()-1);

   cards.set_faceup(0, suit, rank);

   cout << "Suit: " << cards.get_faceup_suit(0) << "   Rank: " << cards.get_faceup_rank(0) << endl;

   cards.set_n_cards(cards.get_n_cards()-2);
   cout << endl;
}

void game::player_hand(){
   string suit = "";
   string rank = "";
   int j = 0;

   players[0].set_name("player");

   // setting and printing the players cards
   cout << "Printing the player's cards: " << endl;
   for (int i = cards.get_n_cards() - 6; i < cards.get_n_cards()+1; i++){
      rank = cards.get_facedown_rank(i);
      suit = cards.get_facedown_suit(i);

      players[0].get_person().set_hand(j, suit, rank);

      cout << "Suit: " << players[0].get_person().get_hand_suit(j);
      cout  << "   Rank: " << players[0].get_person().get_hand_rank(j) << endl;
      j++;
   }

   cards.set_n_cards(cards.get_n_cards() - 7);
   cout << endl;
}

void game::computer_hand(){
   string suit = "";
   string rank = "";
   int j = 0;

   players[1].set_name("computer");

   // setting the computer's cards (with commented printing functionality)
   // cout << "Printing the computer's cards: " << endl;
   for (int i = cards.get_n_cards() - 6; i < cards.get_n_cards()+1; i++){
      rank = cards.get_facedown_rank(i);
      suit = cards.get_facedown_suit(i);

      players[1].get_person().set_hand(j, suit, rank);
      /*
	 cout << "Suit: " << players[1].get_person().get_hand_suit(j);
	 cout  << "   Rank: " << players[1].get_person().get_hand_rank(j) << endl;
	 */
      j++;
   }

   cards.set_n_cards(cards.get_n_cards() - 7);
   cout << endl;
}

void game::first(int &turn){
   // the computer will play all odd rounds, while the human will play all even rounds
   cout << endl;
   cout << "Would you like to go first? " << endl;
   bool check = true;
   string input = "";

   while (check){
      // checking for valid input
      cin >> input;
      if (input != "yes" && input != "no"){
	 cout << "You have entered an invalid answer, please enter a 'yes' or 'no' answer" << endl;
      } else if (input == "yes"){
	 cout << "You will begin the first round" << endl;
	 turn = 0;
	 check = false;
      } else{
	 cout << "The computer will begin the first round" << endl;
	 turn = 1;
	 check = false;
      }
   }
}

