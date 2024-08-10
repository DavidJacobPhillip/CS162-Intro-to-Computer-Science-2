#include <iostream>
#include <cstdlib>
#include <string>
#include "ZooTycoon.hpp"
#include "Zoo.hpp"

using namespace std;

void game(){
    Zoo creation;
    bool alive = true;
    int turn = 0;
    int sickness = 0;

    cout << "Welcome to the Zoo Tycoon! Let's begin the game" << endl;
    cout << "Your beginning balance is: $" << creation.get_balance() << endl;
    cout << endl;

    while (alive){
        cout << "===========================================================" << endl;
        cout << "MONTH: " << turn << endl;
        cout << "REVENUE FROM ANIMALS: $" << creation.revenue() << endl;
        cout << "PREVIOUS TOTAL BALANCE: $" << creation.get_balance() << endl;
        creation.set_balance(creation.get_balance() + creation.revenue());
        cout << "CURRENT TOTAL BALANCE: $" << creation.get_balance() << endl;
        cout << "===========================================================" << endl;
        creation.current();
        cout << "-----------------------------------------------------------" << endl;
        animals(creation);
        cout << "BALANCE AFTER PURCHASES: $" << creation.get_balance() << endl;
        cout << "-----------------------------------------------------------" << endl;
        food_type(sickness, creation, alive, turn);
        cout << "-----------------------------------------------------------" << endl;
        special(creation, sickness);
        cout << "-----------------------------------------------------------" << endl;
        creation.ager();

        quit(alive, turn, creation);
        turn++;
       
    }
}

void special(Zoo& creation, int &sickness) {
    int option = 0;
    option = rand() % (3 + sickness) + 1;

    if (option == 1) {
        cout << "No special events this turn! " << endl;
    }
    else if (option == 2) {
        if (creation.get_t_num() != 0 || creation.get_b_num() != 0 || creation.get_s_num() != 0) {
            cout << "There has been a birth at the Zoo!" << endl;
            creation.birth();
        }
        else {
            cout << "No special events this turn! " << endl;
        }
       
    }
    else if (option == 3) {
        if (creation.get_s_num() != 0) {
            cout << "There has been an boom in Zoo attendence!" << endl;
            creation.boom();
        }
        else {
            cout << "No special events this turn! " << endl;
        }
        
        
    }
    else {
        if (creation.get_t_num() != 0 || creation.get_b_num() != 0 || creation.get_s_num() != 0) {
            cout << "An animal is sick!" << endl;
            creation.sick();
        }
        else {
            cout << "No special events this turn! " << endl;
        } 
    }
}

void food_type(int& sickness, Zoo &creation, bool &alive, int turn) {
    int cheap = 0;
    int regular = 0;
    int premium = 0;

    creation.food_cost(cheap, regular, premium);
    cout << "Would you like to purchase cheap (1), regular (2), or premium (3) food?" << endl;
    cout << "Choosing cheap doubles the chance of sickness, and premium halves it" << endl;
    cout << "- Cheap: $" << cheap << endl;
    cout << "- Regular: $" << regular << endl;
    cout << "- Premium: $" << premium << endl;
    // make calls to determine the cost of the food

    bool valid = true;
    string input = "";
    while (valid) {
        cin >> input;
        if (input == "1") {
            cout << "Buying cheap food" << endl;
            valid = false;
            sickness = 4;
            creation.set_balance(creation.get_balance() - cheap);
        }
        else if (input == "2") {
            cout << "Buying regular food" << endl;
            valid = false;
            sickness = 2;
            creation.set_balance(creation.get_balance() - regular);
        }
        else if (input == "3") {
            cout << "Buying premium food" << endl;
            valid = false;
            sickness = 1;
            creation.set_balance(creation.get_balance() - premium);
        }
        else {
            cout << "Your input was invalid, please enter a 1-3 response for food" << endl;
        }
    }
    cout << endl;
    // determines if the food they purchased made them go bankrupt
    if (creation.get_balance() < 0) {
        alive = false;
        cout << "You spent all your money on food!" << endl;
    }
    else {
        cout << "BALANCE AFTER FEED: $" << creation.get_balance() << endl;
    }
}

