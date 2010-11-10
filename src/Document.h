#ifndef DOCUMENT_H
#define DOCUMENT_H

#include <QObject>

#include "TableElement.h"

class Document
{
  Q_DISABLE_COPY(Document);
public:
  Document();

private:
  TableElement m_tableElement;
};

#endif // DOCUMENT_H
