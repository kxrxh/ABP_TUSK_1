#include "./timedelegator.h"

QWidget* TimeDelegator::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        // Создаем виджет календаря в ячейке
        QTimeEdit* timeEdit = new QTimeEdit(parent);
        timeEdit->setCalendarPopup(true);
        timeEdit->setGeometry(option.rect);
        return timeEdit;
    }
    // Обязательно, для вызова редакторов по умолчанию
    return QStyledItemDelegate::createEditor(parent, option, index);
}

// Инициализируем наш виджет текущим значением
void TimeDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.isValid()) {
        QTimeEdit* timeEdit = qobject_cast<QTimeEdit*>(editor);
        if (timeEdit) {
            // Получаем текущее значение из ячейки
            QString value = index.data().toString();
            QDate date = QDate::fromString(value, "dd.MM.yyyy");
            return;
        }
    }
    QStyledItemDelegate::setEditorData(editor, index);
}
