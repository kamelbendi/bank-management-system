#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "bank.h"
//#include "mainwindow.h"
//#include "investmentaccount.h"
#include <QMessageBox>

// UPDATED
// It's better to have the bank class as a pointer argument instead of creating the same bank class again.
RegisterDialog::RegisterDialog(Bank *bank, QWidget *parent)
	: QDialog(parent),
	  bank(bank),
    ui(new Ui::RegisterDialog)
{
    ui->setupUi(this);
    ui->usernameLine ->setPlaceholderText("Enter your username");
    ui->balanceLine->setPlaceholderText("enter your initial balance");
    ui->passwordLine->setPlaceholderText("Provide a strong password");
    ui->normal_account_type->setChecked(true);
    if (ui->investment_account_type->isChecked())
    {
        ui->accountText->setText("You will open a new investment account, where you can buy stocks!");
    }
    else if(ui->normal_account_type->isChecked())
    {
        ui->accountText->setText("Normal account is selected by default");
    }
    else
    {
        ui->accountText->setText("You have selected a Salary and Savings account!");
    }


}

RegisterDialog::~RegisterDialog()
{
    delete ui;
}


void RegisterDialog::on_buttonBox_accepted()
{
    this->usernameR = ui->usernameLine->text().toStdString();
    this->passwordR = ui->passwordLine->text().toStdString();
    this->initial_balance= ui->balanceLine->text().toFloat();

    if (ui->investment_account_type->isChecked())
    {

		this->type="investment";
    }
	else if(ui->salary_account_type->isChecked())
    {
		this->type = "saving";
    }
    else
    {
		this->type = "normal";
    }

}

