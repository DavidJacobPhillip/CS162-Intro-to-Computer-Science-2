#include <iostream>
#include <cstdlib>
#include <string>
#include <ctime>
#include "Room.hpp"
#include "HuntTheWumpus.hpp"

using namespace std;
/**********************************************************
** Program: HuntTheWumpus.hpp
** Author: Santosh Ramesh
** Date: 3-3-20
** Description: This program is a game called "Hunt the Wumpus", wherein a mythical creature called the "Wumpus" lives within a cave and hoards gold; 
the goal of the game is to retrieve the gold without dying to the Wumpus or to the other dangerous traps within the cave. 
In regards to the program itself, in regular game-play mode the player starts out in random square of a user-designated square cave size (minimum size of 4). 
Within the same game, the player has the option to either move (left, right, up, or down) or shoot an arrow in one of the same 4 directions (by using the "W", "A", "S", or "D" keys). 
If the player decides to shoot an arrow in a specified direction, there are 2 effects that may occur: (1) the Wumpus gets shot by the arrow, and dies, or (2) the Wumpus is woken up, and randomly moves to a different room. 
The player has 3 total arrows to use. If the player enters a room with the Wumpus, he/she is immediately eaten and the game ends. 
Aside from the initial room containing the Wumpus and another room containing a player, there is 1 room containing the gold, 2 rooms containing super-bats, and 2 rooms containing bottomless pits. 
If a player ends a room with a bottomless pit, they instantly die. If a player enters a room containing superbats, he/she is randomly transported to another room within the cave (which has the possibility of being dangerous). 
In order for the game to end without the player dying, they must find the gold without being killed by the Wumpus, and return back to their original spot (where they first started the game, which contains their "escape ladder"). 
To help guide the player through the rooms, there are 4 "percepts" that are activated and printed to the console when a player is adjacent to a non-empty room: 
(1) Wumpus - "you smell a terrible stench", (2) gold - "you see a glimmer nearby", (3) bottomless pit - "you feel a breeze nearby", (4) bats - "you hear wings flapping". 
Once a game ends (either with a death or a successful heist), the player is given the option to either redo the same map, try a new map configuration (with the same size), or quit the program. 
The program also contains 2 other modes: (1) debug mode, wherein all of the room's elements are visible, and (2) AI mode, where the game is played by the computer. 
The program will contain error handling to prevent the player from inputting incorrect values for their turn choices.
** Inputs: The inputs include the direction to move the player, where to shoot, whether to restart the game, with what board size
** Output: The actual game board, along with the percepts of the nearby rooms
**********************************************************/

int main(int argc, char **argv){
    srand(time(NULL));
    start(argc, argv);
}
