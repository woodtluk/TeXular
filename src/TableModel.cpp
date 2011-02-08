#include "TableModel.h"


#include "CsvParser.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent),
    m_tableData(new TableData)
{
  QString csvText = "abc;edf\naaa;sdf";
  QSharedPointer<CsvParser> parser = CsvParser::getInstance();
  //m_tableData = parser->parseCsv(csvText);

}

TableModel::~TableModel() {

}

int TableModel::rowCount(const QModelIndex& parent /*=QModelIndex()*/) const {
 return m_tableData->rowCount();
}

int TableModel::columnCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  return m_tableData->columnCount();
}

QVariant TableModel::data(const QModelIndex& index, int role /*=Qt::DisplayRole*/) const {
  if(!index.isValid()) {
    return QVariant();
  }

  if(Qt::DisplayRole == role || Qt::EditRole == role) {
    return m_tableData->getCell(index.row(), index.column());
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
    m_tableData->setCell(value.toString(), index.row(), index.column());
    emit dataChanged(index, index);
    return true;
  }

  return false;
}
