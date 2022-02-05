#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include "bank.h"

#include <QDialog>

namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    std::string usernameR;
    std::string passwordR;
    float initial_balance;
    std::string type;

	explicit RegisterDialog(Bank *bank, QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_buttonBox_accepted();

private:
	Bank *bank;
	Ui::RegisterDialog *ui;
};

#endif // REGISTERDIALOG_H
