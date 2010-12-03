#ifndef TABLEELEMENT_H
#define TABLEELEMENT_H

#include "AbstractTableElement.h"

#include "TableRowElement.h"

class TableElement : public AbstractTableElement
{
  Q_DISABLE_COPY(TableElement);

public:
    TableElement();
    virtual ~TableElement() {};

    virtual QString getLatexString();
    virtual QString getTableData();

    void appendRow(TableRowElement* row) {
      appendChild(row);
    }


    void insertRow(int index, TableRowElement* row) {
       insertChild(index, row);
    }

    void removeRow(int index) {
       removeChild(index);
    }

    int rowCount() const {return getChildrenCount();}

    int columnCount() const {
      int nColumns=0;
      foreach(AbstractTableElement* row, m_listOfChildren) {
        nColumns = qMax(row->getChildrenCount(), nColumns);
      }

    return nColumns;
  }
};

#endif // TABLEELEMENT_H
