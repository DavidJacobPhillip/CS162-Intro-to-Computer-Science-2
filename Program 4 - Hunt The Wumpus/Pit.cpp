#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Pit.hpp"

using namespace std;

Pit::Pit(){
    percept = "You feel a breeze.";
    type = "P";
    user = false;
}

Pit::~Pit(){

}

// game-design element
void Pit::action(){
    cout << "You have entered a room with a bottomless pit" << endl;
    cout << "You fall to your death..." << endl;
}

// getters
string Pit::get_percept(){
    return percept;
}

string Pit::get_type(){
    return type;
}

bool Pit::get_user(){
    return user;
}

// setters
void Pit::set_user(bool p_user){
    user = p_user;
}