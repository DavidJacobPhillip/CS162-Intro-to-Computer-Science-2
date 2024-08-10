#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Wumpus.hpp"

using namespace std;

Wumpus::Wumpus(){
    percept = "You smell a terrible stench.";
    type = "W";
    user = false;
}

Wumpus::~Wumpus(){

}

// game-design element
void Wumpus::action(){
    cout << "You have entered the room with the Wumpus!" << endl;
    cout << "The Wumpus eats you alive..." << endl;
}

// getters
string Wumpus::get_percept(){
    return percept;
}

string Wumpus::get_type(){
    return type;
}

bool Wumpus::get_user(){
    return user;
}

// setters
void Wumpus::set_user(bool p_user){
    user = p_user;
}