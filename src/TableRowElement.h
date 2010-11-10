#ifndef TABLEROWELEMENT_H
#define TABLEROWELEMENT_H

#include "AbstractTableElement.h"

class TableRowElement : public AbstractTableElement
{
  Q_DISABLE_COPY(TableRowElement)
public:
    TableRowElement();
    ~TableRowElement() {}

    virtual QString getLatexString();
    virtual QString getTableData();
};

#endif // TABLEROWELEMENT_H
