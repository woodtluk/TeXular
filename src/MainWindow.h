#ifndef MAINWINDOW_H
#define MAINWINDOW_H
//
#include <QMainWindow>
#include "ui_MainWindow.h"
//
class MainWindow : public QMainWindow, public Ui::MainWindow
{
Q_OBJECT
public:
	MainWindow( QWidget * parent = 0, Qt::WFlags f = 0 );
private slots:
};
#endif




