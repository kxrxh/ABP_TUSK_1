#include "./booldelegator.h"

QWidget* BoolDelegator::createEditor(
    QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index
) const {
    if (index.isValid()) {
        QCheckBox* checkBox = new QCheckBox(parent);
        checkBox->setGeometry(option.rect);
        return checkBox;
    }
    return QStyledItemDelegate::createEditor(parent, option, index);
}

void BoolDelegator::setEditorData(QWidget *editor, const QModelIndex &index) const {
    if (index.isValid()) {
        QCheckBox* checkBox = qobject_cast<QCheckBox*>(editor);
        if (checkBox) {
            QString value = index.data().toString();
            QDate date = QDate::fromString(value, "dd.MM.yyyy");
            return;
        }
    }
    QStyledItemDelegate::setEditorData(editor, index);
}
