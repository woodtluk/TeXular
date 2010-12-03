#include "TableModel.h"

#include "TableElement.h"

TableModel::TableModel(QObject *parent) :
    QAbstractTableModel(parent),
    m_pTableData(new TableElement())
{

  for(int i=0; i<4; i++) {
    m_pTableData->appendRow(new TableRowElement(5));
  }

}

TableModel::~TableModel() {
  delete m_pTableData;
}

int TableModel::rowCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  return m_pTableData->rowCount();
}

int TableModel::columnCount(const QModelIndex& parent /*=QModelIndex()*/) const {
  return m_pTableData->columnCount();
}

QVariant TableModel::data(const QModelIndex& index, int role /*=Qt::DisplayRole*/) const {
  return m_pTableData->at(index.row())->at(index.column())->getTableData();
}
