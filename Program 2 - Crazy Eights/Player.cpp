//Program #7: Crazy Eights: Player.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Player Class Implementation Code: Player.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "Player.hpp"

using namespace std;

// constructor & destructor
player::player(){
   name = "unknown";
}

player::~player(){

}

// getters & setters
string player::get_name(){
   return name;
}

void player::set_name(string  p_name){
   name = p_name;
}

hand& player::get_person(){
   return person;
}

// game-design functions







