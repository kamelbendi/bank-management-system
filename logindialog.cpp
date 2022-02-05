#include "logindialog.h"
#include "ui_logindialog.h"

LoginDialog::LoginDialog(QWidget *parent) :
	QDialog(parent),
	ui(new Ui::LoginDialog)
{
	ui->setupUi(this);
    ui->usernameLine ->setPlaceholderText("Enter your existing username");
    ui->passwordLine ->setPlaceholderText("Enter your password");
}

LoginDialog::~LoginDialog()
{
	delete ui;
}




void LoginDialog::on_buttonBox_accepted()
{
	this->username = ui->usernameLine->text().toStdString();
	this->password = ui->passwordLine->text().toStdString();
}

void LoginDialog::on_buttonBox_rejected()
{
	reject();
}
