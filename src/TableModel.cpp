#include "TableModel.h"


TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{

  for(int i=0; i<4; i++) {
    for(int j=0; j<5; j++)
    {
      setCell("abc", i, j);
    }
  }

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex& parent /*=QModelIndex()*/) const {
 return m_lstCells.count();
}

int TableModel::columnCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  int nColumnCount = 0;
  foreach(QStringList row, m_lstCells) {
    nColumnCount = qMax(row.count(), nColumnCount);
  }

  return nColumnCount;
}

QVariant TableModel::data(const QModelIndex& index, int role /*=Qt::DisplayRole*/) const {
  if(!index.isValid()) {
    return QVariant();
  }

  if(Qt::DisplayRole == role) {
    return getCell(index.row(), index.column());
  }

  return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
  if(index.isValid()) {
    return Qt::ItemIsEnabled;
  }

  return QAbstractItemModel::flags(index)
         | Qt::ItemIsEnabled
         | Qt::ItemIsEditable
         | Qt::ItemIsSelectable;
}
