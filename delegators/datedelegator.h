#ifndef DATEDELEGATOR_H
#define DATEDELEGATOR_H

#include <QString>
#include <QStyledItemDelegate>
#include <QDebug>
#include <QDate>
 
class DateDelegator : public QStyledItemDelegate
{
    Q_OBJECT
public:
 
    QString displayText ( const QVariant & value, const QLocale & locale ) const;
};
#endif