#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Gold.hpp"

using namespace std;

Gold::Gold(){
    percept = "You see a glimmer nearby.";
    type = "G";
    user = false;
}

Gold::~Gold(){

}

// game-design element
void Gold::action(){
    cout << "You have entered the room with the gold treasures!" << endl;
    cout << "You grab as much gold as you can!" << endl;
    cout << "Now you just have to get back to the starting room safely..." << endl;
}

// getters
string Gold::get_percept(){
    return percept;
}

string Gold::get_type(){
    return type;
}

bool Gold::get_user(){
    return user;
}

// setters
void Gold::set_user(bool p_user){
    user = p_user;
}