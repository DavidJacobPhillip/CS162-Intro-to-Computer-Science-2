#include <iostream>
#include <cstdlib>
#include <string>
#include "LinkedList.hpp"
#include "Node.hpp"
#include "Implementation.hpp"

using namespace std;

void start(){
    // creating the list types
    LinkedList<unsigned int> u;
    LinkedList<signed int> s;
    int type = 0;
    int length = 0;

    list(type);
    cout << "==============================================================" << endl;
    if (type == 1){
        unsigned_list(u, length);
        u.primes();
        u.sorting();
    } else{
        signed_list(s, length);
        s.primes();
        s.sorting();
    }

    u.clear();
    s.clear();
}

void unsigned_list(LinkedList<unsigned int>& u, int &length){
    bool valid = true;
    unsigned int u_number = 0;
    signed int s_number = 0;
    int place = 0;
    string input = "";

    cout << endl;
    
    while (valid){
        cout << "Would you like to input a number into the list?" << endl;
        cout << "Enter 'Y' or 'N' for yes and no respectively" << endl;
        cin >> input;
        if (input != "Y" && input != "N"){
            cout << "Error, please enter a 'Y' or 'N' input" << endl;
        } else if (input == "Y"){
            numbers(u_number, s_number, place, length, 1);
            if (place == 0){
                cout << "Current List Length: " << u.push_front(u_number) << endl;
            } else if (place == length){
                cout << "Current List Length: " << u.push_back(u_number) << endl;
            } else{
                cout << "Current List Length: " << u.insert(u_number, place) << endl;
            }
            cout << endl;
            length++;
        } else if (input == "N"){
            valid = false;
        }
    }
    cout << endl;
    cout << "Printing unsorted unsigned list: " << endl;
    u.print();
    cout << endl;
    cout << endl;
    cout << "==============================================================" << endl;
}

void signed_list(LinkedList<signed int>& s, int &length){
    bool valid = true;
    unsigned int u_number = 0;
    signed int s_number = 0;
    int place = 0;
    string input = "";

    cout << endl;
    
    while (valid){
        cout << "Would you like to input a number into the list?" << endl;
        cout << "Enter 'Y' or 'N' for yes and no respectively" << endl;
        cin >> input;
        if (input != "Y" && input != "N"){
            cout << "Error, please enter a 'Y' or 'N' input" << endl;
        } else if (input == "Y"){
            numbers(u_number, s_number, place, length, 1);
            if (place == 0){
                cout << "Current List Length: " << s.push_front(s_number) << endl;
            } else if (place == length){
                cout << "Current List Length: " << s.push_back(s_number) << endl;
            } else{
                cout << "Current List Length: " << s.insert(s_number, place) << endl;
            }
            cout << endl;
            length++;
        } else if (input == "N"){
            valid = false;
        }
    }
    cout << endl;
    cout << "Printing unsorted signed list: " << endl;
    s.print();
    cout << endl;
    cout << endl;
    cout << "==============================================================" << endl;
}

void numbers(unsigned int &u_number, signed int &s_number, int &place, int &length, int type){
    // Caution: this function does NOT do any error handling for non-integers typed
    // when the user is prompted to answer; there is error handling for invalid
    // integer inputs though

    string input = "";
    bool valid = true;

    cout << "What number do you want to input?" << endl;
    while (valid){
        if (type == 1){
            cin >> u_number;
        } else{
            cin >> s_number;
        }
        
        if (type == 1 && u_number < 0){
            cout << "Error, please input a positive number" << endl;
        } else{
            valid  = false;
        }
    }

    valid = true;
    cout << endl;
    cout << "What place do you want to input the number at?" << endl;
    cout << "Input a place number between 0 and " << length << endl;
    while (valid){
        cin >>  place;
        if (place < 0 || place > length){
            cout << "Error, input a number in the range state above." << endl;
        } else{
            valid = false;
        }
    }
}

void list(int &type){
    bool valid = true;
    string input = "";

    cout << endl;
    cout << "Would you like to use an unsigned or signed linked list?" << endl;
    cout << "Enter '1' or '2' for the list types respectively" << endl;
    while (valid){
        cin >> input;
        if (input != "1" && input != "2"){
            cout << "Error, please enter a '1' or '2' input" << endl;
        } else if (input == "1"){
            type = 1;
            cout << "Creating an unsigned linked list!" << endl;
            valid = false;
        } else if (input == "2"){
            type = 2;
            cout << "Creating an signed linked list!" << endl;
            valid = false;
        }
    }
    cout << endl;
}

void repeat(bool &again){
    bool valid = true;
    string input = "";

    cout << endl;
    cout << "Would you like to run again?" << endl;
    cout << "Enter 'Y' or 'N' for yes and no respectively" << endl;
    while (valid){
        cin >> input;
        if (input != "Y" && input != "N"){
            cout << "Error, please enter a 'Y' or 'N' input" << endl;
        } else if (input == "Y"){
            again = true;
            cout << "Restarting the program..." << endl;
            valid = false;
        } else if (input == "N"){
            again = false;
            cout << "Thank you for running the Linked List Implementation!" << endl;
            valid = false;
        }
    }
    cout << endl;
}
