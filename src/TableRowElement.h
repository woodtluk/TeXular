#ifndef TABLEROWELEMENT_H
#define TABLEROWELEMENT_H

#include "AbstractTableElement.h"

#include <QList>

#include "TableCellElement.h"


class TableRowElement : public AbstractTableElement
{
  Q_DISABLE_COPY(TableRowElement)
public:

    TableRowElement();
    TableRowElement(int nCellsInRow);
    ~TableRowElement() {}

    virtual QString getLatexString();
    virtual QString getTableData();

    void appendCell(TableCellElement* cell) {
      appendChild(cell);
    }
    void insertCell(int index, TableCellElement* cell) {
       insertChild(index, cell);
    }

    void removeCell(int index) {
       removeChild(index);
    }

    int getCellCount() const {return getChildrenCount();}
};

#endif // TABLEROWELEMENT_H
