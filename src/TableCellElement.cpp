#include "TableCellElement.h"

TableCellElement::TableCellElement(  )
{
}

TableCellElement::TableCellElement(QString strData) {
  m_strData = strData;
}



TableCellElement::~TableCellElement(  )
{
}



QString TableCellElement::getLatexString() {
  return m_strData;
}

QString TableCellElement::getTableData() {
  return m_strData;
}
