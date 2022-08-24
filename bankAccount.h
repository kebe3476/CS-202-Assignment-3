
//Class bankAccount

#ifndef H_bankAccount
#define H_bankAccount



using namespace std;
/**
 * @brief bankAccount
 *
 */
class bankAccount
{
public:
    void setAccountNumber(int acct);
    void setAccountType(string accType);
    void setFirstName(string firstName);
    void setLastName(string lastName);
    void setCompanyName(string companyName);
    void setAddress(string address);
    void setCity(string city);
    void setPhone1(long int phone1);
    void setPhone2(long int phone2);
    void setBalance(int balance);

    int getAccountNumber() const;
    string getAccountType() const;
    string getFirstName() const;
    string getLastName() const;
    string getCompanyName() const;
    string getAddress() const;
    string getCity() const;
    long int getPhone1() const;
    long int getPhone2() const;
    double getBalance() const;


    void withdraw(double amount);
    void deposit(double amount);
    // void print() const;

protected:
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
};

#endif
