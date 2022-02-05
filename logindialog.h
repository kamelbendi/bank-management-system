#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>

//#include "normalwindow.h"
//#include "normalaccount.h"
QT_BEGIN_NAMESPACE
namespace Ui {
class LoginDialog;
}
QT_END_NAMESPACE

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    std::string username;
    std::string password;


    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::LoginDialog *ui;
};

#endif // LOGINDIALOG_H
