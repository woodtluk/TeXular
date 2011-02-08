#ifndef TABLEDATA_H
#define TABLEDATA_H

#include <QObject>
#include <QList>
#include <QStringList>
#include <QSharedPointer>

#include <QDebug>

class TableData;
typedef QSharedPointer<TableData> TableDataPtr;

class TableData : public QObject
{
    Q_OBJECT
public:
    explicit TableData(QObject *parent = 0);


public:

    int columnCount() const {
      int nColumn = 0;
      foreach(QStringList strList, m_lstCells) {
        nColumn = qMax(nColumn, strList.count());
      }

      return nColumn;
    }

    int rowCount() const {
      return m_lstCells.count();
    }

    QString getCell(int nRowIndex, int nColumnIndex) const {
      Q_ASSERT(m_lstCells.count() > nRowIndex);
      Q_ASSERT(columnCount() > nColumnIndex);
      return m_lstCells.at(nRowIndex).at(nColumnIndex);
    }

    void setCell(QString strText, int nRowIndex, int nColumnIndex) {
      if(m_lstCells.count() <= nRowIndex) {
        appendRows(nRowIndex - m_lstCells.count() + 1);
      }
      Q_ASSERT(m_lstCells.count() > nRowIndex);

      qDebug() << columnCount();
      if(columnCount() <= nColumnIndex) {
        appendColumns(nColumnIndex - columnCount() + 1);
      }
      qDebug() << columnCount();
      Q_ASSERT(columnCount() > nColumnIndex);

      m_lstCells[nRowIndex][nColumnIndex] = strText;
    }

    void appendRow() {
      QStringList lstStrToAppend;
      for(int i=0; i<columnCount(); i++) {
        lstStrToAppend.append("");
      }

      m_lstCells.append(lstStrToAppend);
    }

    void appendRows(int nNumberOfRows) {
      Q_ASSERT(0 <= nNumberOfRows);
      for(int i=0; i<nNumberOfRows; i++) {
        appendRow();
      }
    }

    void appendColumn() {
      for(int i=0; i<m_lstCells.count(); i++) {
        m_lstCells[i].append("");
      }
    }

    void appendColumns(int nNumberOfColumns) {
      Q_ASSERT(0 <= nNumberOfColumns);
      for(int i=0; i<nNumberOfColumns; i++) {
        appendColumn();
      }
    }



signals:

public slots:
  private:
    QList<QStringList> m_lstCells;
};

#endif // TABLEDATA_H
