#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Implementation.hpp"

using namespace std;

/**********************************************************
** Program: LinkedList.cpp
** Author: Santosh Ramesh
** Date: 3-15-20
** Description: This program involves the implementation of a customized linked-list container, 
that can hold both unsigned and signed integers of various lengths through a template linked-list class; 
the user will be given the option to add elements to either of these application methods. 
The linked list will resemble a "forward linked list", and as such will not contain the pointers 
to the previous nodes. The linked-list class will contain various other functionalities that are 
similar to the Standard Template Library, such as the ability to insert elements (at the front, 
end and middle), but also other features not found in the STL including the implementation to print,
sort, clear, and find all prime numbers of the list. The program will also contain error handling 
to prevent the player from inputting incorrect values.
** Inputs: The inputs include the type of list to be created (unsigned or signed), each number to be inputed
into the list, the place at which each number should be inputed within the list, the method to 
sort the list (ascending or descending), and the decision to restart the entire program. 
** Output: The unordered list, followed by the number of primes (and what those primes are), with
the finally new ordered list.
**********************************************************/

int main(){
    bool again = true;
    while (again){
        start();
        repeat(again);
    }
}


