#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Start.hpp"

using namespace std;

Start::Start(){
    percept = "The rope of the starting room is nearby";
    type = "S";
    user = false;
}

Start::~Start(){

}

// game-design element
void Start::action(){
    
}

// getters
string Start::get_percept(){
    return percept;
}

string Start::get_type(){
    return type;
}

bool Start::get_user(){
    return user;
}

// setters
void Start::set_user(bool p_user){
    user = p_user;
}
