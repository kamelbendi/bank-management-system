#include "normalwindow.h"
#include "ui_normalwindow.h"
#include "normalaccount.h"
#include "bank.h"

#include <QMessageBox>

NormalWindow::NormalWindow(NormalAccount *account, Bank *bank, QWidget *parent) :
	QMainWindow(parent),
	account(account),
	bank(bank),
	ui(new Ui::NormalWindow)
{
	ui->setupUi(this);

	qWarning() << "Normal window";
	// setting the labels in the normalWindow
	ui->usernameLabel-> setText(QString::fromStdString(account->getUsername()));
    QString b = QString::number(account->getBalance());
    ui->balanceLabel->setText(b);
}

NormalWindow::~NormalWindow()
{
	delete ui;
}

void NormalWindow::on_pushButton_2_clicked()
{
	// to log out from the account
	this->close();
}

void NormalWindow::on_transferButton_clicked()
{
	// transfer button

	this->recipient_username = ui->recipientUsername->text().toStdString();
	this->amount_sent = ui->amount->text().toFloat();
    //bool existes = true;

if (bank->accounts.find(recipient_username) != bank->accounts.end()){               // check if the account does exist
    bank->transfer(bank->getAccount(recipient_username), amount_sent, bank->getAccount(account->getUsername())); //<---  senders account, correct.?
    QString b = QString::number(account->getBalance());
    ui->balanceLabel->setText(b);
}
else
{
  QMessageBox::information(this, "Warning", "Username doesnt exist, please provide a valid one");
}
}
