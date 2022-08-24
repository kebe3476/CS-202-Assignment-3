/***********************
   CS 202 Assignment 3

   Name: Keith Beauvais, 5005338658, CS 202 Assignment 3

   Description: This is a banking system that deals with two seperate accounts, Checking and savings.
   It infiles a .csv with mixed accounts. The transaction will be successful only if the following 2
   conditions are met:
   i)Entered account number should match with account type(checking or savings). Separate account
   number for checking and savings account.
   ii)Entered account number details should be in the bankData.csv file. When you exit/quit the
   program, two separate data files (saving_account.csv and checking_account.csv) will be generated
   with the updated information of the accounts specifically withdraw and deposit.

   Input: The inputs are the bankData.csv base as an infile, all other inputs are user inputs

   Output: Outputs are to the terminal and outfile .csv saving_account.csv and checking_account.csv.

***********************/
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
#include "savingsAccount.h"

using namespace std;

/*  withdraw - If the amount is equal to or larger than the balance then it will cout
"Not enough money in the Savings account". If not it will substract the amount from the
balance.


return value - void function does not return a value

  Algorithm
        if else statement if there is more money than being requested it will
        subtract the amount and update balance if now cout error message.

*/
void savingsAccount::withdraw(double amount){
  if(amount >= balance){
    cout<< "Not enough money in the Savings account"<< endl;
  }
  else{
    balance = balance - amount;
  }
}

/* print - This function prints all the records to the terminal.

return value - void function does not return a value. Prints to the terminal.

Algorithm:
    cout to the terminal the account details.

*/
void savingsAccount::print() const{
  cout << "Savings ACCT #: " <<endl;
  cout << "Account Type: " << getAccountType() << endl;
  cout << "Account Number: " << getAccountNumber() << endl;
  cout << "First Name: " << getFirstName() << endl;
  cout << "Last Name: "<< getLastName() << endl;
  cout << "Balance: " << getBalance() << endl;
  cout << "Interest you can earn after 1 year: " << (balance*interestRate*1)/100<< endl;
  cout << "Interest you can earn after 2 year: " << (balance*interestRate*2)/100 << endl;
  cout << "Interest you can earn after 3 year: " << (balance*interestRate*3)/100 <<endl;
}

//sets the interestRate to the Const in savingsAccount.h
savingsAccount::savingsAccount(double intRate){
  interestRate = intRate;
}
