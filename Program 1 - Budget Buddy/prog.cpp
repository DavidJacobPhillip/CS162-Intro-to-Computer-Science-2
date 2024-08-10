/**********************************************************
 ** Program: BudgetBuddy.cpp
 ** Author: Santosh Ramesh
 ** Date: 1-13-20
 ** Description: This function allows a user to log-into their account and sort their purchases/transaction history based on category, amount, and date. 
The data for the user-login functionality and the transactions are prompted through text-files
 ** Inputs: The user file, the budget file, the username/password of the user, the category they want to sort by, and the file name for the output information
 ** Output: The sorted file information, that is also outputted into a separate file
 **********************************************************/


#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./BudgetBuddy.h"

using namespace std;

int main(int argc, char** argv){
   string users;
   string budgets;
   int current_user;
   int total_accounts;
   int current_transactions;

   fstream users_file;
   fstream budgets_file;

   command_line_check(argc, argv, users, budgets, users_file, budgets_file);

   struct user *accounts;
   user_login(users_file, accounts, current_user, total_accounts);

   // exiting the program after 3 attempts
   if (current_user == -1){
      // deleting the heap arrays;
      delete_user_database(accounts);

      return 1;
   } else{
      welcome_message(total_accounts, current_user, accounts);

      struct budget *finances;
      database_initializer(budgets_file, finances, total_accounts, current_transactions, current_user);

      // printing the unsorted data for the current user
      unsorted_data(total_accounts, current_user, finances, current_transactions);
      sorted_data(total_accounts, current_user, finances, current_transactions);
      filing_data(total_accounts, current_user, finances, current_transactions);

      // deleting the heap arrays
      delete_user_database(accounts);
      delete_budget_database(finances, total_accounts);
   }
}

