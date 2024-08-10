#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Event{
    protected:
    string percept; // the string containing the percept
    string type; // the string containing what the room is
    bool user; // the bool determining if the user is on or not on the square

    public:
    // constructor & destructor
    /*******************************************************************
    ** Function: Event()
    ** Description: The constructor for the Event base class
    ** Parameters: n/a
    ** Pre-conditions: none (no parameters)
    ** Post-conditions: Creates an event object
	*******************************************************************/
    Event();

    /*******************************************************************
    ** Function: ~Event()
    ** Description: The destructor for the Event base class
    ** Parameters: n/a
    ** Pre-conditions: Takes in the existing Event object
    ** Post-conditions: Destroys the current Event object
	*******************************************************************/
    virtual ~Event();

    // game-design elements
    /*******************************************************************
    ** Function: action();
    ** Description: Displays what happens when the user steps on a square with an event
    ** Parameters: n/a
    ** Pre-conditions: none (no parameters)
    ** Post-conditions: Prints to console what action occurs when a user steps on a square with an event
	*******************************************************************/
    virtual void action() = 0;

    // getters
    /*******************************************************************
    ** Function: getter functions (ex get_percept();)
    ** Description: It returns the specific member variables of the class (respectively in order, percept, user)
    ** Parameters: n/a
    ** Pre-conditions: The specific member variable of the class is taken in
	** Post-conditions: The specific member variable of the class is returned
	*******************************************************************/
    virtual string get_percept() = 0;
    virtual bool get_user() = 0;
};

#endif
