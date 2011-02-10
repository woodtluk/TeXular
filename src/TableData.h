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
    Q_DISABLE_COPY(TableData)

public:
    explicit TableData(QObject *parent = 0);
    TableData(QList<QStringList> lstRows);
    TableData(QObject *parent, QList<QStringList> lstRows);

    ~TableData() {}

public:

    int columnCount() const {
      int nColumn = 0;
      foreach(QStringList strList, m_lstRows) {
        nColumn = qMax(nColumn, strList.count());
      }

      return nColumn;
    }

    int rowCount() const {
      return m_lstRows.count();
    }

    QString getCell(int nRowIndex, int nColumnIndex) const {
      Q_ASSERT(m_lstRows.count() > nRowIndex);
      Q_ASSERT(columnCount() > nColumnIndex);
      return m_lstRows.at(nRowIndex).at(nColumnIndex);
    }

    void setCell(QString strText, int nRowIndex, int nColumnIndex) {
      if(m_lstRows.count() <= nRowIndex) {
        appendRows(nRowIndex - m_lstRows.count() + 1);
      }
      Q_ASSERT(m_lstRows.count() > nRowIndex);

      qDebug() << columnCount();
      if(columnCount() <= nColumnIndex) {
        appendColumns(nColumnIndex - columnCount() + 1);
      }
      qDebug() << columnCount();
      Q_ASSERT(columnCount() > nColumnIndex);

      m_lstRows[nRowIndex][nColumnIndex] = strText;
    }

    void appendRow() {
      QStringList lstStrToAppend;
      for(int i=0; i<columnCount(); i++) {
        lstStrToAppend.append("");
      }

      m_lstRows.append(lstStrToAppend);
    }

    void appendRows(int nNumberOfRows) {
      Q_ASSERT(0 <= nNumberOfRows);
      for(int i=0; i<nNumberOfRows; i++) {
        appendRow();
      }
    }

    void appendColumn() {
      for(int i=0; i<m_lstRows.count(); i++) {
        m_lstRows[i].append("");
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
    QList<QStringList> m_lstRows;
};

#endif // TABLEDATA_H
