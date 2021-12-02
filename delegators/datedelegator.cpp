#include "./datedelegator.h"
 
QString DateDelegator::displayText ( const QVariant & value, const QLocale & locale ) const {
    return value.toDate().toString("dd.MM.yyyy");
}
