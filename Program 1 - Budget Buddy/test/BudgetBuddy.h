// Header/Interface File Code: BudgetBuddy.h
//CONTAINS ALL FUNCTION PROTOTYPES & STRUCTS
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>

using namespace std;

// this struct holds all of the user account informations
struct user{
   string name;
   int id;
   string password;
};

// this struct holds all of the general information about a user's budget
struct budget{
   int id;
   float balance;
   int num_transactions;
   struct transaction *purchases;
};

// this struct holds all of the transactions history for each user
struct transaction{
   float amount;
   string date;
   string category;
   string description;
};

/******************************************************************* 
 ** Function: command_line_check();
 ** Description: This function checks if the correct number of command line arguments are present, and if they are of the correct file type
 ** Parameters: int argc, char **argv, string &users, string &budgets, fstream &users_file, fstream &budgets_file
 ** Pre-conditions: It takes in the number of arguments, and the files inputed
 ** Post-conditions: Determines if there are the correct number of argc inputs + if the files are correct
 *******************************************************************/
void command_line_check (int, char **, string &, string &, fstream &, fstream &);

/******************************************************************* 
 ** Function: file_check();
 ** Description: Checks if the argc inputs are indeed files that can be opened
 ** Parameters: string &file, fstream &file_type
 ** Pre-conditions: Takes in the string inputs for the potential file names
 ** Post-conditions: Determines if the files can be opened
 *******************************************************************/
void file_check (string &, fstream &);

/******************************************************************* 
 ** Function: user_login();
 ** Description: fstream &users_file, user *&accounts, int &current_user, int &total_accounts
 ** Parameters: The function that contains all of the function calls to allow the user to login
 ** Pre-conditions: The user_file, the accounts structure, the current user, and the total number of accounts
 ** Post-conditions: Allows the user to successfully login or potentially exit the program
 *******************************************************************/
void user_login (fstream &, user *&, int &, int &);

/******************************************************************* 
 ** Function: number_of_accounts();
 ** Description: Determines the number of accounts present
 ** Parameters: fstream &users_file
 ** Pre-conditions: takes in the first line from the users_file containing the number of accounts
 ** Post-conditions: returns the number of accounts present
 *******************************************************************/
int number_of_accounts(fstream &);

/******************************************************************* 
 ** Function: *accounts_database();
 ** Description: Creates the account array based on how many "accounts" there are
 ** Parameters: int accounts
 ** Pre-conditions: Takes in the number of accounts
 ** Post-conditions: Returns an array of "accounts" size
 *******************************************************************/
user *accounts_database(int);

/******************************************************************* 
 ** Function: account_information();
 ** Description: Fills the user struct with the account information
 ** Parameters: user * accounts, fstream &users_file, int total_accounts
 ** Pre-conditions: Takes in an unfilled accounts array
 ** Post-conditions: Fills the accounts array with the information in the users_file
 *******************************************************************/
void account_information(user *, fstream &, int);

/******************************************************************* 
 ** Function: contains_letters();
 ** Description: Determines if the user-name entered contains any letters
 ** Parameters: string &letters, int &numbers
 ** Pre-conditions: The user-inputted user-name
 ** Post-conditions: Returns a user-name with no letters (re-prompts user for another username if necessary)
 *******************************************************************/
void contains_letters (string &, int &);

/******************************************************************* 
 ** Function: correct_account();
 ** Description: Allows the user to log-in using their password/username
 ** Parameters: int user_name, string password, int &attempts, int total_accounts, user *accounts
 ** Pre-conditions: Takes in the user-name, password and compares it to the information given
 ** Post-conditions: Updates the "attempts" column based on the user's tries to login
 *******************************************************************/
void correct_account(int, string, int &, int, user *);

/******************************************************************* 
 ** Function: welcome_message();
 ** Description: Prints out a welcome message to the logged-in user
 ** Parameters: int total_accounts, int current_user, user *accounts
 ** Pre-conditions: Takes in the number of accounts, and the current-account
 ** Post-conditions: Prints a welcome message based on who the current_user is
 *******************************************************************/
void welcome_message(int, int, user *);

/******************************************************************* 
 ** Function: database_initializer();
 ** Description: The function that contains all of the function calls to fill the finances/purchases array with information
 ** Parameters: fstream &budgets_file, budget *&finances, int total_accounts, int &current_transactions, int current_user
 ** Pre-conditions: The finances pointer and the budgets_file 
 ** Post-conditions: Creates / fills a finances array and purchases array
 *******************************************************************/
void database_initializer(fstream &, budget *&, int, int &, int);

/******************************************************************* 
 ** Function: *create_budgets();
 ** Description: Creates the finances array from the budget struct
 ** Parameters: int accounts
 ** Pre-conditions: takes in the number of "accounts" 
 ** Post-conditions: returns an array of size "accounts"
 *******************************************************************/
budget *create_budgets(int);

/******************************************************************* 
 ** Function: *create_transactions();
 ** Description: Creates the purchases array from the transactions struct
 ** Parameters: int actions
 ** Pre-conditions: takes in the number of "purchases" made
 ** Post-conditions: returns an array of size "purchases"
 *******************************************************************/
transaction *create_transactions(int);

/******************************************************************* 
 ** Function: get_budget_data();
 ** Description: Gets the transaction data from the budgets_file to fill the finances array
 ** Parameters: budget *finances, int total_accounts, fstream &budgets_file, int &current_transactions, int current_user
 ** Pre-conditions: Takes in an empty finances array
 ** Post-conditions: Fills the finances array with the information from the budgets_file
 *******************************************************************/
