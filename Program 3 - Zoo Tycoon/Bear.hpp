#ifndef BEAR_HPP
#define BEAR_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

using namespace std;

class Bear : public Animal {
	private:
	public:
		/*******************************************************************
		** Function: Bear();
		** Description: The constructor for the bear object
		** Parameters: n/a
		** Pre-conditions: inherits the animal class's member variables
		** Post-conditions: Creates a bear object
		*******************************************************************/
		Bear();

		/*******************************************************************
		** Function: ~Bear();
		** Description: The destructor for the bear object
		** Parameters: n/a
		** Pre-conditions: Takes in the existing bear class object
		** Post-conditions: Destroys the current bear object
		*******************************************************************/
		~Bear();
};

#endif