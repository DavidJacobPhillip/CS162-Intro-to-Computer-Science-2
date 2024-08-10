#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

class Animal{
    private:
    protected:
        // animal specifics
        int babies;
        int age;

        // costs with the animal
        int sick;
        int feed;
        int purchase;

        // income from animal
        int revenue;
        

    public:
        // constructors and destructors
        /*******************************************************************
        ** Function: Animal();
        ** Description: Creates the animal object
        ** Parameters: string animal
        ** Pre-conditions: takes in the babies, age, sickness, food cost, purchase price, revenue, along with the parameter of the type of animal
        ** Post-conditions: returns the animal object pre-defined with animal specifications
        *******************************************************************/
        Animal(string);

        /*******************************************************************
        ** Function: ~Animal();
        ** Description: Destroys the animal object
        ** Parameters: n/a
        ** Pre-conditions: takes in the old  animal object
        ** Post-conditions: the animal object is destroyed / deallocated
        *******************************************************************/
        ~Animal();

        // getters
        /*******************************************************************
        ** Function: getter functions (ex get_babies();)
        ** Description: It returns the specific member variables of the class (respectively in order, babies, age, sick, feed, purchase, revenue)
        ** Parameters: n/a
        ** Pre-conditions: The specific member variable of the class is taken in
        ** Post-conditions: The specific member variabel of the class is returned
        *******************************************************************/
        int get_babies();
        int get_age();
        int get_sick();
        int get_feed();
        int get_purchase();
        int get_revenue();
        
        //setters
        /*******************************************************************
        ** Function: setter functions (ex set_babies();)
        ** Description: It takes in a parameter to set the member variables of the class (respectively in order, babies, age, sick, feed, purchase, revenue)
        ** Parameters: The respective type of member variable the setter is changing (in this case, all ints)
        ** Pre-conditions: It takes in a parameter of the specific member variable type, along with the member variable of the class
        ** Post-conditions: The member variable of the class is set to be equal to the parameter
        *******************************************************************/
        void set_babies(int);
        void set_age(int);
        void set_sick(int);
        void set_feed(int);
        void set_purchase(int);
        void set_revenue(int);
};

#endif