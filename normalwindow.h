#ifndef NORMALWINDOW_H
#define NORMALWINDOW_H

#include <QMainWindow>

#include "normalaccount.h"
#include "bank.h"

namespace Ui {
class NormalWindow;
}

class NormalWindow : public QMainWindow
{
    Q_OBJECT
	// It's better have pointers instead of storing the values in the stack of the memory
	NormalAccount *account;
	Bank *bank; // for transfer function
public:
    std:: string recipient_username;
    int amount_sent;

	explicit NormalWindow(NormalAccount *account, Bank *bank, QWidget *parent = nullptr);


    ~NormalWindow();

private slots:

    void on_pushButton_2_clicked();

    void on_transferButton_clicked();

private:
    Ui::NormalWindow *ui;
};

#endif // NORMALWINDOW_H
