#include "./timedelegator.h"

QWidget* TimeDelegator::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        QTimeEdit* timeEdit = new QTimeEdit(parent);
        timeEdit->setCalendarPopup(true);
        timeEdit->setGeometry(option.rect);
        return timeEdit;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void TimeDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.isValid()) {
        QTimeEdit* timeEdit = qobject_cast<QTimeEdit*>(editor);
        if (timeEdit) {
            QString value = index.data().toString();
            QDate date = QDate::fromString(value, "dd.MM.yyyy");
            return;
        }
    }
    QStyledItemDelegate::setEditorData(editor, index);
}
