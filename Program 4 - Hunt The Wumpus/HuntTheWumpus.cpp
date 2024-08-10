#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include "HuntTheWumpus.hpp"
#include "Room.hpp"

using namespace std;

void start(int argc, char** argv){
    string mode;
    int size;
    command_line_check(argc, argv, mode, size);
    story_line(mode);
    game(mode, size);
}

void game(string &mode, int &size){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function is the framework that contains all of the necessary calls to make the game run; it's mostly made of variable initializations, while loops, and if-statements
    bool alive = true;
    bool another = true;
    bool gold = false;
    bool wumpus = true;
    // player row & column
    int p_row = 0;
    int p_col = 0;
    // wumpus row & column
    int w_row = 0;
    int w_col = 0;
    int turn = 1;
    int shots = 3;

    while (another){
        vector<vector<Room>> cave(size, vector<Room> (size));
        initializer(cave, size, p_row, p_col, w_row, w_col);

        while (alive){
            print(cave, size, turn, mode, shots);
            percepts(cave, size, p_row, p_col);
            if (mode != "AI"){
                if (shots != 0 && wumpus == true){
                    decision(cave, size, p_row, p_col, shots, wumpus);     
                } else{
                    move(cave, size, p_row, p_col);
                }   
            } else{
                ai(cave, size, p_row, p_col, shots, wumpus);
            }
            action(cave, size, p_row, p_col, shots, alive, gold, turn, wumpus, w_row, w_col);
            turn++;
        }

        alive = true;
        again(another, size);
    }
}

void ai(vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &wumpus){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function contains the framework of the AI, and in fact uses the move_action / shoot_action modularizations used by the player
    // splitting this function any further would increase the complexity of using the AI, because it would be harder to read
    int misses = 1;
    bool valid = true;
    int decision = rand() % 2;
    int direction;
    string s_direction;

    while(valid){
        direction = (rand() % 4) + 1;
        if (direction == 1 && (row - 1) < 0){
            valid = true;
        } else if(direction == 2 && (row + 1) == size){
            valid = true;
        } else if(direction == 3 && (col - 1) < 0){
            valid = true;
        } else if(direction == 4 && (col + 1) == size){
            valid = true;
        } else{
            if (direction == 1){
                s_direction = "W";
            } else if (direction == 2){
                s_direction = "S";
            } else if (direction == 3){
                s_direction = "A";
            } else if (direction == 4){
                s_direction = "D";
            }
            valid = false;
        }
    }

    // randomly moving
    if (decision == 1 || shots == 0){
        cout << "AI Moving at: " << s_direction << endl;
        move_action(cave, s_direction, row, col);
    } 
    // randomly shooting
    else{
        shots--;
        cout << "AI Shooting at: " << s_direction << endl;
        
        shoot_action(cave, s_direction, row, col, wumpus, misses, size);
        if (misses == 1){
            shoot_miss(cave, size, row, col);
        }
    }
}

void again(bool &another, int &size){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function is mostly "cout"  and if statements, so I kept it in one function
    string input = "";
    bool valid = true;

    cout << "Would you like to play with a different board size? ('Y' - yes, 'N' - no)" << endl;

    while (valid){
        cin >> input;
        if (input != "Y" && input != "N"){
            cout << "You have entered an incorrect input, please input a 'Y' - yes, 'N' - no answer" << endl;
        } else{
            valid = false;
        }
    }
    valid = true;

    if (input == "N"){
        cout << "Thank you for playing Hunt the Wumpus!" << endl;
        another = false; 
    } else{
        cout << "Please enter a new board size larger than 3" << endl;
        int non_ints = 0;
        while (valid){
            cin >> input;
            for (int i = 0; i < input.size(); i++){
                if (input[i] < 48 || input[i] > 57){
                    non_ints++;
                }
            }
            if (non_ints != 0){
                cout << "You have entered an invalid cave size" << endl; 
                cout << "Please enter a cave size larger than 3: ";
                non_ints = 0;
                
            } else{
                size = atoi(input.c_str());
                if (size < 4){
                    cout << "You have entered an invalid cave size" << endl; 
                    cout << "Please enter a cave size larger than 3: ";
                } else{
                    valid = false;
                }
            }
        }
    }
}

