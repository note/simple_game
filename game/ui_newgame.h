/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created: Tue 27. Jul 15:21:35 2010
**      by: Qt User Interface Compiler version 4.6.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWGAME_H
#define UI_NEWGAME_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFormLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGamePanel
{
public:
    QGroupBox *groupBox_2;
    QGroupBox *groupBox;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QLabel *label;
    QSpinBox *columnsInput;
    QLabel *label_2;
    QLabel *label_3;
    QSpinBox *rowsInput;
    QSpinBox *victoryInput;
    QPushButton *pushButton;

    void setupUi(QWidget *NewGamePanel)
    {
        if (NewGamePanel->objectName().isEmpty())
            NewGamePanel->setObjectName(QString::fromUtf8("NewGamePanel"));
        NewGamePanel->resize(482, 388);
        groupBox_2 = new QGroupBox(NewGamePanel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(80, 30, 331, 271));
        groupBox = new QGroupBox(groupBox_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(20, 30, 291, 111));
        formLayoutWidget = new QWidget(groupBox);
        formLayoutWidget->setObjectName(QString::fromUtf8("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(20, 20, 101, 81));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(formLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        columnsInput = new QSpinBox(formLayoutWidget);
        columnsInput->setObjectName(QString::fromUtf8("columnsInput"));
        columnsInput->setMinimum(2);
        columnsInput->setMaximum(40);
        columnsInput->setValue(7);

        formLayout->setWidget(0, QFormLayout::FieldRole, columnsInput);

        label_2 = new QLabel(formLayoutWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        label_3 = new QLabel(formLayoutWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        rowsInput = new QSpinBox(formLayoutWidget);
        rowsInput->setObjectName(QString::fromUtf8("rowsInput"));
        rowsInput->setMinimum(2);
        rowsInput->setMaximum(40);
        rowsInput->setValue(7);

        formLayout->setWidget(1, QFormLayout::FieldRole, rowsInput);

        victoryInput = new QSpinBox(formLayoutWidget);
        victoryInput->setObjectName(QString::fromUtf8("victoryInput"));
        victoryInput->setMinimum(2);
        victoryInput->setMaximum(40);
        victoryInput->setValue(4);

        formLayout->setWidget(2, QFormLayout::FieldRole, victoryInput);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(30, 160, 75, 23));

        retranslateUi(NewGamePanel);

        QMetaObject::connectSlotsByName(NewGamePanel);
    } // setupUi

    void retranslateUi(QWidget *NewGamePanel)
    {
        NewGamePanel->setWindowTitle(QApplication::translate("NewGamePanel", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NewGamePanel", "New game", 0, QApplication::UnicodeUTF8));
        groupBox->setTitle(QApplication::translate("NewGamePanel", "Board settings", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("NewGamePanel", "Columns:", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("NewGamePanel", "Rows:", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("NewGamePanel", "Victory", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("NewGamePanel", "Play!", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class NewGamePanel: public Ui_NewGamePanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWGAME_H
