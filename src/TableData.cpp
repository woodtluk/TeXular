#include "TableData.h"

TableData::TableData(QObject *parent) :
    QObject(parent)
{
}
TableData::TableData(QObject *parent, QList<QStringList> lstRows) :
    QObject(parent),
    m_lstRows(lstRows)
    {

    }

TableData::TableData(QList<QStringList> lstRows) :
    m_lstRows(lstRows)
    {

    }
