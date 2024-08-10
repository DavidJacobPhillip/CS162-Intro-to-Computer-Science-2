#ifndef ZOO_HPP
#define ZOO_HPP

#include <iostream>
#include <cstdlib>
#include <string>
#include "Bear.hpp"
#include "Tiger.hpp"
#include "Sealion.hpp"

using namespace std;

class Zoo{
	private:
		// handling the number of bears
		int b_num;
		Bear *bears;
		
		// handling the number of sealions
		int s_num;
		Sealion *sealions;

		// handling the number of tigers
		int t_num;
		Tiger *tigers;

		// the remaining balance & base food cost
		int balance;
		int base_food;
   	public:
		// constructors & destructors
		/*******************************************************************
		** Function: Zoo()
		** Description: The constructor for the Zoo class object
		** Parameters: n/a
		** Pre-conditions: none (no parameters)
		** Post-conditions: Creates a zoo object
		*******************************************************************/
		Zoo();

		/*******************************************************************
		** Function: ~Zoo
		** Description: The destructor for the zoo object, along with dynamic memory management
		** Parameters: n/a
		** Pre-conditions: Takes in the existing zoo class object
		** Post-conditions: Destroys the current zoo object, and deletes the tiger, bear, and sealion arrays
		*******************************************************************/
		~Zoo();	

		//copy constructor & assignment operator overloader
		/*******************************************************************
		** Function: Zoo();
		** Description: The copy constructor for the zoo object
		** Parameters: const Zoo &existing
		** Pre-conditions: Takes in the previously created zoo object
		** Post-conditions: Creates a new zoo object with the same specifications as the existing zoo object
		*******************************************************************/
		Zoo(const Zoo&);

		/*******************************************************************
		** Function: Zoo& operator();
		** Description: The overload assignment operator
		** Parameters: const Zoo &existing
		** Pre-conditions: Takes in the previously created zoo object
		** Post-conditions: Assigns the right-side zoo object's variables and values to the left-side zoo-object (in respect to the "=" sign)
		*******************************************************************/
		Zoo& operator= (const Zoo&);

		// getters
		/*******************************************************************
		** Function: getter functions (ex get_base_food();)
		** Description: It returns the specific member variables of the class (respectively in order, base_food, b_num, t_num, s_num, balance)
		** Parameters: n/a
		** Pre-conditions: The specific member variable of the class is taken in
		** Post-conditions: The specific member variabel of the class is returned
		*******************************************************************/
		int get_base_food();
		int get_b_num();
		int get_t_num();
		int get_s_num();
		int get_balance();

		// special getters for the object arrays (bear, tiger, and sealions respectively)
		/*******************************************************************
		** Function: get_bear();
		** Description: It returns the pointer to the specific animal-child object array (bears, tigers, and sealions respectively)
		** Parameters: n/a
		** Pre-conditions: Takes in the animal-child object array
		** Post-conditions: Returns the pointer to the animal-child object array
		*******************************************************************/
		Bear* get_bear();
		Tiger* get_tiger();
		Sealion* get_sealion();

		// setters
		/*******************************************************************
		** Function: setter functions (ex set_babies();)
		** Description: It takes in a parameter to set the member variables of the class (respectively in order, babies, age, sick, feed, purchase, revenue)
		** Parameters: The respective type of member variable the setter is changing (in this case, all ints)
		** Pre-conditions: It takes in a parameter of the specific member variable type, along with the member variable of the class
		** Post-conditions: The member variable of the class is set to be equal to the parameter
		*******************************************************************/
		
		void set_balance(int);
		void set_b_num(int);
		void set_t_num(int);
		void set_s_num(int);
		void set_base_food(int);

		// increasing and decreasing animal array sizes
		/*******************************************************************
		** Function: bear_add();
		** Description: Increases the size of the bears array by one
		** Parameters: n/a
		** Pre-conditions: Takes in the existing bears array
		** Post-conditions: Creates a new bears array with a larger size, and assigns it to the previoius bears array pointer
		*******************************************************************/
		void bear_add();

		/*******************************************************************
		** Function: bear_sub();
		** Description: Decreases the size of the bears array by one
		** Parameters: int avoid
		** Pre-conditions: Takes in the existing bears array, and the index to avoid when making smaller
		** Post-conditions: Creates a new bears array with a smaller size avoiding the index specified in the parameter, and assigns it to the previous bears array pointer.
		*******************************************************************/
		void bear_sub(int);

