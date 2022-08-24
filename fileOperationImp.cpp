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
#include <sstream>
#include <string>
#include <vector>
#include "fileOperation.h"
#include "savingsAccount.h"
#include "checkingAccount.h"
#include "bankAccount.h"

using namespace std;

/* makeStringUpper - This function converts the passed string to upper case and returns it.

string s – the string to be converted to upper case.

return value – upper case version of passed string.

Algorithm:
    Goes through the string one letter at a time and makes it an upper case.

*/
string makeStringUpper(string s){
  for(int i =0; i < s.length(); i++){
    s[i]=toupper(s[i]);
  }
  return s;

  /* readFile -   Uses getline to read the data.  Once the line of data has
  been read, uses getNextField() to parse the line, one field at a time.  The initial
  call after the getline() should have the index set to zero, so it starts at the
  beginning of the string. getNextField() will update the index. If it the first index
  then that will indicate what type of account it is and will save into the respective
  acount type. As the line is read/parsed and the fields are parsed, set the corresponding
  value in the temporary record. Once parsing the line is complete, and the temporary
  record is filled, uses push_back( ) to add the temporary record to the account vector.

  ifstream & inFile - file stream varible that is passed into the function.

  vector<checkingAccount> &Caccount - vector type is used to read all fields of checking
  account data.

  vector<savingsAccount> &Saccount - vector type is used to read all fields of saving
  account data.

  int &count - This count is the number of accounts in the bankData.csv

  return value - Void function does not have a return value.

  */
}
void readFile(ifstream &inFile, vector<checkingAccount> &Caccount, vector<savingsAccount> &Saccount, int &count){
  string line, subString, accountType;
  int index, fieldNumber;
  checkingAccount cTemp;
  savingsAccount sTemp;

  getline(inFile, line);
  getline(inFile, line);
  line = line + '\n';
  while(!inFile.eof()){
    index = 0;
    fieldNumber = 0;
    for(int i = 0; i < 10 ; i++ ){
      getNextField(line, index, subString);
      if(i == 0){   //the first index is which account it is and sets that to accountType
        accountType = subString;
      }
      if(accountType == "Checking" ){
        saveFieldCheckingAccount (fieldNumber, subString, cTemp);
      }
      else if(accountType == "Saving" ){
        saveFieldSavingAccount(fieldNumber, subString, sTemp);
      }
      fieldNumber++;
    }
  if(accountType == "Checking"){
    Caccount.push_back(cTemp);
  }
  else if(accountType == "Saving"){
    Saccount.push_back(sTemp);
  }
  fieldNumber = 0;
  count++;
  getline(inFile, line);
  line = line + '\n';
  }
}
/* writeFile - Uses the fileClass class in order to open the ofstreams and to close them
using constructors and destructors. It then writes to that respective account .csv based on
account type.

ofstream &savingFile - output file stream variable for the file to be opened

ofstream &checkingFile - output file stream variable for the file to be opened file stream
variable for the file to be opened and is used to save checking account data.

vector<checkingAccount> &Caccount - vector type is used to save all fields of checking
account data

vector<savingsAccount> &Saccount - vector type is used to save all fields of saving account data

int &count - This count is the number of accounts in the bankData.csv

return value - Void function does not have a return value.

*/
void writeFile(ofstream &savingFile, ofstream &checkingFile, vector<checkingAccount> &Caccount, vector<savingsAccount> &Saccount, int &count){

  savingFile<< "Account Type"<< "," << "Account Number"<< ","<< "First Name"<< ","<< "Last Name"<< ","<< "Company Name"<< ","<< "Address"<< ","<< "City"<< ","<<"Phone1"<< ","<<"Phone2"<< ","<<"Balance"<< ","<<"\n";
  for(int i =0; i<Saccount.size();i++){
    savingFile<< Saccount[i].getAccountType()<< "," << Saccount[i].getAccountNumber()<<","<< Saccount[i].getFirstName()<< "," << Saccount[i].getLastName()<< "," << Saccount[i].getCompanyName()<< ",";
    savingFile<< Saccount[i].getAddress()<< "," << Saccount[i].getCity()<< "," << Saccount[i].getPhone1()<< "," << Saccount[i].getPhone2()<< "," << Saccount[i].getBalance()<< "\n";
  }



  checkingFile << "Account Type" << ","<< "Account Number"<< ","<< "First Name"<< ","<< "Last Name"<< ","<< "Company Name"<< ","<< "Address"<< ","<< "City"<< ","<<"Phone1"<< ","<<"Phone2"<< ","<<"Balance"<< ","<<"\n";
  for(int i =0; i<Caccount.size();i++){
    checkingFile<< Caccount[i].getAccountType()<< "," << Caccount[i].getAccountNumber()<<","<< Caccount[i].getFirstName()<< "," << Caccount[i].getLastName()<< "," << Caccount[i].getCompanyName()<< ",";
    checkingFile<< Caccount[i].getAddress()<< "," << Caccount[i].getCity()<< "," << Caccount[i].getPhone1()<< "," << Caccount[i].getPhone2()<< "," << Caccount[i].getBalance()<< "\n";
  }
}

