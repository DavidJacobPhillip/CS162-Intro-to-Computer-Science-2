//Program #7: Crazy Eights: CrazyEights.cpp
//Santosh Ramesh   CS 162   Intro to CompSci 2   Coker   1-27-20

// Implementation File Code: CrazyEights.cpp
#include <iostream>
#include <cstdlib>
#include <string>
#include "CrazyEights.hpp"
#include "Game.hpp"

using namespace std;

void start(){
   srand(time(NULL));
   cout << "Welcome to Crazy-8's!" << endl;

   bool again = true;
   while(again){
      game event;
      event.create();

      repeat(again);
      //event.~ event();
   }
}

void repeat(bool &again){
   cout << "Would you like to play again? " << endl;
   bool check = true;
   string input = "";

   while (check){
      cin >> input;
      if (input != "yes" && input != "no"){
	 cout << "You have entered an invalid answer, please enter a 'yes' or 'no' answer" << endl;
      } else if (input == "yes"){
	 cout << "Thank you for choosing to play again" << endl;
	 check = false;
      } else{
	 cout << "Thank you for choosing to playing" << endl;
	 check = false;
	 again = false;
      }
   }

}







