/********************************************************************************
** Form generated from reading UI file 'maindialog.ui'
**
** Created by: Qt User Interface Compiler version 5.0.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINDIALOG_H
#define UI_MAINDIALOG_H

#include <MyLabel.h>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainDialog
{
public:
    MyLabel *label_0;
    MyLabel *label_1;
    MyLabel *label_2;
    MyLabel *label_4;
    MyLabel *label_5;
    MyLabel *label_3;
    MyLabel *label_7;
    MyLabel *label_8;
    MyLabel *label_6;
    QWidget *widget;
    QLabel *labelsrc;
    QLabel *vediolabel;
    QPushButton *pushButtonHelp;
    QPushButton *pushButtonLoadImg;
    QPushButton *pushButtonClear;
    QPushButton *pushButtonExit;
    QLabel *labelMove;
    QLabel *labelnum;

    void setupUi(QDialog *MainDialog)
    {
        if (MainDialog->objectName().isEmpty())
            MainDialog->setObjectName(QStringLiteral("MainDialog"));
        MainDialog->resize(593, 685);
        MainDialog->setWindowOpacity(1);
        MainDialog->setAutoFillBackground(true);
        label_0 = new MyLabel(MainDialog);
        label_0->setObjectName(QStringLiteral("label_0"));
        label_0->setGeometry(QRect(0, 20, 100, 100));
        label_1 = new MyLabel(MainDialog);
        label_1->setObjectName(QStringLiteral("label_1"));
        label_1->setGeometry(QRect(100, 20, 100, 100));
        label_2 = new MyLabel(MainDialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(200, 20, 100, 100));
        label_4 = new MyLabel(MainDialog);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(100, 120, 100, 100));
        label_5 = new MyLabel(MainDialog);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(200, 120, 100, 100));
        label_3 = new MyLabel(MainDialog);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(0, 120, 100, 100));
        label_7 = new MyLabel(MainDialog);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(100, 220, 100, 100));
        label_8 = new MyLabel(MainDialog);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(200, 220, 100, 100));
        label_6 = new MyLabel(MainDialog);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(0, 220, 100, 100));
        widget = new QWidget(MainDialog);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 490, 301, 100));
        labelsrc = new QLabel(MainDialog);
        labelsrc->setObjectName(QStringLiteral("labelsrc"));
        labelsrc->setGeometry(QRect(300, 20, 291, 301));
        vediolabel = new QLabel(MainDialog);
        vediolabel->setObjectName(QStringLiteral("vediolabel"));
        vediolabel->setGeometry(QRect(40, 320, 511, 361));
        pushButtonHelp = new QPushButton(MainDialog);
        pushButtonHelp->setObjectName(QStringLiteral("pushButtonHelp"));
        pushButtonHelp->setGeometry(QRect(160, 0, 75, 23));
        pushButtonLoadImg = new QPushButton(MainDialog);
        pushButtonLoadImg->setObjectName(QStringLiteral("pushButtonLoadImg"));
        pushButtonLoadImg->setGeometry(QRect(0, 0, 75, 23));
        pushButtonLoadImg->setMaximumSize(QSize(16777215, 31));
        pushButtonClear = new QPushButton(MainDialog);
        pushButtonClear->setObjectName(QStringLiteral("pushButtonClear"));
        pushButtonClear->setGeometry(QRect(80, 0, 75, 23));
        pushButtonExit = new QPushButton(MainDialog);
        pushButtonExit->setObjectName(QStringLiteral("pushButtonExit"));
        pushButtonExit->setGeometry(QRect(240, 0, 75, 23));
        pushButtonExit->setAutoDefault(true);
        pushButtonExit->setDefault(false);
        pushButtonExit->setFlat(false);
        labelMove = new QLabel(MainDialog);
        labelMove->setObjectName(QStringLiteral("labelMove"));
        labelMove->setGeometry(QRect(340, 0, 61, 31));
        labelnum = new QLabel(MainDialog);
        labelnum->setObjectName(QStringLiteral("labelnum"));
        labelnum->setGeometry(QRect(400, 0, 51, 31));

        retranslateUi(MainDialog);

        QMetaObject::connectSlotsByName(MainDialog);
    } // setupUi

    void retranslateUi(QDialog *MainDialog)
    {
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "Jigsaw", 0));
        label_0->setText(QApplication::translate("MainDialog", "          0", 0));
        label_1->setText(QApplication::translate("MainDialog", "          1", 0));
        label_2->setText(QApplication::translate("MainDialog", "          2", 0));
        label_4->setText(QApplication::translate("MainDialog", "          4", 0));
        label_5->setText(QApplication::translate("MainDialog", "          5", 0));
        label_3->setText(QApplication::translate("MainDialog", "          3", 0));
        label_7->setText(QApplication::translate("MainDialog", "          7", 0));
        label_8->setText(QApplication::translate("MainDialog", "          8", 0));
        label_6->setText(QApplication::translate("MainDialog", "          6", 0));
#ifndef QT_NO_TOOLTIP
        labelsrc->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>Original picture</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelsrc->setText(QString());
#ifndef QT_NO_TOOLTIP
        vediolabel->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>This is the vedio area</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        vediolabel->setText(QApplication::translate("MainDialog", "Camera loading", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonHelp->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>get help</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonHelp->setText(QApplication::translate("MainDialog", "Help", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonLoadImg->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>select one picture you want</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonLoadImg->setText(QApplication::translate("MainDialog", "Select Picture", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonClear->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>array the positions randomly</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonClear->setText(QApplication::translate("MainDialog", "Reset Jigsaw", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonExit->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>click to quit the game</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonExit->setText(QApplication::translate("MainDialog", "Quit", 0));
#ifndef QT_NO_TOOLTIP
        labelMove->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>The less steps you use, the better skill you have</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelMove->setText(QApplication::translate("MainDialog", "Step", 0));
        labelnum->setText(QApplication::translate("MainDialog", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
