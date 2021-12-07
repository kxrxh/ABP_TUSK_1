#include "./timedelegate.h"

TimeDelegate::TimeDelegate(QObject *parent) : QStyledItemDelegate(parent) {}

QWidget *TimeDelegate::createEditor(QWidget *parent,
                                    const QStyleOptionViewItem &option,
                                    const QModelIndex &index) const {
  dataTimeEdit = new QTimeEdit(parent);
  QObject::connect(dataTimeEdit, SIGNAL(timeChanged(QTime)), this,
                   SLOT(setData(QTime)));
  return dataTimeEdit;
}

void TimeDelegate::setEditorData(QWidget *editor,
                                 const QModelIndex &index) const {
  QVariant timeTime = index.model()->data(index, Qt::DisplayRole);

  (static_cast<QTimeEdit *>(editor))->setTime(timeTime.toTime());
}

void TimeDelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                const QModelIndex &index) const {
  model->setData(index, static_cast<QTimeEdit *>(editor)->time());
}

void TimeDelegate::updateEditorGeometry(QWidget *editor,
                                        const QStyleOptionViewItem &option,
                                        const QModelIndex &index) const {
  editor->setGeometry(option.rect);
}

void TimeDelegate::setData(QTime val) { emit commitData(dataTimeEdit); }
QString TimeDelegate::displayText(const QVariant &value,
                                  const QLocale &locale) const {
  return QStyledItemDelegate::displayText(value.toTime().toString("hh:mm"),
                                          locale);
}
