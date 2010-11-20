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

    int getRowCount() const {return getChildrenCount();}


};

#endif // TABLEELEMENT_H
