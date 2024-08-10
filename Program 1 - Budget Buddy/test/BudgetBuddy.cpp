// Implementation File Code: BudgetBuddy.cpp
// CONTAINS ALL THE FUNCTION DEFINITIONS

#include <iostream>
#include <cstring>
#include <cstdlib>
#include <string>
#include <fstream>
#include "./BudgetBuddy.h"

using namespace std;

void command_line_check(int argc, char **argv, string &users, string &budgets, fstream &users_file, fstream &budgets_file){
   if (argc !=3){
      cout << "You have entered the incorrect number of files, please enter new file names" << endl;
      cout << "Users  file: ";
      cin >> users;
      cout << endl;
      cout << "Budgets  file: ";
      cin >> budgets;
   } else{
      users = argv[1];
      budgets = argv[2];
   }


   // checking if the users.txt file is a valid file input
   cout << "Checking if the users file is a valid file input " << endl;
   file_check(users, users_file);

   // checking if the budgets.txt file is a valid file input
   cout << "Checking if the budgets file is a valid file input " << endl;
   file_check(budgets, budgets_file);
}

void file_check(string &file, fstream &file_type){
   bool check = true;
   while (check){
      file_type.open(file.c_str());

      if (!file_type.is_open()){
	 cout << "Failed to open the file, please enter a new file name" << endl;
	 cin >> file;
      } else {
	 check = false;
	 cout << "You have inputted a valid file name" << endl;
	 cout << endl;
      }
   }
}

void user_login (fstream &users_file, user *&accounts, int &current_user, int &total_accounts){
   total_accounts = number_of_accounts(users_file);
   cout << "There are " << total_accounts << " accounts registered" << endl;

   // creating the database to store the account information in the struct
   accounts = accounts_database(total_accounts);
   account_information(accounts, users_file, total_accounts);

   // Logging in the user
   string str_user_name;
   int user_name;
   string password;
   int attempts = 3;

   // Prompting the user for the password and username
   while (attempts != 0){
      cout << endl;
      cout << "You have " << attempts << " attempts remaining" << endl;
      cout << "Enter in your user name: ";
      cin >> str_user_name;
      contains_letters(str_user_name, user_name);
      cout << endl;
      cout << "Enter in your password: ";
      cin >> password;
      cout << endl;

      correct_account(user_name, password, attempts, total_accounts, accounts);
      if (attempts == -1){
	 current_user = user_name;
	 attempts = 0;
      } else if (attempts - 1 == 0){
	 current_user = -1;
	 attempts--;
	 cout << "You have exceeded the number of total attempts, ending the program" << endl;
      } else{
	 attempts--;
	 cout << "You have entered an incorrect password / username" << endl;
      }
   }

   users_file.close();
}

int number_of_accounts(fstream &users_file){
   string line;
   users_file >> line;
   return atoi(line.c_str());
}

user* accounts_database(int accounts){
   struct user *arr = new struct user[accounts];
   return arr;
}

void account_information(user * accounts, fstream &users_file, int total_accounts){
   string line;
   int id;

   for (int i = 0; i < total_accounts; i++){
      users_file >> line;
      accounts[i].name = line;
      users_file >> id;
      accounts[i].id = id;
      users_file >> line;
      accounts[i].password = line;
   }
}

void contains_letters(string &letters, int &numbers){
   bool valid = true;
   int check = 0;

   while (valid){
      for (int i = 0; i < letters.length(); i++){
	 if (letters[i] > '9' || letters[i] < '0'){
	    check++;
	 }
      }

      if (check != 0){
	 cout << "You have entered in a user name that contains letters, please enter in another user name" << endl;
	 cin >> letters;
	 check = 0;
      } else{
	 numbers = atoi(letters.c_str());
	 valid = false;
      }
   }
}

void correct_account(int user_name, string password, int &attempts, int total_accounts, user *accounts){
   for (int i = 0; i < total_accounts; i++){
      if (accounts[i].id == user_name && accounts[i].password == password){
	 attempts = -1;
      }
   }
}

void welcome_message(int total_accounts, int current_user, user *accounts){
   for (int i = 0; i < total_accounts; i++){
      if (accounts[i].id == current_user){
	 cout << "Welcome to your account, " << accounts[i].name;
	 cout << endl;
      }
   }
}

