#include "./datedelegator.h"
 
QString DateDelegator::displayText ( const QVariant & value, const QLocale & locale ) const {
    return QStyledItemDelegate::displayText(value.toDate().toString("dd.MM.yyyy"), locale);
}
