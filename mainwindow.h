#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bank.h"

QT_BEGIN_NAMESPACE
namespace Ui {
	class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
	Q_OBJECT
	// It's better have pointers instead of storing the values in the stack of the memory
	Bank *bank;

public:
	explicit MainWindow(Bank *bank, QWidget *parent = nullptr);

	~MainWindow();

private slots:
	void on_log_in_clicked();

	void on_register_2_clicked();

private:
	Ui::MainWindow *ui;

};

#endif // MAINWINDOW_H
