#include "TableModel.h"

#include <QString>

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{

  for(int i=0; i<4; i++) {
    QStringList lstStrItems;
    for(int j=0; j<4; j++){
      lstStrItems << QString::number(j);
    }
    m_lstItems.append(lstStrItems);
  }
}

int TableModel::rowCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  return 4;
}

int TableModel::columnCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  return 4;
}

QVariant TableModel::data(const QModelIndex& index, int role /*=Qt::DisplayRole*/) const {
  return m_lstItems.at(index.row()).at(index.column());
}
