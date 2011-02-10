#include "CsvParser.h"

QSharedPointer<CsvParser> CsvParser::m_csvParser;


QSharedPointer<CsvParser> CsvParser::getInstance() {

  if(m_csvParser.isNull()) {
    m_csvParser = QSharedPointer<CsvParser>(new CsvParser());
  }

  return m_csvParser;
}


TableDataPtr CsvParser::parseCsv(QString csvText) {
  QStringList rows = csvText.split(QRegExp("(\n|\r\n|\r)"));

  QList<QStringList> dataToReturn;

  foreach(QString row, rows) {
    dataToReturn.append(row.split(m_chSeparator));
  }

  return TableDataPtr(new TableData(dataToReturn));
}
