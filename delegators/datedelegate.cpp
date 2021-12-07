#include "./datedelegate.h"

DateDelegate::DateDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *DateDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const {
  dataTimeEdit = new QDateEdit(parent);
  QObject::connect(dataTimeEdit, SIGNAL(dateChanged(QDate)), this,
                   SLOT(setData(QDate)));
  return dataTimeEdit;
}

void DateDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const {
  QVariant dateTime = index.model()->data(index, Qt::DisplayRole);

  (static_cast<QDateEdit *>(editor))->setDate(dateTime.toDate());
}

void DateDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const {
  model->setData(index, static_cast<QDateEdit *>(editor)->dateTime());
}

void DateDelegate::updateEditorGeometry(QWidget *editor,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const {
  editor->setGeometry(option.rect);
}

void DateDelegate::setData(QDate val) { emit commitData(dataTimeEdit); }
QString DateDelegate::displayText(const QVariant &value,
                                  const QLocale &locale) const {
  return QStyledItemDelegate::displayText(value.toDate().toString("dd.MM.yyyy"),
                                          locale);
}
