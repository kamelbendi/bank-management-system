#ifndef INVESTMENTWINDOW_H
#define INVESTMENTWINDOW_H

#include <QMainWindow>

#include "bank.h"
#include "investmentaccount.h"

namespace Ui {
class InvestmentWindow;
}

class InvestmentWindow : public QMainWindow
{
	Q_OBJECT
	// It's better have pointers instead of storing the values in the stack of the memory
	InvestmentAccount *investment;
	Bank *bank;
public:
    int stock_rank;     // RANK FOR BUYING : example :1 for apple 2 for microsoft ect
    int stock_rank_sell;
    int stock_show;
    std:: string recipient_username;
    int amount_sent;
	explicit InvestmentWindow(InvestmentAccount *investment, Bank *bank, QWidget *parent = nullptr);
    ~InvestmentWindow();

private slots:
    void on_transferButton_clicked();

    void on_comboBox_currentTextChanged(const QString &arg1);

    void on_buyButton_clicked();

    void on_sellButton_clicked();

    void on_comboBox_sell_currentTextChanged(const QString &arg1);

    void on_comboBox_buy_currentTextChanged(const QString &arg1);

    void on_start_clicked();

    void on_logout_clicked();

private:
    Ui::InvestmentWindow *ui;
};

#endif // INVESTMENTWINDOW_H
