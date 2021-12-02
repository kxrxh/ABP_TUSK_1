#ifndef DATEDELEGATOR_H
#define DATEDELEGATOR_H

#include <QString>
#include <QItemDelegate>
#include <QDebug>
#include <QDate>
 
class DateDelegator : public QItemDelegate
{
    Q_OBJECT
public:
 
    QString displayText ( const QVariant & value, const QLocale & locale ) const;
};
#endif