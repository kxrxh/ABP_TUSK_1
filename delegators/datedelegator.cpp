#include "./datedelegator.h"

QWidget* DateDelegator::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        // Создаем виджет календаря в ячейке
        QDateEdit* dateEdit = new QDateEdit(parent);
        dateEdit->setCalendarPopup(true);
        dateEdit->setGeometry(option.rect);
        return dateEdit;
    }
    // Обязательно, для вызова редакторов по умолчанию
    return QStyledItemDelegate::createEditor(parent, option, index);
}

// Инициализируем наш виджет текущим значением
void DateDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.isValid()) {
        QDateEdit* dateEdit = qobject_cast<QDateEdit*>(editor);
        if (dateEdit) {
            // Получаем текущее значение из ячейки
            QString value = index.data().toString();
            QDate date = QDate::fromString(value, "dd.MM.yyyy");
            return;
        }
    }
    QStyledItemDelegate::setEditorData(editor, index);
}
