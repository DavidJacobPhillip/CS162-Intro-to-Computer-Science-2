#ifndef ROOM_HPP
#define ROOM_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"
#include "Bats.hpp"
#include "Gold.hpp"
#include "Pit.hpp"
#include "Start.hpp"
#include "Wumpus.hpp"

using namespace std;

class Room{
    private:
    Event *event;
    bool contains; // determines if there is an event
    bool user;
    string type;

    public:
    // constructors & destructors
    /*******************************************************************
    ** Function: Room()
    ** Description: The constructor for the Room class containing an Event
    ** Parameters: n/a
    ** Pre-conditions: none (no parameters)
    ** Post-conditions: Creates an Room object
	*******************************************************************/
    Room();

    /*******************************************************************
    ** Function: ~Room()
    ** Description: The destructor for the Room class containing an Event
    ** Parameters: n/a
    ** Pre-conditions: Takes in the existing Room object
    ** Post-conditions: Destroys the current Room object
	*******************************************************************/
    ~Room();

    // getters
    /*******************************************************************
    ** Function: getter functions (ex get_event();)
    ** Description: It returns the specific member variables of the class (respectively in order, event, contains, user, type)
    ** Parameters: n/a
    ** Pre-conditions: The specific member variable of the class is taken in
	** Post-conditions: The specific member variable of the class is returned
	*******************************************************************/
    Event* get_event();
    bool get_contains();
    bool get_user();
    string get_type();

    // setters
    /*******************************************************************
    ** Function: setter functions (ex get_event();)
    ** Description: It takes in a parameter to set the member variables of the class (respectively in order, event, contains, user, type)
    ** Parameters: The respective type of member variable the setter is changing
    ** Pre-conditions: It takes in a parameter of the specific member variable type, along with the member variable of the class
    ** Post-conditions: The member variable of the class is set to be equal to the parameter
	*******************************************************************/
    void set_event(Event*);
    void set_contains(bool);
    void set_user(bool);
    void set_type(string);
    

};

#endif