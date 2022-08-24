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
#include "bankAccount.h"

using namespace std;
/*
Setters for the inherited class bankAccount:
int accountNumber;
double balance;
string accountType;
string firstName;
string lastName;
string companyName;
string address;
string city;
long int phone1;
long int phone2;
*/
void bankAccount::setAccountNumber(int acct){
  this->accountNumber = acct ;
}
void bankAccount::setAccountType(string accType){
  this->accountType = accType;
}
void bankAccount::setFirstName(string firstName){
  this->firstName = firstName;
}
void bankAccount::setLastName(string lastName){
  this->lastName = lastName;
}
void bankAccount::setCompanyName(string companyName){
  this->companyName = companyName;
}
void bankAccount::setAddress(string address){
  this->address = address;
}
void bankAccount::setCity(string city){
  this->city = city;
}
void bankAccount::setPhone1(long int phone1){
  this->phone1 = phone1;
}
void bankAccount::setPhone2(long int phone2){
  this->phone2 = phone2;
}
void bankAccount::setBalance(int balance){
  this->balance = balance;
}

/*
Getters for the inherited class bankAccount:
int accountNumber;
double balance;
string accountType;
string firstName;
string lastName;
string companyName;
string address;
string city;
long int phone1;
long int phone2;
*/
int bankAccount::getAccountNumber() const{
  return accountNumber;
}
string bankAccount::getAccountType() const{
  return accountType;
}
string bankAccount::getFirstName() const{
  return firstName;
}
string bankAccount::getLastName() const{
  return lastName;
}
string bankAccount::getCompanyName() const{
  return companyName;
}
string bankAccount::getAddress() const{
  return address;
}
string bankAccount::getCity() const{
  return city;
}
long int bankAccount::getPhone1() const{
  return phone1;
}
long int bankAccount::getPhone2() const{
  return phone2;
}
double bankAccount::getBalance() const{
  return balance;
}


void bankAccount::withdraw(double amount){
  balance = balance - amount;
}
void bankAccount::deposit(double amount){
  balance = balance + amount;
}
