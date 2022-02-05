//#include <iostream>
#include <QApplication>

//#include "normalwindow.h"

#include "bank.h"
//#include "bankapp.h"
//#include "logindialog.h"

#include "mainwindow.h"

#include <QFileInfo>

int main(int argc, char *argv[])
{
    Bank santander("Santander Bank", "Gliwice 44-100", "+4899999","/Users/mac/Desktop/BankApp_v5/Resources/santander.dat" );

	// UPDATED
    santander.loadAccounts(); // Load the bank from the resource file

	QApplication app(argc, argv);


    MainWindow w(&santander); // Provide the pointer of the bank to the mainwindow class
	w.show(); // Show the QMainWindow

	return app.exec();
}