/* openInputFile -  This function prompts the user for a .csv file to open. If the
user enters a q || Q then the function returns false and exits out. If the file name
does not exist or if the file cannot be opened then the user is reprompted until a
file name can be read and opened. Once that happens then it will return a true statement.

ifstream & inFile - file stream varible that is passed into the function.

return value - If the user types in q||Q then returns false statement. IF the
file is read and opened returns a true statement.

Algorithm:
    Prompts user for a file name. If the user types in a q || Q then the function
    will return false. If the user types in a file that cannot be opened then it
    goes into a while loop until the user types in a file name that can be read and
    opened and once that happens then the statement returns true.

*/
bool openInputFile(ifstream &inFile){
  string fileName;

      cout<< "Enter input File Name/ (q-quit): ";
      cin>> fileName;

      inFile.open(fileName);

      while(!inFile.is_open()){
        if(fileName == "q"){
          return false;
        }
        else if(fileName == "Q"){
          return false;
        }
        inFile.clear();
        inFile.ignore(100, '\n');
        cout<< "Enter input File Name/ (q-quit): ";
        cin >> fileName;
        inFile.open(fileName);
      }
      return true ;
}
/* getNextField -  This function gets a line of data from getline in readFile(),
it goes from coma to coma saving the sub strings until end of line. The string
found, not including the comma, is saved in the subString. Commas are skipped.
Parses one character at a time.

string &line – the line of data read from the file that needs to be parsed

int &index – the current starting position of the parsing. The first time this
function is called for a new line, index should be set to zero. The function
hould update the index beforereturning, so that on the next call it will look at
the next field.

string &subString – the parsed string

return value - Returns a false statement if the length of the string passed in is
less than or equal to the index number. Returns true if it does not.

Algorithm:
This function gets a line of data from getline in readFile(),
it goes from coma to coma saving the sub strings until end of line. The string
found, not including the comma, is saved in the subString. Commas are skipped.
Parses one character at a time.

*/
bool getNextField(string &line, int &index, string &subString){
  subString = "";

      while(line[index] != '\n' && line[index]!=','){
        subString += line[index];
        index++;
      }
      index++;
      if (line.length() <= index){
        return false;
      }
      else
        return true;
}

/* saveFieldSavingAccount -  This function saves the subString in to fieldNumber in the record
passed, tempItem. The subString can be converted to a double or an int, depending on the
fieldNumber. This function uses stringConvert() to perform the conversion from
string to double.

int fieldNumber - the number of the field, starting at zero

string subString- the value to be saved in the field.

AISType &tempItem - he record to which the field will be added.

return value - Void function does not have a return value.

Algorithm:
    Takes the passed in field number in the switch statement and correspondes
    that to the case #. If the subString needs to get converted to a double or int, it
    calls on stringConvert().

*/
void saveFieldSavingAccount(int fieldNumber, string subString, savingsAccount &tempItem){
  switch(fieldNumber)
      {
        case 0:
          tempItem.setAccountType(subString);
          break;
        case 1:
          tempItem.setAccountNumber(stringConvertInt(subString));
          break;
        case 2:
          tempItem.setFirstName(subString);
          break;
        case 3:
          tempItem.setLastName(subString);
          break;
        case 4:
          tempItem.setCompanyName(subString);
          break;
        case 5:
          tempItem.setAddress(subString);
          break;
        case 6:
          tempItem.setCity(subString);
          break;
        case 7:
          tempItem.setPhone1(stringConvertInt(subString));
          break;
        case 8:
          tempItem.setPhone2(stringConvertInt(subString));
          break;
        case 9:
          tempItem.setBalance(stringConvertDouble(subString));
          break;
        }
}
/* saveFieldCheckingAccount -  This function saves the subString in to fieldNumber in the record
passed, tempItem. The subString can be converted to a double or an int, depending on the
fieldNumber. This function uses stringConvert() to perform the conversion from
string to double.

int fieldNumber - the number of the field, starting at zero

string subString- the value to be saved in the field.

AISType &tempItem - he record to which the field will be added.

return value - Void function does not have a return value.

Algorithm:
    Takes the passed in field number in the switch statement and correspondes
    that to the case #. If the subString needs to get converted to a double or int, it
    calls on stringConvert().

*/
void saveFieldCheckingAccount(int fieldNumber, string subString, checkingAccount &tempItem){
  switch(fieldNumber)
      {
        case 0:
          tempItem.setAccountType(subString);
          break;
        case 1:
          tempItem.setAccountNumber(stringConvertInt(subString));
          break;
        case 2:
          tempItem.setFirstName(subString);
          break;
        case 3:
          tempItem.setLastName(subString);
          break;
        case 4:
          tempItem.setCompanyName(subString);
          break;
        case 5:
          tempItem.setAddress(subString);
          break;
        case 6:
          tempItem.setCity(subString);
          break;
        case 7:
          tempItem.setPhone1(stringConvertInt(subString));
          break;
        case 8:
          tempItem.setPhone2(stringConvertInt(subString));
          break;
        case 9:
          tempItem.setBalance(stringConvertDouble(subString));
          break;
        }
}
/* stringConvertDouble - This function converts strings into doubles.

string s - this string is passed in from the saveField function.

return value - returns a double from the string when called in saveField function.

Algorithm:
    Uses the string stream fuctionality of c++. Stores the the string into
    a string stream type varible and then stores string stream varible into a
    double value.
*/
double stringConvertDouble(string s){
  stringstream ss;
  double value;

  ss << s;
  ss >> value;

  return value;
}
/* stringConvertInt - This function converts strings into int.

string s - this string is passed in from the saveField function.

return value - returns a double from the string when called in saveField function.

Algorithm:
    Uses the string stream fuctionality of c++. Stores the the string into
    a string stream type varible and then stores string stream varible into a
    int value.
*/
long int stringConvertInt(string s){
  stringstream ss;
  int value;

  ss << s;
  ss >> value;

  return value;
}
/* processMoney - Initially, prompt a message to enter the account Checking or Saving.
use makeStringUpper for the entered account and compare. If the account does not match
with SAVING or CHECKING, then output an error message “Error : Entered Account type wrong,
Account type should be saving or checking”. Prompt a message to enter the account number,
and read the entered number as a string. Loops through the database vector, if the
account number matches with any saving account number in database, then display a
message “**Account Information before transaction **”. Prints out to the terminal.
If the account number is not found in the database, then display a message “Error:
Given Account number not present in Saving Account Type”. Displays a message
“**Account Information after transaction **” Again uses print() to check the
updated balance and other functions as above print().

vector<checkingAccount> &Caccount - vector type is used to read all fields of checking
account data.

vector<savingsAccount> &Saccount - vector type is used to read all fields of savings
account data.

bool deposit_f -  bool flag for detecting whether the transaction is a deposit.

bool withdraw_f- bool flag for detecting whether the transaction is a withdraw.

return value - returns an int value.
*/

