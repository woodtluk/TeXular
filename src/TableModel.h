#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include <QString>
#include <QStringList>
#include <QDebug>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT


public:
    explicit TableModel(QObject *parent = 0);
    virtual ~TableModel();

    QString getCell(int nRowIndex, int nColumnIndex) const {
      Q_ASSERT(m_lstCells.count() > nRowIndex);
      Q_ASSERT(columnCount() > nColumnIndex);
      return m_lstCells.at(nRowIndex).at(nColumnIndex);
    }

    void setCell(QString strText, int nRowIndex, int nColumnIndex) {
      if(rowCount() <= nRowIndex) {
        appendRows(nRowIndex - rowCount() + 1);
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

    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags ( const QModelIndex & index ) const;

signals:

public slots:



private:
  QList<QStringList> m_lstCells;


};

#endif // TABLEMODEL_H
