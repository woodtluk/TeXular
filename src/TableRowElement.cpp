#include "TableRowElement.h"

TableRowElement::TableRowElement()
{
}
TableRowElement::TableRowElement(int nCellsInRow) {
  for(int i=0; i<nCellsInRow; i++) {
    appendCell(new TableCellElement());
  }
}


QString TableRowElement::getLatexString() {
  return AbstractTableElement::getLatexString();
}

QString TableRowElement::getTableData() {
  return AbstractTableElement::getTableData();
}

