#ifndef BOOLDELEGATOR_H
#define BOOLDELEGATOR_H

#include <QString>
#include <QStyledItemDelegate>
#include <QCheckBox>
#include <QDebug>
#include <QDate>
 
class BoolDelegator : public QStyledItemDelegate
{
    Q_OBJECT
public:
    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const;
    void setEditorData(QWidget *editor, const QModelIndex &index) const;
};
#endif