void database_initializer(fstream &budgets_file, budget *&finances, int total_accounts, int &current_transactions, int current_user){
   // creating the finance array made from the budget struct
   finances = create_budgets(total_accounts);

   int accounts;
   budgets_file >> accounts;
   total_accounts = accounts;

   // filling the finance array
   get_budget_data(finances, total_accounts, budgets_file, current_transactions, current_user);

   budgets_file.close();
}

budget *create_budgets(int accounts){
   struct budget *arr = new struct budget[accounts];
   return arr;
}

transaction *create_transactions(int actions){
   struct transaction *arr = new struct transaction[actions];
   return arr;
}

void get_budget_data(budget *finances, int total_accounts, fstream &budgets_file, int &current_transactions, int current_user){
   int id;
   float balance;
   int num_transactions;

   for (int i = 0; i < total_accounts; i++){
      budgets_file >> id;
      finances[i].id = id;
      budgets_file >> balance;
      finances[i].balance = balance;
      budgets_file >> num_transactions;
      finances[i].num_transactions = num_transactions;

      if (finances[i].id == current_user){
	 current_transactions = finances[i].num_transactions;
      }

      // creating the transactions and filling the array
      finances[i].purchases = create_transactions(finances[i].num_transactions);
      get_transaction_data(finances[i].purchases, num_transactions, budgets_file);
   }
}

void get_transaction_data(transaction *purchases, int num_transactions, fstream &budgets_file){
   float amount;
   string date;
   string category;
   string description;

   for (int i = 0; i < num_transactions; i++){
      budgets_file >> date;
      purchases[i].date = date;
      budgets_file >> amount;
      purchases[i].amount = amount;
      budgets_file >> description;
      purchases[i].description = description;
      budgets_file >> category;
      purchases[i].category = category;
   }
}

void unsorted_data(int total_accounts, int current_user, budget *finances, int current_transactions){
   for (int i = 0; i < total_accounts; i++){
      if (current_user == finances[i].id){
	 cout << "Your user ID is: " << finances[i].id << endl;
	 cout << "Your current account balance is: " << finances[i].balance << endl;
	 cout << "Number of transactions made on this account: " << finances[i].num_transactions << endl;
	 cout << endl;
	 cout << "Printing unsorted transaction data: " << endl;
      }
   }
   display_data(total_accounts, current_user, finances, current_transactions);
}

void sorted_data(int total_accounts, int current_user, budget *finances, int current_transactions){
   bool repeat = true;
   int category = 0;
   string input;

   while (repeat){
      category_chooser(category);

      if (category == 1){
	 one_unsorted(total_accounts, current_user, finances, current_transactions);
      } else if (category == 2){
	 two_amount(total_accounts, current_user, finances, current_transactions);
      } else if (category == 3){
	 three_category(total_accounts, current_user, finances, current_transactions);
      } else if (category == 4){
	 four_date(total_accounts, current_user, finances, current_transactions);
      }

      cout << "Would you like to display another sorting method?" << endl;
      cout << "Input 'yes' to repeat or any other character for 'no' " << endl;
      cin >> input;

      if (input != "yes"){
	 repeat = false;
      }
   }
}

void one_unsorted(int total_accounts, int current_user, budget *finances, int current_transactions){
   cout << "Displaying the unsorted transaction history" << endl;
   display_data(total_accounts, current_user, finances, current_transactions);
}

void two_amount(int total_accounts, int current_user, budget *finances, int current_transactions){
   cout << "Displaying the amount-sorted transaction history" << endl;
   for (int t = 0; t < total_accounts; t++){
      if (finances[t].id == current_user){
	 for (int i = 0; i < (current_transactions - 1); i++){
	    for (int j = 0; j < (current_transactions - i - 1); j++){
	       if (finances[t].purchases[j].amount < finances[t].purchases[j+1].amount){
		  swap (finances, j, t);
	       }
	    }
	 }
      }
   }
   display_data(total_accounts, current_user, finances, current_transactions);

}

