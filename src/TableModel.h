#ifndef TABLEMODEL_H
#define TABLEMODEL_H

#include <QAbstractTableModel>

#include <QList>
#include <QStringList>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT
public:
    explicit TableModel(QObject *parent = 0);


    int rowCount(const QModelIndex& parent = QModelIndex()) const;
    int columnCount(const QModelIndex& parent = QModelIndex()) const;
    QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const;

signals:

public slots:

private:
    QList< QStringList>  m_lstItems;

};

#endif // TABLEMODEL_H
