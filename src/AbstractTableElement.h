#ifndef _ABSTRACT_TABLE_ELEMENT_H_
#define _ABSTRACT_TABLE_ELEMENT_H_

#include <QString>
#include <QList>


class AbstractTableElement {
  /// @todo setters, constructors, copy & assign constructor...
  Q_DISABLE_COPY(AbstractTableElement);

public:
  //AbstractTableElement(const AbstractTableElement& rhs);
  //AbstractTableElement& operator= (const AbstractTableElement& rhs);
  virtual ~AbstractTableElement() {
    foreach(AbstractTableElement* tableElement, m_listOfChildren) {
      delete tableElement;
    }
  }

  virtual QString getLatexString()=0;
  virtual QString getTableData()=0;

  int getChildrenCount() const {return m_listOfChildren.count();}
  AbstractTableElement * const at(int index) const {
    Q_ASSERT(m_listOfChildren.count() > index);
    return m_listOfChildren.at(index);
  }

protected:
  void appendChild(AbstractTableElement* child);
  void insertChild(int index, AbstractTableElement* child);
  void removeChild(int index);

protected:
  AbstractTableElement() {}

protected:
  QList<AbstractTableElement* > m_listOfChildren;

};


#endif // _ABSTRACT_TABLE_ELEMENT_H_
