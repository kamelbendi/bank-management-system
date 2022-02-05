#ifndef SAVING_H
#define SAVING_H

#include "normalaccount.h"

class SavingAccount : public NormalAccount {                                // add compound interest with chrono library

	float increasing_rate;
	float random_expenses;

	//float usable_balance;

    //float monthly_input_savings;

public:
    float monthly_salary;
	float savings_balance;
	float final_balance;
    SavingAccount(string username, string password, float init_balance)
		: NormalAccount(username, password, init_balance, "saving") {
        this->savings_balance =0;
		increasing_rate = 0.05;
        //this->monthly_salary = monthly_salary;
	}

	float generate_expense() {

		random_expenses = (
#ifdef __APPLE__
							  arc4random()
#else

#endif
                              % 100) + 300;

		return random_expenses;
	}



    float increasing_savings(float monthly_input_savings) {
        if (monthly_input_savings > 0 && final_balance!=0) {
            savings_balance += monthly_input_savings;
            balance -=monthly_input_savings;
        }
		savings_balance += savings_balance * increasing_rate;
        return savings_balance;
    }

	float take_savings(float savings_balance) {
        return balance += savings_balance;
	}

	void increase_salary(float monthly_salary) {
		this->balance += monthly_salary;
	}

	virtual AccountType getAccountType() {
		return Savings;
	}

};

#endif
