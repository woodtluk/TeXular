#ifndef _TABLE_CELL_ELEMENT_H_
#define _TABLE_CELL_ELEMENT_H_

#include "AbstractTableElement.h"

#include <QString>


class CellElement : public AbstractTableElement {
  /// @todo Implement Copy-, Assignmentconstructor...
  Q_DISABLE_COPY(CellElement);

public:
  CellElement();
  CellElement(QString strData);
  virtual ~CellElement();

  virtual QString getLatexString();
  virtual QString getTableData();

private:
  QString m_strData;

};

#endif // _TABLE_CELL_ELEMENT_H
