//Program #7: Crazy Eights: Player.hpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Player Class Header Code: Player.hpp
#ifndef PLAYER_HPP
#define PLAYER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include "Hand.hpp"

using namespace std;

class player {
   private:
      hand person;
      string name;
   public:
      // constructor & destructor
      /******************************************************************* 
       ** Function: player::player()
       ** Description: The constructor creates the player object
       ** Parameters: none
       ** Pre-conditions: It takes in the name member of the player class
       ** Post-conditions: Initializes the name to "unknown"

       *******************************************************************/
      player();

      /******************************************************************* 
       ** Function: player::~player()
       ** Description: The deconstructor that deletes/destroys the player class
       ** Parameters: none
       ** Pre-conditions: none (no parameters)
       ** Post-conditions: It deletes the player object
       *******************************************************************/
      ~player();

      // setters & getters
      /******************************************************************* 
       ** Function: string player::get_name()
       ** Description: The getter function for the name member of the player class
       ** Parameters: none
       ** Pre-conditions: It takes in the name member
       ** Post-conditions: Returns the name member
       *******************************************************************/
      string get_name();

      /******************************************************************* 
       ** Function: void player::set_name()
       ** Description: The setter function for the name member of the player class
       ** Parameters: string p_name
       ** Pre-conditions: It takes in a string passed into the function
       ** Post-conditions: The name member of the player class is set to the p_name string
       *******************************************************************/
      void set_name(string);

      /******************************************************************* 
       ** Function: hand& player::get_person()
       ** Description: The getter function for the address of the hand called person
       ** Parameters: none
       ** Pre-conditions: It takes in the address of the person object of the player class
       ** Post-conditions: The hand person is returned
       *******************************************************************/
      hand& get_person();
};

#endif

