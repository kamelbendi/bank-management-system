#include "investmentwindow.h"
#include "ui_investmentwindow.h"
#include "investmentaccount.h"
#include "bank.h"
#include "stock.h"

//#include <QtTest>
#include <QMessageBox>
#include <QTime>

#ifdef Q_OS_WIN
#include <windows.h> // for Sleep
#endif

InvestmentWindow::InvestmentWindow(InvestmentAccount *investment, Bank *bank, QWidget *parent) :
    QMainWindow(parent),
    investment(investment),
	bank(bank),
    ui(new Ui::InvestmentWindow)
{
    ui->setupUi(this);

    ui->usernameLabel-> setText(QString::fromStdString(investment->getUsername()));
    QString b = QString::number(investment->getBalance());
    ui->balanceLabel->setText(b);
    // setting up the first output after opening the window
    ui->amazon_amount->setText(QString::number(investment->owned_stocks.find("AMZN")->second));
    ui->apple_amount->setText(QString::number(investment->owned_stocks.find("AAPL")->second));
    ui->tesla_amount->setText(QString::number(investment->owned_stocks.find("TSLA")->second));
    ui->microsoft_amount->setText(QString::number(investment->owned_stocks.find("MSFT")->second));
    ui->google_amount->setText(QString::number(investment->owned_stocks.find("GOOGL")->second));

    ui->share_value ->setText("");

    if (stock_show==1){

        ui->share_value->setText(QString::number(bank->stocks.find("AAPL")->second.share));


    }
    else if(stock_show==2)
    {
        ui->share_value->setText(QString::number(bank->stocks.find("MSFT")->second.share));

    }
    else if (stock_show==3)
    {
        ui->share_value->setText(QString::number(bank->stocks.find("AMZN")->second.share));

    }
    else if (stock_show==4)
    {
        ui->share_value->setText(QString::number(bank->stocks.find("GOOGL")->second.share));

    }
    else if (stock_show==5)
    {
        ui->share_value->setText(QString::number(bank->stocks.find("TSLA")->second.share));

    }
}

InvestmentWindow::~InvestmentWindow()
{
    delete ui;

}
// transfer function
void InvestmentWindow::on_transferButton_clicked()
{
    this->recipient_username = ui->recipientUsername->text().toStdString();
    this->amount_sent = ui->amount->text().toFloat();

if (bank->accounts.find(recipient_username) != bank->accounts.end()){               // check if the account does exist
    bank->transfer(bank->getAccount(recipient_username), amount_sent, bank->getAccount(investment->getUsername())); //<---  senders account, correct.?
    QString b = QString::number(investment->getBalance());
    ui->balanceLabel->setText(b);
}

else
{
  QMessageBox::information(this, "Warning", "Username does not exist, please provide a valid one");
}
}


// CURRENT  VALUE SHARE DISPLAY
void InvestmentWindow::on_comboBox_currentTextChanged(const QString &arg1)
{

    if (arg1== QString::fromStdString("AAPL")){

        ui->share_value->setText(QString::number(bank->stocks.find("AAPL")->second.share));
        stock_show=1;  //
    }
    else if(arg1== QString::fromStdString("MSFT"))
    {
        ui->share_value->setText(QString::number(bank->stocks.find("MSFT")->second.share));
        stock_show=2;
    }
    else if (arg1== QString::fromStdString("AMZN"))
    {
        ui->share_value->setText(QString::number(bank->stocks.find("AMZN")->second.share));
        stock_show=3;
    }
    else if (arg1== QString::fromStdString("GOOGL"))
    {
        ui->share_value->setText(QString::number(bank->stocks.find("GOOGL")->second.share));
        stock_show=4;
    }
    else if (arg1== QString::fromStdString("TSLA"))
    {
        ui->share_value->setText(QString::number(bank->stocks.find("TSLA")->second.share));
        stock_show=5;
    }
}

//BUY

void InvestmentWindow::on_comboBox_buy_currentTextChanged(const QString &arg1)
{

    if (arg1== QString::fromStdString("AAPL")){
        stock_rank=1;

    }
    else if(arg1== QString::fromStdString("MSFT"))
    {
        stock_rank=2;
    }
    else if (arg1== QString::fromStdString("AMZN"))
    {
        stock_rank=3;
    }
    else if (arg1== QString::fromStdString("GOOGL"))
    {
        stock_rank=4;
    }
    else if (arg1== QString::fromStdString("TSLA"))
    {
        stock_rank=5;
    }

}

