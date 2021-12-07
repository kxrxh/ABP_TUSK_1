#ifndef PHONEDELEGATE_H
#define PHONEDELEGATE_H

#include <QItemDelegate>
#include <QLineEdit>
#include <QObject>

class Phonedelegate : public QItemDelegate {
  Q_OBJECT
public:
  Phonedelegate(QObject *parent = 0);

  QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                        const QModelIndex &index) const;

  void setEditorData(QWidget *editor, const QModelIndex &index) const;

  void setModelData(QWidget *editor, QAbstractItemModel *model,
                    const QModelIndex &index) const;

  void updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                            const QModelIndex &index) const;

  QString displayText(const QVariant &value, const QLocale &locale) const;

public slots:
};
#endif // PHONEDELEGATE_H
