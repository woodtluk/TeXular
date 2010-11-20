#include "TableCellElement.h"

TableCellElement::TableCellElement(  )
{
}

TableCellElement::TableCellElement(QString strData) {
  m_strData = strData;
}

TableCellElement::TableCellElement(const TableCellElement& rhs)
  : m_strData(rhs.m_strData) {

}

TableCellElement& TableCellElement::operator= (const TableCellElement& rhs) {
  if(this == &rhs) {
    return *this;
  }

  m_strData = rhs.m_strData;

  return *this;
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
