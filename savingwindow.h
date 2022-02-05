#ifndef SAVINGWINDOW_H
#define SAVINGWINDOW_H

#include <QMainWindow>
#include "bank.h"
#include "savingaccount.h"

namespace Ui {
class SavingWindow;
}

class SavingWindow : public QMainWindow
{
    Q_OBJECT
	// It's better have pointers instead of storing the values in the stack of the memory
	SavingAccount *saving;
	Bank *bank;
public:

    std:: string recipient_username;
    int amount_sent;
	explicit SavingWindow(SavingAccount *saving, Bank *bank, QWidget *parent = nullptr);
    ~SavingWindow();

private slots:
    void on_transferButton_clicked();

    void on_pushButton_2_clicked();

    void on_take_all_savings_clicked();

    void on_startButton_clicked();

private:
    Ui::SavingWindow *ui;
};

#endif // SAVINGWINDOW_H