// BUY BUTTON
void InvestmentWindow::on_buyButton_clicked()
{
    int amount = ui->share_amount_buy->text().toInt();

    // if apple is selected :
    if (stock_rank==1){
    try {
        if (bank->apple.share * amount > investment->getBalance() || bank->apple.volume < amount) {
            throw std::out_of_range("Insufficient funds or insufficient number of stocks!\n");

        }
        else                // buying
        {
            investment->buy_stocks(bank->apple, amount);                                                       //buying the stock with the wanted amount
            ui->apple_amount->setText(QString::number(investment->owned_stocks.find("AAPL")->second));          //displaying it
            QString b = QString::number(investment->getBalance());                                             //plotting balance
            ui->balanceLabel->setText(b);                                                                       //displaying the new balance
        }

    } catch (std::exception& d) {
        qDebug() << d.what();
        qDebug() << "Insufficient funds or insufficient stocks\n";
        QMessageBox::information(this, "Warning", "Insufficient funds or insufficient number of stocks!");
    }

} else if (stock_rank==2){
        try {
            if (bank->microsoft.share * amount > investment->getBalance() || bank->microsoft.volume < amount) {
                throw std::out_of_range("Insufficient funds or insufficient number of stocks!\n");

            }
            else                // buying
            {
                investment->buy_stocks(bank->microsoft, amount);
                ui->microsoft_amount->setText(QString::number(investment->owned_stocks.find("MSFT")->second));
                QString b = QString::number(investment->getBalance());
                ui->balanceLabel->setText(b);
                qDebug()<<"microsoft";
            }

        } catch (std::exception& d) {
            qDebug() << d.what();
            qDebug() << "Insufficient funds or insufficient stocks\n";
            QMessageBox::information(this, "Warning", "Insufficient funds or insufficient number of stocks!");
        }
    }else if (stock_rank==3){
        try {
            if (bank->amazon.share * amount > investment->getBalance() || bank->amazon.volume < amount) {
                throw std::out_of_range("Insufficient funds or insufficient number of stocks!\n");

            }
            else                // buying
            {
                investment->buy_stocks(bank->amazon, amount);
                ui->amazon_amount->setText(QString::number(investment->owned_stocks.find("AMZN")->second));
                QString b = QString::number(investment->getBalance());
                ui->balanceLabel->setText(b);
                qDebug()<<"amazon";

            }

        } catch (std::exception& d) {
            qDebug() << d.what();
            qDebug() << "Insufficient funds or insufficient stocks\n";
            QMessageBox::information(this, "Warning", "Insufficient funds or insufficient number of stocks");
        }
    }else if (stock_rank==4){
        try {
            if (bank->alphabet.share * amount > investment->getBalance() || bank->alphabet.volume < amount) {
                throw std::out_of_range("Insufficient funds or insufficient number of stocks!\n");

            }
            else                // buying
            {
                qDebug()<<investment->owned_stocks.find("GOOGL")->second;
                investment->buy_stocks(bank->alphabet, amount);
                ui->google_amount->setText(QString::number(investment->owned_stocks.find("GOOGL")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);
                qDebug()<<investment->owned_stocks.find("GOOGL")->second;
            }

        } catch (std::exception& d) {
            qDebug() << d.what();
            qDebug() << "Insufficient funds or insufficient stocks\n";
            QMessageBox::information(this, "Warning", "Insufficient funds or insufficient number of stocks!");
        }
    }else if (stock_rank==5){
        try {
            if (bank->tesla.share * amount > investment->getBalance() || bank->tesla.volume < amount) {
                throw std::out_of_range("Insufficient funds or insufficient number of stocks!\n");

            }
            else                // buying
            {
                investment->buy_stocks(bank->tesla, amount);
                ui->tesla_amount->setText(QString::number(investment->owned_stocks.find("TSLA")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);
                qDebug()<<"buying tesla stocks";
        }

        } catch (std::exception& d) {
            qDebug() << d.what();
            qDebug() << "Insufficient funds or insufficient stocks\n";
            QMessageBox::information(this, "Warning", "Insufficient funds or insufficient number of stocks!");
        }
    }
}
// SELL
void InvestmentWindow::on_sellButton_clicked()
{
    int amount = ui->share_amount_sell->text().toInt();
    // if apple is selected :
    if (stock_rank_sell==1){

            investment->sell_stocks(bank->apple, amount);
            ui->apple_amount->setText(QString::number(investment->owned_stocks.find("AAPL")->second));
            QString b = QString::number(investment->getBalance());      // plotting the balance after change
            ui->balanceLabel->setText(b);

} else if (stock_rank_sell==2){
                investment->sell_stocks(bank->microsoft, amount);
                ui->microsoft_amount->setText(QString::number(investment->owned_stocks.find("MSFT")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);

    }else if (stock_rank_sell==3){
                investment->sell_stocks(bank->amazon, amount);
                ui->amazon_amount->setText(QString::number(investment->owned_stocks.find("AMZN")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);

    }else if (stock_rank_sell==4){

                investment->sell_stocks(bank->alphabet, amount);
                ui->google_amount->setText(QString::number(investment->owned_stocks.find("GOOGL")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);

    }else if (stock_rank_sell==5){

                investment->sell_stocks(bank->tesla, amount);
                ui->tesla_amount->setText(QString::number(investment->owned_stocks.find("TSLA")->second));
                QString b = QString::number(investment->getBalance());      // plotting the balance after change
                ui->balanceLabel->setText(b);

    }
}

// sell stocks
void InvestmentWindow::on_comboBox_sell_currentTextChanged(const QString &arg1)
{
    if (arg1== QString::fromStdString("AAPL")){
        stock_rank_sell=1;

    }
    else if(arg1== QString::fromStdString("MSFT"))
    {
        stock_rank_sell=2;
    }
    else if (arg1== QString::fromStdString("AMZN"))
    {
        stock_rank_sell=3;
    }
    else if (arg1== QString::fromStdString("GOOGL"))
    {
        stock_rank_sell=4;
    }
    else if (arg1== QString::fromStdString("TSLA"))
    {
        stock_rank_sell=5;
    }



}


void InvestmentWindow::on_start_clicked()
{
    ui->start->setVisible(false);

    int j=0;

    while (j<10000) {
        j++;

//DELAY FUNCTION
        QTime dieTime= QTime::currentTime().addMSecs(500);
        while (QTime::currentTime() < dieTime)
            QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
// END OF DELAY FUNCTION



        QString b = QString::number(investment->getBalance());
        ui->balanceLabel->setText(b);

        if (stock_show==1){
        bank->apple.share=bank->updateStockValue(bank->apple);
        ui->share_value->setText(QString::number(bank->apple.share));

        }
        else if(stock_show==2)
        {
        bank->microsoft.share=bank->updateStockValue(bank->microsoft);
        ui->share_value->setText(QString::number(bank->microsoft.share));
        }
        else if (stock_show==3)
        {
        bank->amazon.share=bank->updateStockValue(bank->amazon);
        ui->share_value->setText(QString::number(bank->amazon.share));
        }
        else if (stock_show==4)
        {
        bank->alphabet.share=bank->updateStockValue(bank->alphabet);
        ui->share_value->setText(QString::number(bank->alphabet.share));
        }
        else if (stock_show==5)
        {
            bank->tesla.share=bank->updateStockValue(bank->tesla);
            ui->share_value->setText(QString::number(bank->tesla.share));
        }

        ui->apple_amount->setText(QString::number(investment->owned_stocks.find("AAPL")->second));
        ui->microsoft_amount->setText(QString::number(investment->owned_stocks.find("MSFT")->second));
        ui->amazon_amount->setText(QString::number(investment->owned_stocks.find("AMZN")->second));
        ui->google_amount->setText(QString::number(investment->owned_stocks.find("GOOGL")->second));
        ui->tesla_amount->setText(QString::number(investment->owned_stocks.find("TSLA")->second));
}
}

void InvestmentWindow::on_logout_clicked()
{
    this->close();
}