void get_budget_data(budget*, int, fstream &, int &, int);

/******************************************************************* 
 ** Function: get_transaction_data();
 ** Description: Gets the transaction data from the budgets_file to fill the purchases array
 ** Parameters: transaction *purchases, int num_transactions, fstream &budgets_file
 ** Pre-conditions: Takes in an empty purchases array
 ** Post-conditions: Fills the purchases array with the information from the budgets_file
 *******************************************************************/
void get_transaction_data(transaction *, int, fstream &);

/******************************************************************* 
 ** Function: unsorted_data();
 ** Description: Prints out the details about the finances array (excluding the purchases information)
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: The finances array
 ** Post-conditions: prints out the user id, current account balance, and number of transactions to the console
 *******************************************************************/
void unsorted_data(int, int, budget *, int);

/******************************************************************* 
 ** Function: sorted_data();
 ** Description: Contains all of the function calls required to sort the data
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: The unsorted purchases array
 ** Post-conditions: The sorted purchases array, based on user choice
 *******************************************************************/
void sorted_data(int, int, budget *, int);

/******************************************************************* 
 ** Function: category_chooser();
 ** Description: Determines the specific category that the user would like to sort the purchases data by
 ** Parameters: int &category
 ** Pre-conditions: Takes in the category variable, with no specification
 ** Post-conditions: Returns the category variable modified with the user's choice
 *******************************************************************/
void category_chooser(int &);

/******************************************************************* 
 ** Function: one_unsorted();
 ** Description: Prints out an unsorted array
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: Takes in an unordered purchases array
 ** Post-conditions: Prints out an unordered purchases array
 *******************************************************************/
void one_unsorted(int, int, budget *, int);

/******************************************************************* 
 ** Function: two_amount();
 ** Description: Orders the transaction history based on amount (highest to lowest)
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: An unordered purchases array
 ** Post-conditions: An ordered purchases array based on amount
 *******************************************************************/
void two_amount(int, int, budget *, int);

/******************************************************************* 
 ** Function: three_category();
 ** Description: Orders the transaction history based on category (housing, food, entertainment, personal-care, misc)
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: An unordered purchases array
 ** Post-conditions: An ordered purchases array based on category
 *******************************************************************/
void three_category(int, int, budget *, int);

/******************************************************************* 
 ** Function: four_date();
 ** Description: Orders the transaction history based on date (newest to oldest)
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: An unordered purchases array
 ** Post-conditions: An ordered purchases array based on date
 *******************************************************************/
void four_date(int, int, budget *, int);

/******************************************************************* 
 ** Function: filing_data();
 ** Description: Takes in a user-inputted file name to input the transaction history into
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: The finances/ purchase array
 ** Post-conditions: The data of the aforementioned arrays is printed into the user-specified file
 *******************************************************************/
void filing_data(int, int, budget *, int);

/******************************************************************* 
 ** Function: display_data();
 ** Description: Displays the data in the transactions array for the current user
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transaction
 ** Pre-conditions: The finances and subsequent purchases array are taken in
 ** Post-conditions: The transaction history is printed to the console
 *******************************************************************/
void display_data(int, int, budget *, int);

/******************************************************************* 
 ** Function: swap();
 ** Description: This function swaps the two array elements being compared
 ** Parameters: budget *finances, int j, int t
 ** Pre-conditions: The finances array with the two compared elements un-swapped
 ** Post-conditions: The finances array with the two compared elements swapped
 *******************************************************************/
void swap(budget *finances, int j, int t);

/******************************************************************* 
 ** Function: date_reverser_forward();
 ** Description: This reverses the date order to year/month/day
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: The finances array with the date strings in order
 ** Post-conditions: The finances array with the date strings in the reversed order
 *******************************************************************/
void date_reverser_forward(int, int, budget *, int);

/******************************************************************* 
 ** Function: date_reverser_back();
 ** Description: This reverses the date order back to month/day/year
 ** Parameters: int total_accounts, int current_user, budget *finances, int current_transactions
 ** Pre-conditions: The finances array with the reversed date strings
 ** Post-conditions: The finances array with the date strings back in order
 *******************************************************************/
void date_reverser_back(int, int, budget *, int);

/******************************************************************* 
 ** Function: delete_user_database();
 ** Description: deletes the users struct array called "accounts"
 ** Parameters: user *&accounts
 ** Pre-conditions: It takes in the accounts array
 ** Post-conditions: it deletes the accounts array and sets the pointer to null
 *******************************************************************/
void delete_user_database(user *&);

/******************************************************************* 
 ** Function: delete_transaction_database();
 ** Description: deletes the transaction struct array called "purchases"
 ** Parameters: transaction *&purchases
 ** Pre-conditions: it takes in the purchases array
 ** Post-conditions: it deletes the purchases array and sets the pointer to null
 *******************************************************************/
void delete_transaction_database(transaction *&);

/******************************************************************* 
 ** Function: delete_budget_database();
 ** Description: deletes the budget struct array called "finances"
 ** Parameters: budget *&finances, int total_accounts
 ** Pre-conditions: it takes in the finances array and the total number of accounts
 ** Post-conditions: it deletes the finances array and sets the pointer to null
 *******************************************************************/
void delete_budget_database(budget *&, int);