void three_category(int total_accounts, int current_user, budget *finances, int current_transactions){
   // the category function is so large due to how it swaps each of the categories into numerical equivalents
   // while I was initially planning on separating this into 3 different functions, it wouldn't reduce the overall size of the code
   // as each of the portions of the code are distinctively different and cannot be shrunk
   // as such, for the sake of simplicity I kept it on one file

   cout << "Displaying the category-sorted transaction history" << endl;

   // assigns each category a value from 0 to 5 based on importance
   for (int i = 0; i < total_accounts; i ++){
      if (finances[i].id == current_user){
	 for (int j = 0; j < current_transactions; j++){
	    if (finances[i].purchases[j].category == "Housing"){
	       finances[i].purchases[j].category = "0";
	    } else if (finances[i].purchases[j].category == "Food"){
	       finances[i].purchases[j].category = "1";
	    } else if (finances[i].purchases[j].category == "Entertainment"){
	       finances[i].purchases[j].category = "2";
	    } else if (finances[i].purchases[j].category == "Personal_Care"){
	       finances[i].purchases[j].category = "3";
	    } else if (finances[i].purchases[j].category == "Miscellaneous"){
	       finances[i].purchases[j].category = "4";
	    } 
	 }
      }
   }

   // swaps the transactions based on category's importance
   for (int t = 0; t < total_accounts; t++){
      if (finances[t].id == current_user){
	 for (int i = 0; i < (current_transactions - 1); i++){
	    for (int j = 0; j < (current_transactions - i - 1); j++){
	       if (finances[t].purchases[j].category > finances[t].purchases[j+1].category){
		  swap (finances, j, t);
	       }
	    }
	 }
      }
   }

   // changes the values back to the original category types
   for (int i = 0; i < total_accounts; i ++){
      if (finances[i].id == current_user){
	 for (int j = 0; j < current_transactions; j++){
	    if (finances[i].purchases[j].category == "0"){
	       finances[i].purchases[j].category = "Housing";
	    } else if (finances[i].purchases[j].category == "1"){
	       finances[i].purchases[j].category = "Food";
	    } else if (finances[i].purchases[j].category == "2"){
	       finances[i].purchases[j].category = "Entertainment";
	    } else if (finances[i].purchases[j].category == "3"){
	       finances[i].purchases[j].category = "Personal_Care";
	    } else if (finances[i].purchases[j].category == "4"){
	       finances[i].purchases[j].category = "Miscellaneous";
	    } 
	 }
      }
   }

   display_data(total_accounts, current_user, finances, current_transactions);

}

void four_date(int total_accounts, int current_user, budget *finances, int current_transactions){
   cout << "Displaying the date-sorted transaction history" << endl;

   date_reverser_back(total_accounts, current_user, finances, current_transactions);
   for (int t = 0; t < total_accounts; t++){
      if (finances[t].id == current_user){
	 for (int i = 0; i < (current_transactions - 1); i++){
	    for (int j = 0; j < (current_transactions - i - 1); j++){
	       if (finances[t].purchases[j].date < finances[t].purchases[j+1].date){
		  swap (finances, j, t);
	       }
	    }
	 }
      }
   }
   date_reverser_forward(total_accounts, current_user, finances, current_transactions);

   display_data(total_accounts, current_user, finances, current_transactions);
}

void date_reverser_back(int total_accounts, int current_user, budget *finances, int current_transactions){
   string swap = "";

   // swaps the order to go year / month / day
   for (int i = 0; i < total_accounts; i++){
      if (finances[i].id == current_user){
	 for (int j = 0; j < current_transactions; j++){
	    // the year
	    for (int k = 6; k < 10; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }
	    swap = swap + '/';

	    // the month
	    for (int k = 3; k < 5; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }
	    swap = swap + '/';

	    // the day
	    for (int k = 0; k < 2; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }

	    // adding the swapped date order to the string
	    finances[i].purchases[j].date = swap;
	    swap = "";
	 }
      }
   }
}

void date_reverser_forward(int total_accounts, int current_user, budget *finances, int current_transactions){
   string swap = "";

   // swaps the order back to go day / month / year
   for (int i = 0; i < total_accounts; i++){
      if (finances[i].id == current_user){
	 for (int j = 0; j < current_transactions; j++){
	    // the day
	    for (int k = 8; k < 10; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }
	    swap = swap + '/';

	    // the month
	    for (int k = 5; k < 7; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }
	    swap = swap + '/';

	    // the year
	    for (int k = 0; k < 4; k++){
	       swap = swap + finances[i].purchases[j].date[k];
	    }

	    // adding the swapped date order to the string
	    finances[i].purchases[j].date = swap;
	    swap = "";
	 }
      }
   }
}

