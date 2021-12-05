#include "./datedelegator.h"
#include <QDebug>
#include <iostream>
using namespace std;

QWidget* DateDelegator::createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    if (index.isValid()) {
        // Создаем виджет календаря в ячейке
        QDateEdit* dateEdit = new QDateEdit(parent);
        dateEdit->setCalendarPopup(true);
        dateEdit->setDate(QDate::currentDate());
        dateEdit->setDisplayFormat("dd.MM.yyyy");
        dateEdit->setGeometry(option.rect);
        return dateEdit;
    }
    // Обязательно, для вызова редакторов по умолчанию
    return QItemDelegate::createEditor(parent, option, index);
}

// Инициализируем наш виджет текущим значением
void DateDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.isValid()) {
        QDateEdit* dateEdit = qobject_cast<QDateEdit*>(editor);
        if (dateEdit) {
            // Получаем текущее значение из ячейки
            QDate date = index.data().toDate();
            QString value = date.toString("dd.MM.yyyy");
            return;
        }
    }
    QItemDelegate::setEditorData(editor, index);
}

void DateDelegator::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
    QString value = model->data(index).toDate().toString("dd.MM.yyyy");
    QItemDelegate::setModelData(editor, model, index);
}