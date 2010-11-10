#ifndef _TESTCELLELEMENT_H_
#define _TESTCELLELEMENT_H_

#include <QObject>
#include <QTest>

class TestCellElement : public QObject {
  
  Q_OBJECT

public:
  TestCellElement();
  ~TestCellElement();

private slots:
  void initTestCase(); // will be called before the first testfunction is executed.
  void cleanupTestCase(); // will be called after the last testfunction was executed.
  void init(); // will be called before each testfunction is executed.
  void cleanup(); // will be called after every testfunction.

  void getDataFromCellElement();
	
};

#endif // _TESTCELLELEMENT_H_