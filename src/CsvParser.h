#ifndef CSVPARSER_H
#define CSVPARSER_H

#include <QSharedPointer>
#include <QList>
#include <QString>
#include <QStringList>
#include <QChar>

class CsvParser
{
  Q_DISABLE_COPY(CsvParser);

public:
  static QSharedPointer<CsvParser> getInstance();

  QList<QStringList> parseCsv(QString csvText);

private:
  explicit CsvParser() : m_chSeparator(';') {};

    static QSharedPointer<CsvParser> m_csvParser;

    QChar m_chSeparator;
};

#endif // CSVPARSER_H