void action(vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &alive, bool &gold, int &turn, bool &wumpus, int &w_row, int&w_col){
    int death = 0;

    if (cave[row][col].get_contains() == true){
        cave[row][col].get_event()->action();
        if (cave[row][col].get_type() == "W" || cave[row][col].get_type() == "P" ){
            death++;
        }
        if (cave[row][col].get_type() == "G"){
            gold = true;
        }
        if (cave[row][col].get_type() == "S" && gold == true){
            cout << "Congratulations, you have survived the Wumpus and escaped with the gold!" << endl;
            death++;
        }
        if (cave[row][col].get_type() == "B"){
            cave[row][col].set_user(false);
            row = rand() % size;
            col = rand() % size;
            cave[row][col].set_user(true);
            action(cave, size, row, col, shots, alive, gold, turn, wumpus, w_row, w_col);
        }
    }

    if (death != 0){
        death++;
        cout << "Thank you for playing Hunt the Wumpus!" << endl;
        cout << endl;
        reset(cave, size, row, col, shots, turn, alive, gold, wumpus, w_row, w_col);
    }
}

void reset(vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, int &turn, bool &alive, bool &gold, bool &wumpus, int &w_row, int &w_col){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // the reason this function is so large is because it contains all of the necessary statements to reset the board
    // although it would have been possible to split the no-reset, reset, and player-input portions into different sections it would make reading the code harder

    string input = "";
    bool valid = true;

    cout << endl;
    cout << "Would you like to play again with the same board? ('Y' - yes or 'N' - no)" << endl;
    while (valid){
        cin >> input;
        if (input != "Y" && input != "N"){
            cout << "Your response was invalid, please input a ('Y' - yes or 'N' - no) response" << endl;
        } else if (input == "Y"){
            cout << "Resetting the board" << endl;
            gold = false;
            turn = 0;
            shots = 3;
            wumpus = true;

            cave[row][col].set_user(false);
            
            for (int i = 0; i < size; i++){
                for (int j = 0; j < size; j++){
                    // finding the starting room
                    if (cave[i][j].get_type() == "S"){
                        row = i;
                        col = j;
                    }
                    
                    // removing the current Wumpus location
                    if (cave[i][j].get_type() == "W"){
                        cave[i][j].set_contains(false);
                        cave[i][j].set_type(" ");
                        delete cave[i][j].get_event();
                        cave[i][j].set_event(NULL);
                    }
                }
            }

            // setting the user back at the original starting room
            cave[row][col].set_user(true);

            // setting the wumpus back at the original wumpus room
            Wumpus *w3 = new Wumpus;
            cave[w_row][w_col].set_type("W");
            cave[w_row][w_col].set_contains(true);
            cave[w_row][w_col].set_event(w3);

            valid = false;
        } else if (input == "N"){
            deleter(cave, size);
            gold = false;
            turn = 0;
            shots = 3;
            wumpus = true;
            alive = false;
            valid = false;
        }
    }
}

void decision(vector<vector<Room>> &cave, int &size, int &row, int &col, int &shots, bool &wumpus){
    cout << "Would you like to move or shoot?" << endl;

    bool valid = true;
    string input = "";
    while (valid){
        cout << "Enter (1) to move and (2) to shoot:" << endl;
        cin >> input;

        if (input != "1" && input != "2"){
            cout << "Your decision was invalid, please try again." << endl;
        } else if (input == "1"){
            move(cave, size, row, col);
            valid = false;
        } else{
            shots--;
            shoot(cave, size, row, col, wumpus);
            valid = false;
        }
    }

}

void percepts(vector<vector<Room>> &cave, int &size, int &row, int &col){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function has if-statements that are different enough to the point where it doesn't make it easier to split into seperate functions

    cout << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << "PERCEPTS:" << endl;
    int special = 0;


    if (row - 1 >= 0){
        if (cave[row-1][col].get_contains() == true){
            cout << cave[row-1][col].get_event()->get_percept() << endl;
            special++;
        }
    }

    if (row + 1 < size){
        if (cave[row+1][col].get_contains() == true){
            cout << cave[row+1][col].get_event()->get_percept() << endl;
            special++;
        }
    }

    if (col - 1 >= 0){
        if (cave[row][col-1].get_contains() == true){
            cout << cave[row][col-1].get_event()->get_percept() << endl;
            special++;
        }
    }

    if (col + 1 < size){
        if (cave[row][col+1].get_contains() == true){
            cout << cave[row][col+1].get_event()->get_percept() << endl;
            special++;
        }
    }

    if (special == 0){
        cout << "No special rooms nearby." << endl;
    }

    cout << "==============================================================" << endl;


}

