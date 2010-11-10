#ifndef _ABSTRACT_TABLE_ELEMENT_H_
#define _ABSTRACT_TABLE_ELEMENT_H_

#include <QString>
#include <QList>


class AbstractTableElement {
  /// @todo setters, constructors, copy & assign constructor...
  Q_DISABLE_COPY(AbstractTableElement);

public:
  virtual ~AbstractTableElement() {};

  virtual QString getLatexString()=0;
  virtual QString getTableData()=0;

  void appendChild(AbstractTableElement* child);
  void insertChild(int index, AbstractTableElement* child);
  void removeChild(int index);

protected:
  AbstractTableElement() {};
  QList<AbstractTableElement* > * const getListOfChildren() {return &m_listOfChildren;}

private:
  QList<AbstractTableElement* > m_listOfChildren;

};


#endif // _ABSTRACT_TABLE_ELEMENT_H_
