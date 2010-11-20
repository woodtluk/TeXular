#include "AbstractTableElement.h"

/*
AbstractTableElement::AbstractTableElement(const AbstractTableElement& rhs)
  : m_listOfChildren(rhs.m_listOfChildren){

}

AbstractTableElement& AbstractTableElement::operator= (const AbstractTableElement& rhs) {
  // self assignment
  if (this == &rhs)
  {
    return *this;
  }

  m_listOfChildren = rhs.m_listOfChildren;

  return *this;
}*/

QString AbstractTableElement::getLatexString() /*=0*/ {
  QString strToReturn;
  foreach(AbstractTableElement* child, m_listOfChildren) {
      strToReturn += child->getLatexString();
    }
  return strToReturn;
}

QString AbstractTableElement::getTableData() /*=0*/ {
  QString strToReturn;
  foreach(AbstractTableElement* child, m_listOfChildren) {
      strToReturn += child->getTableData();
    }
  return strToReturn;
}

void AbstractTableElement::appendChild(AbstractTableElement* child) {
  Q_ASSERT(child);
  m_listOfChildren.append(child);
}

void AbstractTableElement::insertChild(int index, AbstractTableElement* child) {
  Q_ASSERT(child);
  Q_ASSERT(0<index && m_listOfChildren.size()>=index);

  if(0<index && m_listOfChildren.size()>=index) {
    m_listOfChildren.insert(index, child);
  }

}

void AbstractTableElement::removeChild(int index) {
  Q_ASSERT(0<index && m_listOfChildren.size()>index);

    if(0<index && m_listOfChildren.size()>index) {
      AbstractTableElement* childToDelete = m_listOfChildren.takeAt(index);
      delete childToDelete;
  }
}
