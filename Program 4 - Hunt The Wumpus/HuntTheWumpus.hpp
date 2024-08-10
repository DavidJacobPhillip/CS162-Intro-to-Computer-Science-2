#ifndef HUNTTHEWUMPUS_HPP
#define HUNTTHEWUMPUS_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Room.hpp"

using namespace std;

// starts the game
/*******************************************************************
** Function: start();
** Description: Starts the entire program, and makes the calls to check the command line and start a game
** Parameters: int argc, char** argv
** Pre-conditions: Takes in the command line prompts
** Post-conditions: Determines if the command-line prompts are appropriate, and starts the game
*******************************************************************/
void start(int, char**);

/*******************************************************************
** Function: command_line_check();
** Description: Checks if the command-line prompts are valid
** Parameters: int argc, char** argv, string &mode, int &size
** Pre-conditions: Takes in the command-line prompts
** Post-conditions: Outputs the correct (potentially modified) size and mode
*******************************************************************/
void command_line_check(int, char **, string&, int&);

/*******************************************************************
** Function: story_line();
** Description: Prints out the directions to play the gae
** Parameters: string& mode
** Pre-conditions: Takes in the mode of the game
** Post-conditions: Displays the mode, and the directions depending on if the user decided to view them
*******************************************************************/
void story_line(string&);

/*******************************************************************
** Function: game();
** Description: Contains all of the calls required for one game
** Parameters: string &mode, int &size
** Pre-conditions: Takes in the game mode, and the size of the board
** Post-conditions: Creates a game with the above specifications 
*******************************************************************/
void game(string &, int &);

/*******************************************************************
** Function: initializer();
** Description: Initializes the board, by randomly placing bats, starting room, pits, gold, and wumpus
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, int &w_row, int &w_col
** Pre-conditions: Takes in an empty 2-D vector of rooms
** Post-conditions: Adds events to random rooms in the 2-D vector
*******************************************************************/
void initializer(vector<vector<Room>>&, int&, int&, int&, int&, int&);

/*******************************************************************
** Function: random();
** Description: Determines which random room currently doesn't have an event
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col
** Pre-conditions: Takes in an empty 2-D vector of rooms
** Post-conditions: Returns the row and col of a room without any events
*******************************************************************/
void random(vector<vector<Room>>&, int&, int&, int&);

/*******************************************************************
** Function: print();
** Description: Prints out the board with the various events (depending on the mode)
** Parameters: vector<vector<Room>> &cave, int &size, int &turn, string &mode, int &shots
** Pre-conditions: Takes in the 2-D vector of rooms
** Post-conditions: Prints the 2-D vector to the console
*******************************************************************/
void print(vector<vector<Room>>&, int&, int&, string&, int&);

/*******************************************************************
** Function: move();
** Description: Determines where the player wants to move appropriately based on where they currently are
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col
** Pre-conditions: Takes in the2-D vector of rooms along with the player's current position
** Post-conditions: Makes a call to the move_action function with the desired player movement
*******************************************************************/
void move(vector<vector<Room>> &, int &, int &, int &);

/*******************************************************************
** Function: move_action();
** Description: Moves the player within the cave grid
** Parameters: vector<vector<Room>> &cave, string &direction, int &row, int &col
** Pre-conditions: Takes in the 2-D vector of rooms, along with the direction the player wants to move
** Post-conditions: Modifies the current location of the player
*******************************************************************/
void move_action(vector<vector<Room>> &, string &, int&, int&);

/*******************************************************************
** Function: percepts();
** Description: Displays all of the adjacent room's "percept" statements (descriptions), excluding diagonals
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col
** Pre-conditions: Takes in the2-D vector of rooms, and the player's current position
** Post-conditions: Prints out the percept statements to the console 
*******************************************************************/
void percepts(vector<vector<Room>> &, int &, int &, int &);

