#ifndef TIMEDELEGATE_H
#define TIMEDELEGATE_H

#include <QStyledItemDelegate>
#include <QTimeEdit>

class TimeDelegate: public QStyledItemDelegate
{
 Q_OBJECT
public:
    TimeDelegate(QObject *parent = 0);

    QWidget *createEditor( QWidget *parent,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index ) const;

    void setEditorData( QWidget *editor,
                            const QModelIndex &index ) const;

    void setModelData( QWidget *editor,
                            QAbstractItemModel *model,
                            const QModelIndex &index ) const;

    void updateEditorGeometry( QWidget *editor,
                            const QStyleOptionViewItem &option,
                            const QModelIndex &index ) const;

    QString displayText ( const QVariant & value, const QLocale & locale ) const;

    mutable QTimeEdit *dataTimeEdit;

public slots:

    void setData(QTime val);

};

#endif