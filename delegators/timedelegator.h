#ifndef TIMEDELEGATOR_H
#define TIMEDELEGATOR_H

#include <QString>
#include <QStyledItemDelegate>
#include <QTimeEdit>
#include <QDebug>
#include <QDate>
 
class TimeDelegator : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};
#endif