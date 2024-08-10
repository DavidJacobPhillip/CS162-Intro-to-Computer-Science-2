#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Bats.hpp"
#include "Gold.hpp"
#include "Pit.hpp"
#include "Start.hpp"
#include "Wumpus.hpp"
#include "Room.hpp"

using namespace std;

// constructors & destructors
Room::Room(){
    contains = false;
    user = false;
    type = " ";
}

Room::~Room(){
    //delete event;
}

// getters
Event* Room::get_event(){
    return event;
}

bool Room::get_contains(){
    return contains;
}

bool Room::get_user(){
    return user;
}

string Room::get_type(){
    return type;
}

// setters
void Room::set_event(Event* p_event){
    event = p_event;
}

void Room::set_contains(bool p_contains){
    contains = p_contains;
}

void Room::set_user(bool p_user){
    user = p_user;
}

void Room::set_type(string p_type){
    type = p_type;
}