int processMoney(vector<checkingAccount> &Caccount, vector<savingsAccount> &Saccount, bool deposit_f, bool withdraw_f){
  string bankChoice, accountNumber, amount, upper;
  int intNumber, found;
  savingsAccount save;
  checkingAccount saveC;
  bankAccount bankA;
  double doubleAmount;

  cout<< "Enter Account Type Name: Saving or Checking"<< endl;
  cin >> bankChoice;
  upper = makeStringUpper(bankChoice);

  if(upper == "SAVING"){
    cout<<"Enter Account Number:" <<endl;
    cin >> accountNumber;

    if(deposit_f == true){
      cout << "Enter the Deposit Amount"<<endl;
      cin >> amount;
    }
    if(withdraw_f == true){
      cout << "Enter Withdrawl Amount"<<endl;
      cin >> amount;
    }
    intNumber = stringConvertInt(accountNumber);
    doubleAmount = stringConvertDouble(amount);
    found = -1;
    for(int i =0; i < Saccount.size(); i++){
      if(Saccount[i].getAccountNumber() == intNumber){
        found = i;
        cout<< "***************Account Information before transaction***************"<< endl;
        }
      }
      if(found == -1){
        cout << "##############################################################" << endl;
        cout <<" Error: Given Account number not present in Saving Account Type" << endl;
        cout << "##############################################################" << endl;
      }
      else{
        Saccount[found].print();
        if(withdraw_f == true){
            Saccount[found].withdraw(doubleAmount);
        }
        if(deposit_f == true){
            Saccount[found].deposit(doubleAmount);
        }
        cout<< "***************Account Information after transaction***************"<< endl;
        Saccount[found].print();
      }

  }
  else if(upper == "CHECKING"){
    cout<<"Enter Account Number:" <<endl;
    cin >> accountNumber;

    if(deposit_f == true){
      cout << "Enter the Deposit Amount"<<endl;
      cin >> amount;
    }
    if(withdraw_f == true){
      cout << "Enter Withdrawl Amount"<<endl;
      cin >> amount;
    }
    intNumber = stringConvertInt(accountNumber);
    doubleAmount = stringConvertDouble(amount);
    found = -1;
    for(int i =0; i < Caccount.size(); i++){
      if(Caccount[i].getAccountNumber() == intNumber){
        found = i;
        cout<< "***************Account Information before transaction***************"<< endl;
        }
      }
      if(found == -1){
        cout << "##############################################################" << endl;
        cout <<" Error: Given Account number not present in Saving Account Type" << endl;
        cout << "##############################################################" << endl;
      }
      else{
        Caccount[found].print();
        if(withdraw_f == true){
          Caccount[found].withdraw(doubleAmount);
        }
        if(deposit_f == true){
          Caccount[found].deposit(doubleAmount);
        }
        cout<< "***************Account Information after transaction***************"<< endl;
        Caccount[found].print();
      }
  }
  else{
    cout << "#############################################################################" << endl;
    cout << "Error: Entered Account type wrong, Account type should be saving or checking"<< endl;
    cout << "#############################################################################" << endl;
  }

 return 0;
}
