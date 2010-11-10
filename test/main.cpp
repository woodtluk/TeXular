//#include <QCoreApplication>

//#include <iostream>

#include <QApplication>
//#include <QTest>

#include "TestCellElement.h"

int main(int argc, char * argv[])
{
	QApplication app(argc, argv);
	
	TestCellElement testCellElement;
	
	QTest::qExec(&testCellElement, argc, argv);
	
	return app.exec();
}
