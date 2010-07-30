/********************************************************************************
** Form generated from reading UI file 'newgame.ui'
**
** Created: Fri 30. Jul 14:58:05 2010
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
#include <QtGui/QCheckBox>
#include <QtGui/QFormLayout>
#include <QtGui/QGridLayout>
#include <QtGui/QGroupBox>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewGamePanel
{
public:
    QGroupBox *groupBox_2;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QGroupBox *playersForm;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_4;
    QSpinBox *spinBox;
    QSpinBox *spinBox_2;
    QSpinBox *spinBox_3;
    QSpinBox *spinBox_4;
    QSpinBox *spinBox_5;
    QSpinBox *spinBox_6;
    QSpinBox *spinBox_7;
    QSpinBox *spinBox_8;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QCheckBox *checkBox;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox_3;
    QCheckBox *checkBox_4;
    QWidget *widget;
    QWidget *widget_2;
    QWidget *widget_3;
    QWidget *widget_4;
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
        NewGamePanel->resize(632, 629);
        groupBox_2 = new QGroupBox(NewGamePanel);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 30, 581, 571));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(10);
        sizePolicy.setVerticalStretch(10);
        sizePolicy.setHeightForWidth(groupBox_2->sizePolicy().hasHeightForWidth());
        groupBox_2->setSizePolicy(sizePolicy);
        groupBox_2->setMinimumSize(QSize(5, 5));
        QPalette palette;
        QBrush brush(QColor(0, 255, 0, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush);
        QBrush brush1(QColor(170, 170, 0, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Light, brush1);
        QBrush brush2(QColor(0, 170, 127, 255));
        brush2.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Midlight, brush2);
        QBrush brush3(QColor(170, 0, 0, 255));
        brush3.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::BrightText, brush3);
        QBrush brush4(QColor(85, 255, 127, 255));
        brush4.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush5(QColor(255, 0, 0, 255));
        brush5.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush5);
        QBrush brush6(QColor(0, 85, 0, 255));
        brush6.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::HighlightedText, brush6);
        palette.setBrush(QPalette::Active, QPalette::AlternateBase, brush5);
        QBrush brush7(QColor(170, 0, 127, 255));
        brush7.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::NoRole, brush7);
        QBrush brush8(QColor(85, 255, 0, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Light, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Inactive, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::HighlightedText, brush6);
        palette.setBrush(QPalette::Inactive, QPalette::AlternateBase, brush5);
        palette.setBrush(QPalette::Inactive, QPalette::NoRole, brush7);
        palette.setBrush(QPalette::Inactive, QPalette::ToolTipBase, brush8);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Light, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Midlight, brush2);
        palette.setBrush(QPalette::Disabled, QPalette::BrightText, brush3);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::HighlightedText, brush6);
        palette.setBrush(QPalette::Disabled, QPalette::AlternateBase, brush5);
        palette.setBrush(QPalette::Disabled, QPalette::NoRole, brush7);
        palette.setBrush(QPalette::Disabled, QPalette::ToolTipBase, brush8);
        groupBox_2->setPalette(palette);
        gridLayoutWidget_2 = new QWidget(groupBox_2);
        gridLayoutWidget_2->setObjectName(QString::fromUtf8("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(80, 40, 411, 441));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        playersForm = new QGroupBox(gridLayoutWidget_2);
        playersForm->setObjectName(QString::fromUtf8("playersForm"));
        gridLayoutWidget = new QWidget(playersForm);
        gridLayoutWidget->setObjectName(QString::fromUtf8("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 30, 394, 171));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        QPalette palette1;
        QBrush brush9(QColor(0, 0, 0, 255));
        brush9.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        QBrush brush10(QColor(120, 120, 120, 255));
        brush10.setStyle(Qt::SolidPattern);
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        label_4->setPalette(palette1);

        gridLayout->addWidget(label_4, 0, 2, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        label_5->setPalette(palette2);

        gridLayout->addWidget(label_5, 1, 2, 1, 1);

        label_6 = new QLabel(gridLayoutWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));

        gridLayout->addWidget(label_6, 2, 2, 1, 1);

        label_7 = new QLabel(gridLayoutWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush9);
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush10);
        label_7->setPalette(palette3);

        gridLayout->addWidget(label_7, 3, 2, 1, 1);

        lineEdit = new QLineEdit(gridLayoutWidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        gridLayout->addWidget(lineEdit, 0, 3, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QString::fromUtf8("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 1, 3, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QString::fromUtf8("lineEdit_3"));
        lineEdit_3->setEnabled(false);

        gridLayout->addWidget(lineEdit_3, 2, 3, 1, 1);

        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QString::fromUtf8("lineEdit_4"));
        lineEdit_4->setEnabled(false);

        gridLayout->addWidget(lineEdit_4, 3, 3, 1, 1);

        spinBox = new QSpinBox(gridLayoutWidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setEnabled(true);
        spinBox->setMaximum(59);
        spinBox->setValue(2);

        gridLayout->addWidget(spinBox, 0, 5, 1, 1);

        spinBox_2 = new QSpinBox(gridLayoutWidget);
        spinBox_2->setObjectName(QString::fromUtf8("spinBox_2"));
        spinBox_2->setMaximum(59);
        spinBox_2->setValue(2);

        gridLayout->addWidget(spinBox_2, 1, 5, 1, 1);

        spinBox_3 = new QSpinBox(gridLayoutWidget);
        spinBox_3->setObjectName(QString::fromUtf8("spinBox_3"));
        spinBox_3->setEnabled(false);
        spinBox_3->setMaximum(59);
        spinBox_3->setValue(2);

        gridLayout->addWidget(spinBox_3, 2, 5, 1, 1);

        spinBox_4 = new QSpinBox(gridLayoutWidget);
        spinBox_4->setObjectName(QString::fromUtf8("spinBox_4"));
        spinBox_4->setEnabled(false);
        spinBox_4->setMaximum(59);
        spinBox_4->setValue(2);

        gridLayout->addWidget(spinBox_4, 3, 5, 1, 1);

        spinBox_5 = new QSpinBox(gridLayoutWidget);
        spinBox_5->setObjectName(QString::fromUtf8("spinBox_5"));
        spinBox_5->setMinimum(0);
        spinBox_5->setMaximum(50);
        spinBox_5->setSingleStep(10);
        spinBox_5->setValue(0);

        gridLayout->addWidget(spinBox_5, 0, 7, 1, 1);

        spinBox_6 = new QSpinBox(gridLayoutWidget);
        spinBox_6->setObjectName(QString::fromUtf8("spinBox_6"));
        spinBox_6->setMinimum(0);
        spinBox_6->setMaximum(59);
        spinBox_6->setSingleStep(10);
        spinBox_6->setValue(0);

        gridLayout->addWidget(spinBox_6, 1, 7, 1, 1);

        spinBox_7 = new QSpinBox(gridLayoutWidget);
        spinBox_7->setObjectName(QString::fromUtf8("spinBox_7"));
        spinBox_7->setEnabled(false);
        spinBox_7->setMaximum(50);
        spinBox_7->setSingleStep(10);

        gridLayout->addWidget(spinBox_7, 2, 7, 1, 1);

        spinBox_8 = new QSpinBox(gridLayoutWidget);
        spinBox_8->setObjectName(QString::fromUtf8("spinBox_8"));
        spinBox_8->setEnabled(false);
        spinBox_8->setMaximum(50);
        spinBox_8->setSingleStep(10);

        gridLayout->addWidget(spinBox_8, 3, 7, 1, 1);

        label_8 = new QLabel(gridLayoutWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));

        gridLayout->addWidget(label_8, 0, 4, 1, 1);

        label_9 = new QLabel(gridLayoutWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));

        gridLayout->addWidget(label_9, 1, 4, 1, 1);

        label_10 = new QLabel(gridLayoutWidget);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setEnabled(false);

        gridLayout->addWidget(label_10, 2, 4, 1, 1);

        label_11 = new QLabel(gridLayoutWidget);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setEnabled(false);

        gridLayout->addWidget(label_11, 3, 4, 1, 1);

        label_12 = new QLabel(gridLayoutWidget);
        label_12->setObjectName(QString::fromUtf8("label_12"));

        gridLayout->addWidget(label_12, 0, 6, 1, 1);

        label_13 = new QLabel(gridLayoutWidget);
        label_13->setObjectName(QString::fromUtf8("label_13"));

        gridLayout->addWidget(label_13, 1, 6, 1, 1);

        label_14 = new QLabel(gridLayoutWidget);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setEnabled(false);

        gridLayout->addWidget(label_14, 2, 6, 1, 1);

        label_15 = new QLabel(gridLayoutWidget);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setEnabled(false);

        gridLayout->addWidget(label_15, 3, 6, 1, 1);

        checkBox = new QCheckBox(gridLayoutWidget);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);
        checkBox->setTristate(false);

        gridLayout->addWidget(checkBox, 0, 0, 1, 1);

        checkBox_2 = new QCheckBox(gridLayoutWidget);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        gridLayout->addWidget(checkBox_2, 1, 0, 1, 1);

        checkBox_3 = new QCheckBox(gridLayoutWidget);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));

        gridLayout->addWidget(checkBox_3, 2, 0, 1, 1);

        checkBox_4 = new QCheckBox(gridLayoutWidget);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));

        gridLayout->addWidget(checkBox_4, 3, 0, 1, 1);

        widget = new QWidget(gridLayoutWidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy1);
        widget->setMinimumSize(QSize(10, 10));
        widget->setBaseSize(QSize(10, 10));
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush11(QColor(0, 0, 255, 255));
        brush11.setStyle(Qt::SolidPattern);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush11);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush11);
        widget->setPalette(palette4);
        widget->setAutoFillBackground(true);

        gridLayout->addWidget(widget, 0, 1, 1, 1);

        widget_2 = new QWidget(gridLayoutWidget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));
        sizePolicy1.setHeightForWidth(widget_2->sizePolicy().hasHeightForWidth());
        widget_2->setSizePolicy(sizePolicy1);
        widget_2->setMinimumSize(QSize(10, 10));
        widget_2->setBaseSize(QSize(10, 10));
        widget_2->setAutoFillBackground(true);

        gridLayout->addWidget(widget_2, 1, 1, 1, 1);

        widget_3 = new QWidget(gridLayoutWidget);
        widget_3->setObjectName(QString::fromUtf8("widget_3"));
        sizePolicy1.setHeightForWidth(widget_3->sizePolicy().hasHeightForWidth());
        widget_3->setSizePolicy(sizePolicy1);
        widget_3->setMinimumSize(QSize(10, 10));
        widget_3->setBaseSize(QSize(10, 10));
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::Base, brush4);
        QBrush brush12(QColor(255, 255, 0, 255));
        brush12.setStyle(Qt::SolidPattern);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush12);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush12);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush12);
        widget_3->setPalette(palette5);
        widget_3->setAutoFillBackground(true);

        gridLayout->addWidget(widget_3, 2, 1, 1, 1);

        widget_4 = new QWidget(gridLayoutWidget);
        widget_4->setObjectName(QString::fromUtf8("widget_4"));
        sizePolicy1.setHeightForWidth(widget_4->sizePolicy().hasHeightForWidth());
        widget_4->setSizePolicy(sizePolicy1);
        widget_4->setMinimumSize(QSize(10, 10));
        widget_4->setBaseSize(QSize(10, 10));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::Base, brush4);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush4);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush);
        widget_4->setPalette(palette6);
        widget_4->setAutoFillBackground(true);

        gridLayout->addWidget(widget_4, 3, 1, 1, 1);


        gridLayout_2->addWidget(playersForm, 0, 0, 1, 1);

        groupBox = new QGroupBox(gridLayoutWidget_2);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setMaximumSize(QSize(16777215, 212));
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


        gridLayout_2->addWidget(groupBox, 1, 0, 1, 1);

        pushButton = new QPushButton(groupBox_2);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(80, 500, 81, 23));

        retranslateUi(NewGamePanel);

        QMetaObject::connectSlotsByName(NewGamePanel);
    } // setupUi

    void retranslateUi(QWidget *NewGamePanel)
    {
        NewGamePanel->setWindowTitle(QApplication::translate("NewGamePanel", "Form", 0, QApplication::UnicodeUTF8));
        groupBox_2->setTitle(QApplication::translate("NewGamePanel", "New game", 0, QApplication::UnicodeUTF8));
        playersForm->setTitle(QApplication::translate("NewGamePanel", "Players", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("NewGamePanel", "Player 1:", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("NewGamePanel", "Player 2:", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("NewGamePanel", "Player 3:", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("NewGamePanel", "Player 4:", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("NewGamePanel", "Minutes:", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("NewGamePanel", "Minutes:", 0, QApplication::UnicodeUTF8));
        label_10->setText(QApplication::translate("NewGamePanel", "Minutes:", 0, QApplication::UnicodeUTF8));
        label_11->setText(QApplication::translate("NewGamePanel", "Minutes:", 0, QApplication::UnicodeUTF8));
        label_12->setText(QApplication::translate("NewGamePanel", "Seconds:", 0, QApplication::UnicodeUTF8));
        label_13->setText(QApplication::translate("NewGamePanel", "Seconds", 0, QApplication::UnicodeUTF8));
        label_14->setText(QApplication::translate("NewGamePanel", "Seconds", 0, QApplication::UnicodeUTF8));
        label_15->setText(QApplication::translate("NewGamePanel", "Seconds", 0, QApplication::UnicodeUTF8));
        checkBox->setText(QString());
        checkBox_2->setText(QString());
        checkBox_3->setText(QString());
        checkBox_4->setText(QString());
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
