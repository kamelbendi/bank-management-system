#ifndef INVESTMENT_H
#define INVESTMENT_H

#include "normalaccount.h"
#include "stock.h"
#include "bank.h"
#include <QDebug>
#include <QMessageBox>
#include <exception>

using namespace std;

class InvestmentAccount : public NormalAccount {                             // stocks changing in value randomly and possibility to sell

public:
    map<string, int>owned_stocks;                                           //map for all of the stocks owned by the account at the moment
	InvestmentAccount(string username, string password, float init_balance)
		: NormalAccount(username, password, init_balance, "investment") {

        owned_stocks.insert(std::pair<string, int>("AAPL", 0));
        owned_stocks.insert(std::pair<string, int>("MSFT", 0));
        owned_stocks.insert(std::pair<string, int>("AMZN", 0));
        owned_stocks.insert(std::pair<string, int>("TSLA", 0));
        owned_stocks.insert(std::pair<string, int>("GOOGL", 0));
	}

    void buy_stocks(Stock stock, int amount) {
        if(balance>amount*stock.share){
        owned_stocks.find(stock.stock_symbol)->second += amount;
        this->balance -= amount*stock.share;
        stock.volume -= amount;
}
}

    void sell_stocks(Stock stock, int amount) {
        if (owned_stocks.find(stock.stock_symbol)->second>=amount){
        owned_stocks.find(stock.stock_symbol)->second -= amount;
        this->balance +=amount*stock.share;
        stock.volume+=amount;
        }
	}

	// Parent class inherited method to provide the account type for the current class of Account
	virtual AccountType getAccountType() {
		return Investment;
	}
};

#endif