void shoot(vector<vector<Room>> &cave, int &size, int &row, int &col, bool &wumpus){
    bool valid = true;
    string input = "";
    int misses = 1;

    cout << endl;
    while (valid){
        cout << "Enter a direction to shoot in (W - up, A - left, S - down, or D - right)" << endl;
        cin >> input;

        if (input != "W" && input != "A" && input != "S" && input != "D"){
            cout << "You have entered an invalid shooting input" << endl;
        } else{
            if (input == "W" && (row - 1) < 0){
                cout << "You are at the top of the cave-wall, shoot in a different direction" << endl;
            } else if(input == "S" && (row + 1) == size){
                cout << "You are at the bottom of the cave-wall, shoot in a different direction" << endl;
            } else if(input == "A" && (col - 1) < 0){
                cout << "You are at the left-most of the cave-wall, shoot in a different direction" << endl;
            } else if(input == "D" && (col + 1) == size){
                cout << "You are at the right-most of the cave-wall, shoot in a different direction" << endl;
            } 
            // kills the wumpus if it is in the direction of the arrow
            else{
                shoot_action(cave, input, row, col, wumpus, misses, size);
                valid = false;
            }
        }
    }

    // changes the location of the Wumpus if the shot misses
    if (misses == 1){
        shoot_miss(cave, size, row, col);
    }
}

void shoot_action(vector<vector<Room>> &cave, string &direction, int &row, int &col, bool &wumpus, int &misses, int &size){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // This function has similar for-loops within an if-statement that cannot be seperated; each of the for-loops is different to the point where it would be very hard to seperate into different functions
    // To reduce the size of the function, I did include a final if-statement which has the code to perform within each of the if-statements
    
    // temporary row & column
    int t_row = -1;
    int t_col = -1;

    if (direction == "W"){
        for (int i = row; i >= 0; i--){
            if (cave[i][col].get_contains() == true){
                if (cave[i][col].get_type() == "W"){
                    t_row = i;
                    t_col = col;
                } 
            }
        }
    } else if (direction == "S"){
        for (int i = row; i < size; i++){
            if (cave[i][col].get_contains() == true){
                if (cave[i][col].get_type() == "W"){
                    t_row = i;
                    t_col = col;
                }
            }
        }
    } else if (direction == "A"){
        for (int i = col; i >= 0; i--){
            if (cave[row][i].get_contains() == true){
                if (cave[row][i].get_type() == "W"){
                    t_row = row;
                    t_col = i;
                }
            }
        }
    } else{
        for (int i = col; i < size; i++){
            if (cave[row][i].get_contains() == true){
                if (cave[row][i].get_type() == "W"){
                    t_row = row;
                    t_col = i;
                }
            }
        }
    }

    if (t_row != -1){
        cout << "You have killed the Wumpus!" << endl;
        delete cave[t_row][t_col].get_event();
        cave[t_row][t_col].set_event(NULL);
        cave[t_row][t_col].set_contains(false);
        cave[t_row][t_col].set_type(" ");
        misses = 0;
        wumpus = false;
    }
}

void shoot_miss(vector<vector<Room>> &cave, int &size, int &row, int &col){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function contains all of the functionality for what happens when the Wumpus is disturbed, so it makes most sense to keep it in one function (it would only add length to seperate this)
    cout << "Your shot missed!" << endl;

    int move = 0;
    move = rand() % 4;
    if (move == 1){
        cout << "The Wumpus has been disturbed, but decides to stay where it is..." << endl;
    } else{
        cout << "The Wumpus has been disturbed, and moves to a different location to lumber..." << endl;

        int w_row = 0;
        int w_col = 0;
        bool valid = true;

        for (int i = 0; i < size; i++){
            for (int j = 0; j < size; j++){
                if (cave[i][j].get_type() == "W"){
                    delete cave[i][j].get_event();
                    cave[i][j].set_event(NULL);
                    cave[i][j].set_contains(false);
                    cave[i][j].set_type(" ");
                }
            }
        }
        
        // makes sure that the Wumpus isn't on top of the player for the new location
        while (valid){
            random(cave, size, w_row, w_col);
            cout << "p" << endl;
            
            if (w_row != row && w_col != col){
                valid = false;
            } else{
                cave[w_row][w_col].set_contains(false);
            }
            
           //valid = false;
        }

        Wumpus *w2 = new Wumpus;
        cave[w_row][w_col].set_event(w2);
        cave[w_row][w_col].set_type("W");
        cave[w_row][w_col].set_contains(true);   
    }
}

