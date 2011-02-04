#include "TableModel.h"


#include "CsvParser.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent)
{
  QString csvText = "abc;edf\naaa;sdf";
  QSharedPointer<CsvParser> parser = CsvParser::getInstance();
  m_lstCells = parser->parseCsv(csvText);

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

  if(Qt::DisplayRole == role || Qt::EditRole == role) {
    return getCell(index.row(), index.column());
  }

  return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const {
  if(!index.isValid()) {
    return Qt::ItemIsEnabled;
  }

  return QAbstractTableModel::flags(index)
         | Qt::ItemIsEnabled
         | Qt::ItemIsEditable
         | Qt::ItemIsSelectable;
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role/*=Qt::EditRole*/) {
  if(!index.isValid()) {
    return false;
  }

  if(Qt::EditRole == role) {
    setCell(value.toString(), index.row(), index.column());
    emit dataChanged(index, index);
    return true;
  }

  return false;
}
