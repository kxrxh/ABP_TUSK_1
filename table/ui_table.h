/********************************************************************************
** Form generated from reading UI file 'table.ui'
**
** Created by: Qt User Interface Compiler version 5.15.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TABLE_H
#define UI_TABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Table
{
public:
    QVBoxLayout *verticalLayout;
    QTableWidget *tableWidget;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *newRowLayout;
    QPushButton *addButton;

    void setupUi(QWidget *Table)
    {
        if (Table->objectName().isEmpty())
            Table->setObjectName(QString::fromUtf8("Table"));
        Table->resize(594, 482);
        verticalLayout = new QVBoxLayout(Table);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tableWidget = new QTableWidget(Table);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));

        verticalLayout->addWidget(tableWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        newRowLayout = new QHBoxLayout();
        newRowLayout->setObjectName(QString::fromUtf8("newRowLayout"));

        horizontalLayout->addLayout(newRowLayout);

        addButton = new QPushButton(Table);
        addButton->setObjectName(QString::fromUtf8("addButton"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(addButton->sizePolicy().hasHeightForWidth());
        addButton->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(addButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(Table);

        QMetaObject::connectSlotsByName(Table);
    } // setupUi

    void retranslateUi(QWidget *Table)
    {
        Table->setWindowTitle(QCoreApplication::translate("Table", "Form", nullptr));
        addButton->setText(QCoreApplication::translate("Table", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Table: public Ui_Table {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TABLE_H