void quit(bool& alive, int turn, Zoo &creation) {
    if (creation.get_balance() < 0) {
        alive = false;
        cout << "You have ran out of money! Thanks for playing." << endl;
        cout << "Months lasted: " << turn << endl;
    }
    else {
        string input = "";

        cout << "Would you like to play another round?" << endl;
        cout << "Type 'no' to end the game, or enter any other key to continue" << endl;
        cin >> input;

        if (input == "no") {
            cout << "Thanks for playing" << endl;
            alive = false;
        }
        else {
            alive = true;
            for (int i = 0; i < 7; i++) {
                cout << endl;
            }
        }
    }
}

void animals(Zoo &creation){
    // the reason this function is well over 20 lines is due to two reasons:
    // (1) I wanted to keep all of the "animal" functionality under one roof for readability; i.e determining how many animals a user wants to purchase
    // (2) 50% of the function is comprised of cout statements
    string input = "";
    bool valid = true;
    int numbers;
    int sickness = 2;

    cout << endl;
    cout << "Would you like to purchase an animal?" << endl;
    cout << "Enter a 'yes' or 'no' response" << endl;

    while (valid){
        cin >> input;
        // if response is invalid
        if (input != "yes" &&  input != "no"){
            cout << "Your response was invalid, please enter a 'yes' or 'no' response" << endl;
        // if they don't want to purchase an animal
        } else if (input == "no"){
            cout << "Proceeding to play this month without purchasing any animals" << endl;
            valid = false;
        // if they want to purchase an animal
        } else if (input == "yes"){
            cout << endl;
            cout << "What species would you like to purchase?" << endl;
            cout << "Warning, if your purchase exceeds the amount of money in your balance, you will lose the game" << endl;
            cout << "Choose between 'tiger' ($12,000), 'sealion' ($700), 'bear' ($5,000), or 'none ($0)" << endl;
            while (valid){
                cin >> input;
                // if response is invalid
                if (input != "tiger" &&  input != "sealion" && input != "bear" && input != "none"){
                    cout << "Your response was invalid, please enter a 'tiger', 'sealion', and 'bear' " << endl;
                // if they want to buy a tiger
                } else if (input == "tiger"){
                    cout << "Tigers are a good choice!" << endl;
                    cout << endl;
                    cout << "How many tigers would you like to buy?" << endl;
                    animal_numbers(numbers);
                    for (int i = 0; i < numbers; i++) {
                        creation.tiger_add();
                        creation.get_tiger()[creation.get_t_num() - 1].set_age(48);
                        creation.set_balance(creation.get_balance() - 12000);
                    }
                    valid = false;
                    // call to increase the numbers
                // if they want to buy a bear
                } else if (input == "bear"){
                    cout << "Bears are a good choice!" << endl;
                    cout << endl;
                    cout << "How many bears would you like to buy?" << endl;
                    animal_numbers(numbers);
                    valid = false;
                    for (int i = 0; i < numbers; i++) {
                        creation.bear_add();
                        creation.get_bear()[creation.get_b_num() - 1].set_age(48);
                        creation.set_balance(creation.get_balance() - 5000);
                    }
                    // call to increase the numbers
                // if they want to buy a sealion
                } else if (input == "sealion"){
                    cout << "Sealions are a good choice!" << endl;
                    cout << endl;
                    cout << "How many sealions would you like to buy?" << endl;
                    animal_numbers(numbers);
                    valid = false;
                    for (int i = 0; i < numbers; i++) {
                        creation.sealion_add();
                        creation.get_sealion()[creation.get_s_num() - 1].set_age(48);
                        creation.set_balance(creation.get_balance() - 700);
                    }
                    // call to increase the numbers
                // if they don't want to buy an animal
                } else if (input == "none"){
                    cout << "Proceeding to play this month without purchasing any animals" << endl;
                    valid = false;
                }
            }
        }
    }
    cout << endl;
}

void animal_numbers(int &numbers){
    string input = "";
    bool valid = true;

    cout << "Enter a number between 0-2" << endl;
    while (valid){  
        cin >> input;
        if (input != "0" && input != "1" && input != "2"){
            cout << "You have not inputed a number 0-2, please try again" << endl;
        } else{
            numbers = atoi(input.c_str());
            valid = false;
        }
    }
}

