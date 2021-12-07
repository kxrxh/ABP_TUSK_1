#ifndef DATEDELEGATE_H
#define DATEDELEGATE_H

#include <QDateEdit>
#include <QStyledItemDelegate>


class DateDelegate : public QStyledItemDelegate {
  Q_OBJECT
public:
  DateDelegate(QObject *parent = 0);

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;

  void setEditorData(QWidget *editor, const QModelIndex &index) const;

  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const;

  QString displayText(const QVariant &value, const QLocale &locale) const;

  mutable QDateEdit *dataTimeEdit;

public slots:

  void setData(QDate val);
};

#endif
