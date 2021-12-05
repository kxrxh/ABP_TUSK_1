#ifndef DATEDELEGATOR_H
#define DATEDELEGATOR_H

#include <QString>
#include <QItemDelegate>
#include <QDateEdit>
#include <QDebug>
#include <QDate>
 
class DateDelegator : public QItemDelegate
{
    Q_OBJECT
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
    void setModelData(QWidget *editor, QAbstractItemModel *model,
                      const QModelIndex &index) const;
};
#endif
