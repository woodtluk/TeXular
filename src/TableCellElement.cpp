#include "TableCellElement.h"

CellElement::CellElement(  )
{
}

CellElement::CellElement(QString strData) {
  m_strData = strData;
}



CellElement::~CellElement(  )
{
}



QString CellElement::getLatexString() {
  return m_strData;
}

QString CellElement::getTableData() {
  return m_strData;
}