void move(vector<vector<Room>> &cave, int &size, int &row, int &col){
    bool valid = true;
    string input = "";

    cout << endl;
    while (valid){
        cout << "Enter a direction to move in (W - up, A - left, S - down, or D - right)" << endl;
        cin >> input;

        if (input != "W" && input != "A" && input != "S" && input != "D"){
            cout << "You have entered an invalid movement input" << endl;
        } else{
            if (input == "W" && (row - 1) < 0){
                cout << "You are at the top of the cave-wall, enter another input" << endl;
            } else if(input == "S" && (row + 1) == size){
                cout << "You are at the bottom of the cave-wall, enter another input" << endl;
            } else if(input == "A" && (col - 1) < 0){
                cout << "You are at the left-most of the cave-wall, enter another input" << endl;
            } else if(input == "D" && (col + 1) == size){
                cout << "You are at the right-most of the cave-wall, enter another input" << endl;
            } else{
                move_action(cave, input, row, col);
                valid = false;
            }
        }
    }
}

void move_action(vector<vector<Room>> &cave, string &direction, int &row, int &col){
    if (direction == "W"){
        cave[row][col].set_user(false);
        row--;
        cave[row][col].set_user(true);
    } else if (direction == "S"){
        cave[row][col].set_user(false);
        row++;
        cave[row][col].set_user(true);
    } else if (direction == "A"){
        cave[row][col].set_user(false);
        col--;
        cave[row][col].set_user(true);
    } else{
        cave[row][col].set_user(false);
        col++;
        cave[row][col].set_user(true);
    }
}

void print(vector<vector<Room>> &cave, int &size, int &turn, string &mode, int &shots){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function prints the board each turn, and has important for-loop statements that would be more complicated to separate into different functions
    // printing the header for each turn
    cout << endl;
    cout << "==============================================================" << endl;
    cout << "MODE: " << mode << endl;
    cout << "TURN: " << turn << endl;
    cout << "SHOTS LEFT: " << shots << endl;
    cout << "--------------------------------------------------------------" << endl;
    cout << endl;

    int row = 0;
    int col = 0;

    // printing the game-board for each turn
    cout << "+";
    for (int i = 0; i < size; i++){cout << "---+";}
    cout << endl;

    for (int i = 0; i < size; i++){
        cout << "|";
        for (int i = 0; i < size; i++){cout << "   |";}
        cout << endl;
        
        cout << "|";
        for (int i = 0; i < size; i++){
            if (cave[row][col].get_user() == false){
                cout << "   |";
            } else{
                cout << " * |";
            }
            col++;
        }
        col = 0;
        cout << endl;

        cout << "|";
        for (int i = 0; i < size; i++){
            cout << " ";
            if (mode == "debug" || mode == "AI"){
                cout << cave[row][col].get_type();
            } else{
                cout << " ";
            }
            cout << " |";
            col++;
        }
        col = 0;
        cout << endl;

        cout << "+";
        for (int i = 0; i < size; i++){cout << "---+";}
        cout << endl;

        row++;
    }
}

void initializer(vector<vector<Room>> &cave, int &size, int &row, int &col, int &w_row, int &w_col){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function is contains all of the object creation elements; it would be more complex to seperate this out into
    // separate functions

    // assigning various events to random rooms
    Bats *b1 = new Bats;
    random(cave, size, row, col);
    cave[row][col].set_event(b1);
    cave[row][col].set_type("B");
 
    Bats *b2 = new Bats;
    random(cave, size, row, col);
    cave[row][col].set_event(b2);
    cave[row][col].set_type("B");

    Pit *p1 = new Pit;
    random(cave, size, row, col);
    cave[row][col].set_event(p1);
    cave[row][col].set_type("P");

    Pit *p2 = new Pit;
    random(cave, size, row, col);
    cave[row][col].set_event(p2);
    cave[row][col].set_type("P");

    Gold *g1 = new Gold;
    random(cave, size, row, col);
    cave[row][col].set_event(g1);
    cave[row][col].set_type("G");

    Wumpus *w1 = new Wumpus;
    random(cave, size, w_row, w_col);
    cave[w_row][w_col].set_event(w1);
    cave[w_row][w_col].set_type("W");

    Start *s1 = new Start;
    random(cave, size, row, col);
    cave[row][col].set_event(s1);
    cave[row][col].set_user(true);
    cave[row][col].set_type("S");
}