		/*******************************************************************
		** Function: tiger_add();
		** Description: Increases the size of the tigers array by one
		** Parameters: n/a
		** Pre-conditions: Takes in the existing tigers array
		** Post-conditions: Creates a new tigers array with a larger size, and assigns it to the previoius tigers array pointer
		*******************************************************************/
		void tiger_add();

		/*******************************************************************
		** Function: tiger_sub();
		** Description: Decreases the size of the tigers array by one
		** Parameters: int avoid
		** Pre-conditions: Takes in the existing tigers array, and the index to avoid when making smaller
		** Post-conditions: Creates a new tigers array with a smaller size avoiding the index specified in the parameter, and assigns it to the previous tigers array pointer.
		*******************************************************************/
		void tiger_sub(int);

		/*******************************************************************
		** Function: sealion_add();
		** Description: Increases the size of the sealions array by one
		** Parameters: n/a
		** Pre-conditions: Takes in the existing sealions array
		** Post-conditions: Creates a new sealions array with a larger size, and assigns it to the previoius sealions array pointer
		*******************************************************************/
		void sealion_add();

		/*******************************************************************
		** Function: sealion_sub();
		** Description: Decreases the size of the sealion array by one
		** Parameters: int avoid
		** Pre-conditions: Takes in the existing sealions array, and the index to avoid when making smaller
		** Post-conditions: Creates a new sealions array with a smaller size avoiding the index specified in the parameter, and assigns it to the previous sealions array pointer.
		*******************************************************************/
		void sealion_sub(int);


		// game-design functions
		/*******************************************************************
		** Function: current();
		** Description: Displays the current number of tigers, bears, and sealions categorized based on babies (less than 6 months), adolescents (less than 48 months), and adults
		** Parameters: n/a
		** Pre-conditions: Takes in the existing animal-object arrays
		** Post-conditions: Prints out the specific number of each animal-age category
		*******************************************************************/
		void current();

		/*******************************************************************
		** Function: revenue();
		** Description: Determines the revenue the animals produce each round
		** Parameters: n/a
		** Pre-conditions: Takes in the animal-array classes
		** Post-conditions: Sets the current balance to the current balance plus the amount of revenue produced by the animals
		*******************************************************************/
		int revenue();

		/*******************************************************************
		** Function: food_cost();
		** Description: Determines the cost of each of the 3 types of feed
		** Parameters: int &cheap, int &regular, int &premium
		** Pre-conditions: Takes in the undefined cheap, regular, and premium pricing, along with the animal-child arrays
		** Post-conditions: Allows the user to choose between the 3 types of food, with printed food pricing
		*******************************************************************/
		void food_cost(int &, int &, int &);

		/*******************************************************************
		** Function: ager();
		** Description: Increases the age of the animals each turn by 1 month
		** Parameters: n/a
		** Pre-conditions: Takes in the animal-child arrays
		** Post-conditions: Increases the age of each animal within the array by 1
		*******************************************************************/
		void ager();

		/*******************************************************************
		** Function: boom();
		** Description: The special event where there is increased Zoo attendence
		** Parameters: n/a
		** Pre-conditions: The sealion array is taken into consideration
		** Post-conditions: For each sealion, extra revenue is produced; this total revenue is then added to the balance
		*******************************************************************/
		void boom();

		/*******************************************************************
		** Function: sick();
		** Description: The special event where an animal gets sick in the zoo
		** Parameters: n/a
		** Pre-conditions: All three of the animal-child arrays are taken into consideration
		** Post-conditions: A random animal is chosen to be sick; the user then chooses to either treat the animal, or remove them from the array
		*******************************************************************/
		void sick();

		/*******************************************************************
		** Function: chooser();
		** Description: Randomly chooses an animal
		** Parameters: string &animal, int &index
		** Pre-conditions: Takes in an undefined animal string and index
		** Post-conditions: Modifies the animal string and index based on the randomized chooser
		*******************************************************************/
		void chooser(string&, int&);

		/*******************************************************************
		** Function: determiner();
		** Description: Determines the age and cost to treat an animal based on index and the name of the animal
		** Parameters: string &animal, int &index, string &age, int &cost)
		** Pre-conditions: Takes in the pre-defined animal and index, along with the undefined age and cost
		** Post-conditions: Modifies age and cost and returns this
		*******************************************************************/
		void determiner(string&, int&, string&, int&);

		/*******************************************************************
		** Function: birth();
		** Description: The special event that increases the size of a respective animal array by the number of babies present
		** Parameters: n/a
		** Pre-conditions: Takes in the specific animal array to have babies
		** Post-conditions: Increases the size of that specific animal array, and grows its size by the number of babies a species can produce at one time
		*******************************************************************/
		void birth();

};

#endif
