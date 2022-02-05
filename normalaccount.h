#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>
#include <string>
#include <iostream>

using namespace std;

// Used to differentiate the account class. Each account class must have a AccountType. If new account type needed then Better append a new Type here.
enum AccountType {
	Normal,
	Savings,
	Investment,
	Unknown
};

class NormalAccount {

	int id;
	string username;
	string password;
	string type;
    //AccountType accountType;

protected:
	float balance;
	static int account_count;

public:

	NormalAccount(string username, string password, float init_balance, string type = "normal") {
        this->id = account_count++;     //0
		this->username = username;      //1
		this->password = password;      //2
		this->balance = init_balance;   //3
		this->type = type;              //5
	}

	// UPDATED for child class to be deleted as there own.
	virtual ~NormalAccount() {}

	//
	int getId() {
		return id;
	}

	string getUsername() {
		return username;
	}

	string getPassword() {
		return password;
	}

	string getType() {
		return type;
	}

	float getBalance() {
        return this->balance;
	}

	virtual AccountType getAccountType() {
		return Normal;
	}

	void deposit(float amount) {
		balance += amount;
	}

	void withdraw(float amount) {
		balance -= amount;
	}

	//
	friend std::ostream &operator<< (std::ostream &stream, const NormalAccount &acc) {          //for printing on the file
		stream << acc.id << endl;
		stream << acc.username << endl;
		stream << acc.password << endl;
		stream << acc.balance << endl;
		stream << acc.type << endl;
		return stream;
	}

};

#endif
