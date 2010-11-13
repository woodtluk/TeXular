#ifndef _TABLE_CELL_ELEMENT_H_
#define _TABLE_CELL_ELEMENT_H_

#include "AbstractTableElement.h"

#include <QString>


class TableCellElement : public AbstractTableElement {
  /// @todo Implement Copy-, Assignmentconstructor...
  Q_DISABLE_COPY(TableCellElement);

public:
  TableCellElement();
  TableCellElement(QString strData);
  virtual ~TableCellElement();

  virtual QString getLatexString();
  virtual QString getTableData();

private:
  QString m_strData;

};

#endif // _TABLE_CELL_ELEMENT_H
