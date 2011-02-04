#include "MainWindow.h"

#include "TableModel.h"

#include <QDebug>

MainWindow::MainWindow( QWidget * parent, Qt::WFlags f)
	: QMainWindow(parent, f)
{
	setupUi(this);
  Ui::MainWindow::m_viewTable->setModel(new TableModel);

//  qDebug() << "Test";

}
//
