#ifndef TABLEELEMENT_H
#define TABLEELEMENT_H

#include "AbstractTableElement.h"

class TableElement : public AbstractTableElement
{
  Q_DISABLE_COPY(TableElement);
public:
    TableElement();
    ~TableElement() {};

    virtual QString getLatexString();
    virtual QString getTableData();

};

#endif // TABLEELEMENT_H
