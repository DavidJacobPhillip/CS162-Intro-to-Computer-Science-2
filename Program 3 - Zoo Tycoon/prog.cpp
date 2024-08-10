#include <iostream>
#include <cstdlib>
#include <string>
#include "Zoo.hpp"
#include "ZooTycoon.hpp"

using namespace std;

/**********************************************************
** Program: ZooTycoon.cpp
** Author: Santosh Ramesh
** Date: 2-12-20
** Description: This is a game wherein the user can farm for Zoo animals. The user starts out with $100,000, and each month they are given the chance to purchase a tiger, sealion, or bear. 
Furthermore, each month, the player has to feed the player with cheap, regular, or premium food to determine how likely the animal is to become sick. There is also a special event that occurs
at the end of each month: (1) a birth in the Zoo, (2) increased revenue, (3) an animal becomes sick, (4) no special event. The game ends when the player either runs out of money or they decide to quit.
** Inputs: Each month the user inputs what animal they would like to buy, how much of that animal, and what food they would like to buy for that animal. Based on the special event, there is also
special event user-inputs required; if there is a sick animal, the user has to determine if they want to treat it or not. There is also an input at the end of each turn where the player
determines if they want to play again or not. 
** Output: The console displays the balance left in the bank after revenue/costs,  the number of animals (categorized into adults, babies, and adolescents), along with prompts for user decisions.
**********************************************************/

int main(){
    srand(time(NULL));
    game();

    return 0;
}
