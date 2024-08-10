#ifndef TIGER_HPP
#define TIGER_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

using namespace std;

class Tiger : public Animal{
	private:
	public:
		// constructor & destructor
		/*******************************************************************
		** Function: Tiger(); 
		** Description: The constructor for the tiger object
		** Parameters: n/a
		** Pre-conditions: inherits the animal class's member variables
		** Post-conditions: Creates a tiger object
		*******************************************************************/
		Tiger();

		/*******************************************************************
		** Function: ~Tiger();
		** Description: The destructor for the tiger object
		** Parameters: n/a
		** Pre-conditions: Takes in the existing tiger class object
		** Post-conditions: Destroys the current tiger object
		*******************************************************************/
		~Tiger();
};

#endif