void swap(budget *finances, int j, int t){
   int swap1 = 0;
   string swap2 = "0";

   swap1 = finances[t].purchases[j].amount;
   finances[t].purchases[j].amount = finances[t].purchases[j+1].amount;
   finances[t].purchases[j+1].amount = swap1;

   swap2 = finances[t].purchases[j].date;
   finances[t].purchases[j].date = finances[t].purchases[j+1].date;
   finances[t].purchases[j+1].date = swap2;

   swap2 = finances[t].purchases[j].category;
   finances[t].purchases[j].category = finances[t].purchases[j+1].category;
   finances[t].purchases[j+1].category = swap2;

   swap2 = finances[t].purchases[j].description;
   finances[t].purchases[j].description = finances[t].purchases[j+1].description;
   finances[t].purchases[j+1].description = swap2;
}

void display_data(int total_accounts, int current_user, budget *finances, int current_transactions){
   for (int i = 0; i < total_accounts; i++){
      if (current_user == finances[i].id){
	 for (int j = 0; j < current_transactions; j++){
	    cout << "Purchase #" << j + 1 << ": " << endl;
	    cout << "Date: " << finances[i].purchases[j].date << "    ";
	    cout << "Amount: " << finances[i].purchases[j].amount << "    ";
	    cout << "Category: " << finances[i].purchases[j].category << "    ";
	    cout << "Description: " << finances[i].purchases[j].description << endl;
	 }
	 cout << endl;
      }
   }
   cout << endl;
}

void category_chooser(int &category){
   bool check = true;
   string input = "";
   int non_ints = 0;

   cout << "Please enter a category to sort the data by (chose 1 through 4)" << endl;
   cout << "1. Unsorted Data" << endl;
   cout << "2. Sort by Amount" << endl;
   cout << "3. Sort by Category" << endl;
   cout << "4. Sort by Date" << endl;

   while (check){
      cin >> input;

      for (int i = 0; i < input.length(); i++){
	 if (input[i] > '4' || input[i] < '1'){
	    non_ints++;
	 }
      }

      if (non_ints != 0){
	 cout << "Error, you have not inputed a 1-4 choice. Please input another value" << endl;
	 non_ints = 0;
      } else{
	 category = atoi(input.c_str());
	 check = false;
      }
   }
}

void filing_data(int total_accounts, int current_user, budget *finances, int current_transactions){
   string file_name = "";
   cout << "Type the file name that you want the sorted transaction info to be added to" << endl;
   cin >> file_name;
   ofstream outputs_file(file_name.c_str());

   for (int i = 0; i < total_accounts; i++){
      if (current_user == finances[i].id){
	 outputs_file << "Your user ID is: " << finances[i].id << endl;
	 outputs_file << "Your current account balance is: " << finances[i].balance << endl;
	 outputs_file << "Number of transactions made on this account: " << finances[i].num_transactions << endl;
	 outputs_file << endl;
	 outputs_file << "Transaction data: " << endl;
	 for (int j = 0; j < current_transactions; j++){
	    outputs_file << "Purchase #" << j + 1 << ": " << endl;
	    outputs_file << "Date: " << finances[i].purchases[j].date << "    ";
	    outputs_file << "Amount: " << finances[i].purchases[j].amount << "    ";
	    outputs_file << "Category: " << finances[i].purchases[j].category << "    ";
	    outputs_file << "Description: " << finances[i].purchases[j].description << endl;
	 }
	 outputs_file << endl;
      }
   }

   outputs_file.close();
}

void delete_user_database(user *&accounts){
   delete [] accounts;
   accounts = NULL;
}

void delete_transaction_database(transaction *&purchases){
   delete [] purchases;
   purchases = NULL;

}

void delete_budget_database(budget *&finances, int total_accounts){
   for (int i = 0; i < total_accounts; i++){
      for (int j = 0; j < finances[i].num_transactions; j++){
	 delete_transaction_database(finances[i].purchases);
      }
   }

   delete [] finances;
   finances = NULL;
}