void random(vector<vector<Room>> &cave, int &size, int &row, int &col){
    bool valid = true;

    while (valid){
        row = rand() % size;
        col = rand() % size;

        if (cave[row][col].get_contains() == false){
            cave[row][col].set_contains(true);
            valid = false;
        }
    }

}

void command_line_check(int argc, char** argv, string &mode, int &size){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function is contains both the error-checking and reprompting for the user's incorrrect  command-line inputs
    // I kept it all in one function in order to reduce complexity of finding all the parts related to command-line
    string potential;
    
    if (argc != 3)
    {
        cout << "You have entered the wrong number of inputs" << endl;
        cout << "Please enter 'debug', 'regular', or 'AI' for the game mode: ";
        cin >> mode;
        cout << "Please enter a cave size larger than 3: ";
        cin >> potential;
        cout << endl;
    } else{
        mode = argv[2];
        potential = argv[1];

    }

    bool valid = true;
    while (valid){
        if (mode != "debug" && mode != "AI" && mode != "regular"){
            cout << "You have entered an invalid game-type mode." << endl;
            cout << "Please enter 'debug', 'regular', or 'AI' ";
            cin >> mode;
        } else{
            valid = false;
            cout << endl;
        }
    }

    valid = true;
    int non_ints = 0;
    while (valid){
        for (int i = 0; i < potential.size(); i++){
            if (potential[i] < 48 || potential[i] > 57){
                non_ints++;
            }
        }

        if (non_ints != 0){
            cout << "You have entered an invalid cave size" << endl; 
            cout << "Please enter a cave size larger than 3: ";
            cin >> potential;
            non_ints = 0;
            
        } else{
            size = atoi(potential.c_str());
            if (size < 4){
                cout << "You have entered an invalid cave size" << endl; 
                cout << "Please enter a cave size larger than 3: ";
                cin >> potential;
            } else{
                valid = false;
            }
        }
    }

    cout << endl;
}

void story_line(string& mode){
    // JUSTIFICATION FOR FUNCTION LENGTH:
    // this function is mostly "cout" statements, so I kept it in one function
    cout << "Welcome to 'Hunt the Wumpus'! You have entered " << mode << " mode." << endl;
    cout << "Would you like to understand how to play the game? (Enter 'Y' or 'N') " << endl;
    string input;
    cin >> input;
    cout << endl;

    bool valid = true;

    while (valid){
        if (input != "Y" && input != "N"){
            cout << "You have inputted an incorrect response, please enter a 'Y' or 'N'. " << endl;
            cin >> input;
        } else{
            valid = false;
        }

    }

    if (input == "Y"){
        cout << "Hunt the Wumpus is a game set inside the cave of the Wumpus, a scary, gold-hoarding monster who likes to eat people who disturb its sleep. " << endl;
        cout << "The player's goal is to guide an adventurer to kill the Wumpus, find its hidden gold, and escape alive.  " << endl;
        cout << "The Wumpus lives in a large cave of rooms arranged in a grid, where each room has four tunnels leading to the rooms to the north, east, south, and west.  " << endl;
        cout << "The adventurer starts the game in a random empty room in the Wumpus’ cave.  " << endl;
        cout << "Her starting position is also the location of the escape rope that she must use to escape after she's completed her task.  " << endl;
        cout << "Each room may be empty, or it may contain one (and only one) of four 'events' (all described below): two kinds of dangerous hazards, the terrifying Wumpus, and the gold treasure.  " << endl;
        cout << "When the adventurer is in a room that’s adjacent to one containing an 'event', the player will receive a percept (a message) to inform them about the event the adventurer is close to.  " << endl;
        cout << "The player wins the game if they can safely guide the adventurer through the cave to kill the Wumpus, pick up the gold, and make it back to the escape rope unharmed!  " << endl;
        cout <<  "Note: If you enter the cave, retrieve the gold, and escape without killing the Wumpus, that's okay too. The player still wins." << endl;
    }

    cout << endl;
    cout << "PROCEEDING WITH GAME" << endl;
    cout << endl;
}

void deleter(vector<vector<Room>> &cave, int &size){
    for (int i = 0; i < size; i++){
        for (int j = 0; j < size; j++){
            if (cave[i][j].get_contains() == true){
                delete cave[i][j].get_event();
                cave[i][j].set_event(NULL);
                cave[i][j].set_type(" ");
                cave[i][j].set_contains(false);
            }
        }
    }
}

