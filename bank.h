#ifndef BANK_H
#define BANK_H

#include <string>
#include <map>

#include "normalaccount.h"
#include "investmentaccount.h"
#include "savingaccount.h"
#include "stock.h"

#include <QFile>
#include <QString>
#include <QTextStream>
#include <sstream>

using namespace std;

class Bank {
	string name;
	string location;
	string phone_number;
    string bankfile;

public:
    map<string, NormalAccount *> accounts; // Store the pointer of NormalAccount class. It will be easy to cast to the child from a parent pointer (according to stackoverflow, and thats the only way how i have managed to solve my errors)
	map<string, Stock> stocks;
    //createAccount
    //saveAccount
    //Bank() {} // added for transfer
    Bank(string name, string location, string phone_number, string bankfile) {
		this->name = name;
		this->location = location;
		this->phone_number = phone_number;
        this->bankfile = bankfile;

		createDummyStocks();
	}

	~Bank() {

		// Before closing bank save the accounts

        saveAccounts(bankfile);
		for (auto &p : accounts) {
            delete p.second;        // deleting p in order to have no memory leaks
		}
	}

public :
    Stock apple, microsoft, alphabet, amazon, tesla;
    std::string getBankfile() {
        return bankfile;
    }

	 void createAccount(string username, string password, float init_balance, string type) {
        NormalAccount *new_account = nullptr; // Store the pointer of NormalAccount class

		if (type == "investment") {

			// class pointer should be stored in the variable
			new_account = new InvestmentAccount(username, password, init_balance);        //creating account


        } else if (type == "saving") {

                // class pointer should be stored in the variable
			 new_account = new SavingAccount(username, password, init_balance);

        } else {                        // By default create the Normal account

			 new_account = new NormalAccount(username, password, init_balance);


        }
        accounts[new_account->getUsername()] = new_account;         //saving the account in the bank map

	}


void saveAccounts()  {
    saveAccounts(bankfile);
}

    void saveAccounts(const string &filename) {         // save all the contents of a map in a file

        QFile bankFile(QString::fromStdString(filename)); // Get the std::string to QString then open a QFile

        if (bankFile.open(QFile::ReadWrite )) { // Open the file to ReadWrite into it and clear the old content of the file
            QTextStream out(&bankFile); //<--QT text for file handeling-- Create a Text stream to write into the file

            std::stringstream ss; // Used to get the std::ostream output of our NormalAccount

			for (auto it = accounts.begin(); it != accounts.end(); it++) {
				ss << *(it->second);
			}

			out << QString::fromStdString(ss.str()); // Conver the std::stringstream to QString and write into the file

			bankFile.close(); // Close the file
		} else {
            std::cout << "Can not open file " << filename << " to save account." << endl;
		}
}

    void loadAccounts() {
        loadAccounts(bankfile);
    }
    void loadAccounts(const string &filename) { // Using const & we won't copy the argument value, instead use the reference of the value to access it.
		QFile bankFile(QString::fromStdString(filename));

        if (bankFile.open(QFile::ReadOnly)) {
			QTextStream data(&bankFile);
            QString line = "";                            // Individual line to read

            while (data.readLineInto(&line)) {          // Read the line and check whether it is read or not
                if (line.trimmed().isEmpty()) {         // Skip if we encounter an empty line
					continue;
				}

				// First line is id
//				 int id = line.toInt();

                QString userName = data.readLine();      // equivalent of getline() from standard lib
				if (!userName.count()) {
					break;
				}

				QString password = data.readLine();
				if (!password.count()) {
					break;
				}

				QString balance = data.readLine();
				if (!balance.count()) {
					break;
				}

				QString type = data.readLine();
				if (!type.count()) {
					break;
				}

				// Create the account from the read values
                createAccount(userName.toStdString(), password.toStdString(), balance.toInt(), type.toStdString());
			}

			bankFile.close();
		} else {
			cout << "Can not open file " << filename << " to load accounts." << endl;
		}


	}

    bool login(string username, string password) {
		auto acc = accounts.find(username);

		if (acc == accounts.end()) {
			cout << "Wrong username\n";
			return false;
		} else {
			return (acc->second->getPassword() == password); // checking for the passwordand type
		}

		return false;
	}

	NormalAccount *getAccount(string username) { // get the account out of a username string
		if (accounts.find(username) == accounts.end()) {
			cout << "wrong username";
			throw exception();
		}

		return accounts.find(username)->second;
	}

	void transfer(NormalAccount *receiver, float amount, NormalAccount *sender) { // Used to get the pointer argument of receiver and sender account
        if (amount > sender->getBalance()) {
			cout << "insufficent funds" << endl;

		} else {
			receiver->deposit(amount);
			sender->withdraw(amount);
		}
	}

	void createDummyStocks() {


		apple.stock_name = "Apple Inc.";
		apple.stock_symbol = "AAPL";
		apple.share = 159.69;
		apple.volume = 200;

		//
		microsoft.stock_name = "Microsoft Corporation";
		microsoft.stock_symbol = "MSFT";
		microsoft.share = 297.71;
		microsoft.volume = 200;

		//

		amazon.stock_name = "Alphabet Inc";
        amazon.stock_symbol = "AMZN";
		amazon.share = 2584.66;
		amazon.volume = 200;

		//
        alphabet.stock_name = "Google";
        alphabet.stock_symbol = "GOOGL";
		alphabet.share = 828.66;
		alphabet.volume = 200;

		//
        tesla.stock_name = "Tesla";
        tesla.stock_symbol = "TSLA";
		tesla.share = 2815.66;
		tesla.volume = 200;

		// insert dummy stocks to stocks map
		stocks[apple.stock_symbol] = apple;
		stocks[microsoft.stock_symbol] = microsoft;
		stocks[alphabet.stock_symbol] = alphabet;
		stocks[amazon.stock_symbol] = amazon;
		stocks[tesla.stock_symbol] = tesla;
	}

	// CAUTION: This is an infinite loop
    float updateStockValue(Stock stock) {
		float shareFraction = stock.share / 5;
                return stock.share += (arc4random_uniform (2*shareFraction)) - shareFraction;
	}
};

#endif
