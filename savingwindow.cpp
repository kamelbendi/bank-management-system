#include "savingwindow.h"
#include "ui_savingwindow.h"
#include "savingaccount.h"
#include "bank.h"
//#include "stdlib.h"

//#include <stdio.h>
//#include <time.h>
#include <unistd.h>

#include <QMessageBox>
#include <QTime>
#include <QThread>
#include <chrono>
#include <thread>

using namespace std::literals::chrono_literals;

SavingWindow::SavingWindow(SavingAccount *saving, Bank *bank, QWidget *parent) :
	QMainWindow(parent),
	saving(saving),
	bank(bank),
	ui(new Ui::SavingWindow)


{
	ui->setupUi(this);
    ui->usernameLabel-> setText(QString::fromStdString(saving->getUsername()));
    QString b = QString::number(saving->getBalance());
    ui->balanceLabel->setText(b);

	ui-> month_expense -> setText(QString::number(saving->generate_expense()));
    ui -> total_saving_balance-> setText(QString::number(saving->savings_balance));
    ui->final_balance ->setText("0");

}


SavingWindow::~SavingWindow()
{
	delete ui;
	//ui->saving_input
}



void SavingWindow::on_transferButton_clicked()
{
    this->recipient_username = ui->recipientUsername->text().toStdString();
    this->amount_sent = ui->amount->text().toFloat();
    //bool existes = true;

if (bank->accounts.find(recipient_username) != bank->accounts.end()){               // check if the account does exist
    bank->transfer(bank->getAccount(recipient_username), amount_sent, bank->getAccount(saving->getUsername())); //<---  senders account, correct.?
    QString b = QString::number(saving->getBalance());
    ui->balanceLabel->setText(b);
}
else
{
  QMessageBox::information(this, "Warning", "Username doesnt exist, please provide a valid one");
}
}





void SavingWindow::on_pushButton_2_clicked()
{
	this->close();
}



void SavingWindow::on_take_all_savings_clicked()
{
	float x = saving->savings_balance;
	saving->take_savings(x);
	saving->savings_balance = 0;

}


void SavingWindow::on_startButton_clicked()
{
    ui->startButton->setVisible(false);

    int j=0;

    while (j<100) {
        j++;



//DELAY FUNCTION
        QTime dieTime= QTime::currentTime().addSecs(3);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
// END OF DELAY FUNCTION

// generating a new random expanse :
        float expense =saving->generate_expense();
        ui-> month_expense -> setText(QString::number(expense));

// storing the data from the user :
        float salary= ui->monthly_salary->text().toFloat();
        float saving_input= ui->saving_input->text().toFloat();

//increasing balance by salary
         saving->increase_salary(salary);
         QString b = QString::number(saving->getBalance());
          ui->balanceLabel->setText(b);

            ui->total_saving_balance->setText(QString::number(saving->increasing_savings(saving_input)));    // adding the money to the balance of savings and increasing with the rate


            if (saving->getBalance() - expense - saving_input > 0) {
                ui->final_balance -> setText(QString::number(saving->getBalance() - expense - saving_input));
            }
            else
            {
                ui->final_balance -> setText("0");
                 QMessageBox::information(this, "Warning", "Your expenses are too high, you have no money to spare");
            }
    }
    }




