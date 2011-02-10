#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <QSharedPointer>
#include <QList>
#include <QString>
#include <QStringList>
#include <QChar>

#include "TableData.h"

class CsvParser
{
  Q_DISABLE_COPY(CsvParser);

public:
  static QSharedPointer<CsvParser> getInstance();

  TableDataPtr parseCsv(QString csvText);

private:
  explicit CsvParser() : m_chSeparator(';') {};

    static QSharedPointer<CsvParser> m_csvParser;

    QChar m_chSeparator;
};

#endif // CSVPARSER_H