/*******************************************************************
** Function: decision();
** Description: Determines if the player would like to move or shoot (if possible) a specific turn
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &wumpus
** Pre-conditions: Takes in the2-D vector of rooms, the players current position, the shots they currently have, and the bool determining the wumpus' health
** Post-conditions: Makes a call either to the move() or shoot() function based on the player's choice input
*******************************************************************/
void decision(vector<vector<Room>> &, int &, int &, int &, int&, bool&);

/*******************************************************************
** Function: shoot();
** Description: Determines where the player wants to shoot appropriately based on where they currently are
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, bool &wumpus
** Pre-conditions: Takes in the 2-D vector of rooms along with the player's current position
** Post-conditions: Makes a call to the shoot_action function with the desired player shooting movement
*******************************************************************/
void shoot(vector<vector<Room>> &, int &, int &, int &, bool &);

/*******************************************************************
** Function: shoot_miss();
** Description: Determines what happens to the Wumpus if the player misses a shot
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col
** Pre-conditions: Takes in the 2-D vector of rooms, along with the player position
** Post-conditions: Either changes the current position of the Wumpus or keeps it in the same location
*******************************************************************/
void shoot_miss(vector<vector<Room>> &, int &size, int &row, int &col);

/*******************************************************************
** Function: shoot_action();
** Description: Checks the location wherein the player shot for the Wumpus, and kills it if present
** Parameters: vector<vector<Room>> &cave, string &direction, int &row, int &col, bool &wumpus, int &misses, int &size
** Pre-conditions: Takes in the 2-D vector of rooms, the player's position, and the player's shot direction
** Post-conditions: Kills the Wumpus if present in the shooting direction, or does nothing
*******************************************************************/
void shoot_action(vector<vector<Room>> &, string &, int&, int&, bool&, int&, int&);

/*******************************************************************
** Function: action();
** Description: Determines what happens to a player if they enter a room with a specific event
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &alive, bool &gold, int &turn, bool &wumpus, int &w_row, int&w_col
** Pre-conditions: Takes in the 2-D vector of rooms, the player's current position, and other side-variables (such as whether the player has the gold, if the wumpus is alive, number of shots left, etc.)
** Post-conditions: Displays the action() of the room, and either ends the game (and proceeds to call the reset() function) or lets the player continue
*******************************************************************/
void action(vector<vector<Room>> &, int &, int &, int &, int &, bool &, bool &, int &, bool&, int&, int&);

/*******************************************************************
** Function: deleter();
** Description: Deletes all of the dynamically created objects
** Parameters: vector<vector<Room>> &cave, int &size
** Pre-conditions: Takes in the 2-D vector of rooms
** Post-conditions: Deletes all of the dynamic events-child objects held within the rooms within the 2-D vectors 
*******************************************************************/
void deleter(vector<vector<Room>> &, int &);

/*******************************************************************
** Function: reset();
** Description: Determins if the user would like to restart the game with the same game-board
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, int &turn, bool &alive, bool &gold, bool &wumpus, int &w_row, int &w_col
** Pre-conditions: Takes in the 2-D vector of rooms, the player's current position, and other side-variables (such as whether the player has the gold, if the wumpus is alive, number of shots left, etc.)
** Post-conditions: Either deletes the board and vector, or resets the board to how it initially was
*******************************************************************/
void reset(vector<vector<Room>> &, int &, int &, int &, int &, int &, bool &, bool &, bool&, int&, int&);

/*******************************************************************
** Function: again();
** Description: Determins if the user would like to restart the game with a different game-board
** Parameters: bool &another, int &size
** Pre-conditions: Takes in the another bool, and the size of the new board if they choose to create a new game
** Post-conditions: Either determines the size of the new board, or ends the game by setting another to false
*******************************************************************/
void again(bool &, int &);

/*******************************************************************
** Function: ai();
** Description: Controls the AI-computer player to go through a game
** Parameters: vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &wumpus
** Pre-conditions: Takes in the 2-D vector of rooms, the shots remainihg, and the current position
** Post-conditions: Goes through an entire game using the AI-player
*******************************************************************/
void ai(vector<vector<Room>> &, int &, int &, int &, int&, bool&);

#endif