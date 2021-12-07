#include "phonedelegate.h"

Phonedelegate::Phonedelegate(QObject *parent) : QItemDelegate(parent) {}

QWidget *Phonedelegate::createEditor(QWidget *parent,
                                     const QStyleOptionViewItem & /* option */,
                                     const QModelIndex & /* index */) const {
  QLineEdit *editor = new QLineEdit(parent);

  return editor;
}

void Phonedelegate::setEditorData(QWidget *editor,
                                  const QModelIndex &index) const {
  QString value = index.model()->data(index, Qt::EditRole).toString();

  QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);
  lineEdit->setInputMask("8-000-000-00-00");
  lineEdit->setText(value);
}

void Phonedelegate::setModelData(QWidget *editor, QAbstractItemModel *model,
                                 const QModelIndex &index) const {
  QLineEdit *lineEdit = static_cast<QLineEdit *>(editor);
  //    lineEdit->returnPressed();
  lineEdit->setInputMask("8-000-000-00-00");
  QString value = lineEdit->text();

  model->setData(index, value, Qt::EditRole);
}

void Phonedelegate::updateEditorGeometry(
    QWidget *editor, const QStyleOptionViewItem &option,
    const QModelIndex & /* index */) const {
  editor->setGeometry(option.rect);
}
