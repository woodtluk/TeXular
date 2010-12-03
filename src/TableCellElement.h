#ifndef _TABLE_CELL_ELEMENT_H_
#define _TABLE_CELL_ELEMENT_H_

#include "AbstractTableElement.h"

#include <QString>


class TableCellElement : public AbstractTableElement {

public:
  TableCellElement();
  TableCellElement(QString strData);

  TableCellElement(const TableCellElement& rhs);
  TableCellElement& operator= (const TableCellElement& rhs);

  virtual ~TableCellElement();

  virtual QString getLatexString();
  virtual QString getTableData();
  virtual void setTableData(QString strText);

private:
  QString m_strData;

};

#endif // _TABLE_CELL_ELEMENT_H
