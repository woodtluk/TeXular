#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include <QString>
#include <QStringList>
#include <QDebug>

#include "TableData.h"

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

public:
  explicit TableModel(TableDataPtr tableData, QObject *parent=0):
      QAbstractTableModel(parent),
      m_tableData(tableData)
  {}
  explicit TableModel(QObject *parent=0);

  ~TableModel();
    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;
    virtual Qt::ItemFlags flags( const QModelIndex & index ) const;
    virtual bool setData(const QModelIndex &index, const QVariant &value, int role=Qt::EditRole);

signals:

public slots:



private:
  TableDataPtr m_tableData;
};

#endif // TABLEMODEL_H
