#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Bats.hpp"

using namespace std;

Bats::Bats(){
    percept = "You hear wings flapping.";
    type = "B";
    user = false;
}

Bats::~Bats(){

}

// game-design element
void Bats::action(){
    cout << "You have entered a room with super bats!" << endl;
    cout << "The bats attack and carry you to a different room..." << endl;
}

// getters
string Bats::get_percept(){
    return percept;
}

string Bats::get_type(){
    return type;
}

bool Bats::get_user(){
    return user;
}

// setters
void Bats::set_user(bool p_user){
    user = p_user;
}