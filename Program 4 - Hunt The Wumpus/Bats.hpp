#ifndef BATS_HPP
#define BATS_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Event.hpp"

using namespace std;

class Bats : public Event{
    private:

    public:
    // constructors & destructors
    /*******************************************************************
    ** Function: Bats()
    ** Description: The constructor for the Bats child class
    ** Parameters: n/a
    ** Pre-conditions: none (no parameters)
    ** Post-conditions: Creates an Bats object
	*******************************************************************/
    Bats();

    /*******************************************************************
    ** Function: ~Bats()
    ** Description: The destructor for the Bats child class
    ** Parameters: n/a
    ** Pre-conditions: Takes in the existing Bats object
    ** Post-conditions: Destroys the current Bats object
	*******************************************************************/
    virtual ~Bats();

    // game-design functions
    /*******************************************************************
    ** Function: action();
    ** Description: Displays what happens when the user steps on a square with Bats
    ** Parameters: n/a
    ** Pre-conditions: none (no parameters)
    ** Post-conditions: Prints to console what action occurs when a user steps on a square with Bats
	*******************************************************************/
    void action();

    // getters
    /*******************************************************************
    ** Function: getter functions (ex get_percept();)
    ** Description: It returns the specific member variables of the class (respectively in order, percept, user)
    ** Parameters: n/a
    ** Pre-conditions: The specific member variable of the class is taken in
	** Post-conditions: The specific member variable of the class is returned
	*******************************************************************/
    string get_percept();
    string get_type();
    bool get_user();

    // setters
    /*******************************************************************
    ** Function: setter functions (ex set_percept();)
    ** Description: It takes in a parameter to set the member variables of the class (respectively user)
    ** Parameters: The respective type of member variable the setter is changing
    ** Pre-conditions: It takes in a parameter of the specific member variable type, along with the member variable of the class
    ** Post-conditions: The member variable of the class is set to be equal to the parameter
	*******************************************************************/
    void set_user(bool p_user);
};

#endif