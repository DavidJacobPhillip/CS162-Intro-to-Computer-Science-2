#ifndef SEALION_HPP
#define SEALION_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Animal.hpp"

using namespace std;

class Sealion : public Animal {
	private:
	public:
		/*******************************************************************
		** Function: Sealion();
		** Description: The constructor for the sealion object
		** Parameters: n/a
		** Pre-conditions: inherits the animal class's member variables
		** Post-conditions: Creates a sealion object
		*******************************************************************/
		Sealion();

		/*******************************************************************
		** Function: ~Sealion();
		** Description: The destructor for the sealion object
		** Parameters: n/a
		** Pre-conditions: Takes in the existing sealion class object
		** Post-conditions: Destroys the current sealion object
		*******************************************************************/
		~Sealion();
};

#endif