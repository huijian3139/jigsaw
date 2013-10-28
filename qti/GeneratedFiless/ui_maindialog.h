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
        MainDialog->setWindowTitle(QApplication::translate("MainDialog", "\346\213\274\345\233\276\346\270\270\346\210\217", 0));
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
        labelsrc->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\345\216\237\345\247\213\345\233\276\347\211\207</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelsrc->setText(QString());
#ifndef QT_NO_TOOLTIP
        vediolabel->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\346\221\204\345\203\217\345\244\264\345\233\276\345\203\217</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        vediolabel->setText(QApplication::translate("MainDialog", "TextLabel", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonHelp->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\350\216\267\345\276\227\345\270\256\345\212\251</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonHelp->setText(QApplication::translate("MainDialog", "\345\270\256\345\212\251", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonLoadImg->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\351\200\211\346\213\251\344\270\200\345\274\240\344\275\240\346\203\263\350\246\201\346\213\274\347\232\204\345\233\276\347\211\207</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonLoadImg->setText(QApplication::translate("MainDialog", "\351\200\211\346\213\251\345\233\276\347\211\207", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonClear->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\351\232\217\346\234\272\346\216\222\345\210\227\346\226\271\345\235\227\344\275\215\347\275\256</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonClear->setText(QApplication::translate("MainDialog", "\351\207\215\347\275\256\344\275\215\347\275\256", 0));
#ifndef QT_NO_TOOLTIP
        pushButtonExit->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\347\202\271\345\207\273\351\200\200\345\207\272\346\270\270\346\210\217</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        pushButtonExit->setText(QApplication::translate("MainDialog", "\351\200\200\345\207\272", 0));
#ifndef QT_NO_TOOLTIP
        labelMove->setToolTip(QApplication::translate("MainDialog", "<html><head/><body><p>\350\277\231\346\230\257\344\275\240\347\247\273\345\212\250\347\232\204\346\255\245\346\225\260\357\274\214\350\266\212\345\260\221\350\266\212\345\245\275</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        labelMove->setText(QApplication::translate("MainDialog", "\347\247\273\345\212\250\346\254\241\346\225\260:", 0));
        labelnum->setText(QApplication::translate("MainDialog", "0", 0));
    } // retranslateUi

};

namespace Ui {
    class MainDialog: public Ui_MainDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINDIALOG_H
