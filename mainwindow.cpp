#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"

#include "normalwindow.h"
#include "savingwindow.h"
#include "investmentwindow.h"
#include "registerdialog.h"

MainWindow::MainWindow(Bank *bank, QWidget *parent)
	: QMainWindow(parent)
	, bank(bank)
	, ui(new Ui::MainWindow)
{
	ui->setupUi(this);
}

MainWindow::~MainWindow()
{
	delete ui;
}

void MainWindow::on_log_in_clicked()
{
	std::string username = "";
	std::string password = "";
	bool loggedIn = false;

	while (!loggedIn) {
		LoginDialog loginDialog;

		if (loginDialog.exec()) { // Open the login dialog and wait for accepted or rejected from the dialog
			// Dialog accepted
			//login to account
			loggedIn = bank->login(loginDialog.username, loginDialog.password); // Dialog closed and check the user input information

			if (!loggedIn) { // Account not found.
				QMessageBox::critical(&loginDialog, "Incorrect credentials", "Your usrename or password are incorrect, please try again.");
			} else {
				username = loginDialog.username;
				password = loginDialog.password;
			}
		} else { // Dialog rejected
			loggedIn = true;
		}
	}

	QMainWindow *w = nullptr;

    if (username.size() && password.size() != 0) { // If username & password are not empty

		NormalAccount *account = bank->getAccount(username); // Get the account class from the bank account map

		// Check the account type and open appropriate window
		// Giving the parent reference so that whenever MainWindow is deleted it's child will also be deleted. (A Qt parent child functionality)
		if (account->getAccountType() == Normal) {
			w = new NormalWindow(account, bank, this);
		} else if (account->getAccountType() == Investment) {
			w = new InvestmentWindow(dynamic_cast<InvestmentAccount *>(account), bank, this);
		} else if (account->getAccountType() == Savings) {
			w = new SavingWindow(dynamic_cast<SavingAccount *>(account), bank, this);
		}
	}

	if (w) {
        w->show();           // Show the window if it is not nullptr
	}
}


void MainWindow::on_register_2_clicked()
{
	// UPDATED

    while (true) {
        RegisterDialog registerDialog(bank, this);

        if (registerDialog.exec()) { //if register dialog opened
            try {
                if (!registerDialog.usernameR.size() || !registerDialog.passwordR.size() || !registerDialog.initial_balance) {
                    throw std::invalid_argument("Fill in all data \n");
                }
                }  catch (std::exception &ex1) {
                qDebug() << ex1.what();
                QMessageBox::information(this, "Warning", "You have to fill in everything for a successful creation of your bank account");
                }
                // Check for uniqueness only if the username is not empty
                bool unique = true;

                if (bank->accounts.find(registerDialog.usernameR) != bank->accounts.end()) { // Check the account map
                    unique = false;
                }

                try {
                    if (!unique) {
                        throw std::invalid_argument("Username not unique\n");
                    }else{
                    // create and save in the file santander.dat
                    if (registerDialog.type == "investment") {
                        bank->createAccount(registerDialog.usernameR, registerDialog.passwordR, registerDialog.initial_balance, "investment");
                    } else if (registerDialog.type == "saving") {
                        bank->createAccount(registerDialog.usernameR, registerDialog.passwordR, registerDialog.initial_balance, "saving");
                    } else {
                        bank->createAccount(registerDialog.usernameR, registerDialog.passwordR, registerDialog.initial_balance, "normal");
                    }

                    bank->saveAccounts();         // save accounts
                    qDebug("saving");
                    break; // Break from the loop as we created a new account
                    }
                }  catch (std::exception &ex) {
                    qDebug() << ex.what();
                    QMessageBox::information(this, "Warning", "Username already existing, please provide another one");
                    continue;
                }

        } else {
            break;
        }
    }
}


