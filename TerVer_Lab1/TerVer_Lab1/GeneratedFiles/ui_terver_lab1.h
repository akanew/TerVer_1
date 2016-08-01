/********************************************************************************
** Form generated from reading UI file 'terver_lab1.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TERVER_LAB1_H
#define UI_TERVER_LAB1_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QFrame>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>
#include <QtGui/QSpinBox>
#include <QtGui/QTabWidget>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TerVer_Lab1Class
{
public:
    QWidget *centralWidget;
    QPushButton *Button;
    QTableWidget *Table;
    QPushButton *Button_2;
    QSpinBox *k_widget;
    QPushButton *Create_Table;
    QSpinBox *Table_Height;
    QSpinBox *Table_Width;
    QLabel *label;
    QLabel *label_2;
    QFrame *line;
    QFrame *line_2;
    QFrame *line_3;
    QFrame *line_4;
    QFrame *line_5;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *Sum;
    QFrame *line_6;
    QFrame *line_7;
    QFrame *line_8;
    QFrame *line_9;
    QFrame *line_10;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGraphicsView *Browser_2;
    QGraphicsView *Browser;
    QPushButton *Zoom_Button_1;
    QPushButton *Zoom_Button_2;
    QWidget *tab_2;
    QGraphicsView *Browser_4;
    QGraphicsView *Browser_3;
    QPushButton *Zoom_Button_3;
    QLineEdit *X;
    QLineEdit *D;
    QLineEdit *S;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QFrame *line_11;
    QFrame *line_12;
    QFrame *line_13;
    QFrame *line_14;
    QFrame *line_15;
    QTabWidget *tabWidget_2;
    QWidget *tab_3;
    QTableWidget *Table_2;
    QWidget *tab_4;
    QTableWidget *Table_3;
    QPushButton *Create_Table_2;
    QFrame *line_16;
    QLineEdit *A;
    QLabel *label_8;
    QFrame *line_17;
    QLineEdit *Sigma;
    QLabel *label_9;
    QPlainTextEdit *Text_Task;

    void setupUi(QMainWindow *TerVer_Lab1Class)
    {
        if (TerVer_Lab1Class->objectName().isEmpty())
            TerVer_Lab1Class->setObjectName(QString::fromUtf8("TerVer_Lab1Class"));
        TerVer_Lab1Class->resize(644, 694);
        TerVer_Lab1Class->setMinimumSize(QSize(644, 694));
        TerVer_Lab1Class->setMaximumSize(QSize(644, 694));
        centralWidget = new QWidget(TerVer_Lab1Class);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        Button = new QPushButton(centralWidget);
        Button->setObjectName(QString::fromUtf8("Button"));
        Button->setGeometry(QRect(35, 223, 120, 23));
        Table = new QTableWidget(centralWidget);
        Table->setObjectName(QString::fromUtf8("Table"));
        Table->setGeometry(QRect(12, 32, 618, 182));
        Table->setStyleSheet(QString::fromUtf8("selection-background-color: rgb(255, 255, 255);\n"
"selection-color: rgb(0, 0, 0);"));
        Table->horizontalHeader()->setDefaultSectionSize(60);
        Table->horizontalHeader()->setMinimumSectionSize(27);
        Table->verticalHeader()->setDefaultSectionSize(20);
        Button_2 = new QPushButton(centralWidget);
        Button_2->setObjectName(QString::fromUtf8("Button_2"));
        Button_2->setGeometry(QRect(541, 344, 75, 23));
        k_widget = new QSpinBox(centralWidget);
        k_widget->setObjectName(QString::fromUtf8("k_widget"));
        k_widget->setGeometry(QRect(476, 344, 42, 22));
        Create_Table = new QPushButton(centralWidget);
        Create_Table->setObjectName(QString::fromUtf8("Create_Table"));
        Create_Table->setGeometry(QRect(471, 223, 140, 23));
        Table_Height = new QSpinBox(centralWidget);
        Table_Height->setObjectName(QString::fromUtf8("Table_Height"));
        Table_Height->setGeometry(QRect(421, 223, 42, 22));
        Table_Width = new QSpinBox(centralWidget);
        Table_Width->setObjectName(QString::fromUtf8("Table_Width"));
        Table_Width->setGeometry(QRect(277, 222, 42, 22));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(331, 226, 101, 16));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(181, 226, 101, 16));
        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setGeometry(QRect(160, 219, 20, 31));
        line->setFrameShape(QFrame::VLine);
        line->setFrameShadow(QFrame::Sunken);
        line_2 = new QFrame(centralWidget);
        line_2->setObjectName(QString::fromUtf8("line_2"));
        line_2->setGeometry(QRect(2, 218, 20, 31));
        line_2->setFrameShape(QFrame::VLine);
        line_2->setFrameShadow(QFrame::Sunken);
        line_3 = new QFrame(centralWidget);
        line_3->setObjectName(QString::fromUtf8("line_3"));
        line_3->setGeometry(QRect(11, 211, 620, 16));
        line_3->setFrameShape(QFrame::HLine);
        line_3->setFrameShadow(QFrame::Sunken);
        line_4 = new QFrame(centralWidget);
        line_4->setObjectName(QString::fromUtf8("line_4"));
        line_4->setGeometry(QRect(622, 218, 20, 31));
        line_4->setFrameShape(QFrame::VLine);
        line_4->setFrameShadow(QFrame::Sunken);
        line_5 = new QFrame(centralWidget);
        line_5->setObjectName(QString::fromUtf8("line_5"));
        line_5->setGeometry(QRect(12, 242, 620, 16));
        line_5->setFrameShape(QFrame::HLine);
        line_5->setFrameShadow(QFrame::Sunken);
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(331, 347, 141, 16));
        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(167, 346, 91, 20));
        Sum = new QLineEdit(centralWidget);
        Sum->setObjectName(QString::fromUtf8("Sum"));
        Sum->setGeometry(QRect(260, 345, 51, 20));
        line_6 = new QFrame(centralWidget);
        line_6->setObjectName(QString::fromUtf8("line_6"));
        line_6->setGeometry(QRect(518, 340, 20, 31));
        line_6->setFrameShape(QFrame::VLine);
        line_6->setFrameShadow(QFrame::Sunken);
        line_7 = new QFrame(centralWidget);
        line_7->setObjectName(QString::fromUtf8("line_7"));
        line_7->setGeometry(QRect(11, 332, 620, 16));
        line_7->setFrameShape(QFrame::HLine);
        line_7->setFrameShadow(QFrame::Sunken);
        line_8 = new QFrame(centralWidget);
        line_8->setObjectName(QString::fromUtf8("line_8"));
        line_8->setGeometry(QRect(11, 363, 620, 16));
        line_8->setFrameShape(QFrame::HLine);
        line_8->setFrameShadow(QFrame::Sunken);
        line_9 = new QFrame(centralWidget);
        line_9->setObjectName(QString::fromUtf8("line_9"));
        line_9->setGeometry(QRect(2, 339, 20, 31));
        line_9->setFrameShape(QFrame::VLine);
        line_9->setFrameShadow(QFrame::Sunken);
        line_10 = new QFrame(centralWidget);
        line_10->setObjectName(QString::fromUtf8("line_10"));
        line_10->setGeometry(QRect(620, 340, 20, 31));
        line_10->setFrameShape(QFrame::VLine);
        line_10->setFrameShadow(QFrame::Sunken);
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setGeometry(QRect(11, 406, 621, 285));
        tabWidget->setTabShape(QTabWidget::Triangular);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        Browser_2 = new QGraphicsView(tab);
        Browser_2->setObjectName(QString::fromUtf8("Browser_2"));
        Browser_2->setGeometry(QRect(313, 3, 300, 260));
        Browser = new QGraphicsView(tab);
        Browser->setObjectName(QString::fromUtf8("Browser"));
        Browser->setGeometry(QRect(2, 3, 300, 260));
        Zoom_Button_1 = new QPushButton(tab);
        Zoom_Button_1->setObjectName(QString::fromUtf8("Zoom_Button_1"));
        Zoom_Button_1->setGeometry(QRect(3, 244, 18, 18));
        QIcon icon;
        icon.addFile(QString::fromUtf8("loupe.png"), QSize(), QIcon::Normal, QIcon::Off);
        Zoom_Button_1->setIcon(icon);
        Zoom_Button_1->setIconSize(QSize(16, 16));
        Zoom_Button_2 = new QPushButton(tab);
        Zoom_Button_2->setObjectName(QString::fromUtf8("Zoom_Button_2"));
        Zoom_Button_2->setGeometry(QRect(314, 244, 18, 18));
        Zoom_Button_2->setIcon(icon);
        Zoom_Button_2->setIconSize(QSize(16, 16));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        Browser_4 = new QGraphicsView(tab_2);
        Browser_4->setObjectName(QString::fromUtf8("Browser_4"));
        Browser_4->setGeometry(QRect(313, 3, 300, 260));
        Browser_3 = new QGraphicsView(tab_2);
        Browser_3->setObjectName(QString::fromUtf8("Browser_3"));
        Browser_3->setGeometry(QRect(2, 3, 300, 260));
        Zoom_Button_3 = new QPushButton(tab_2);
        Zoom_Button_3->setObjectName(QString::fromUtf8("Zoom_Button_3"));
        Zoom_Button_3->setGeometry(QRect(314, 244, 18, 18));
        Zoom_Button_3->setIcon(icon);
        Zoom_Button_3->setIconSize(QSize(16, 16));
        tabWidget->addTab(tab_2, QString());
        X = new QLineEdit(centralWidget);
        X->setObjectName(QString::fromUtf8("X"));
        X->setGeometry(QRect(54, 375, 51, 20));
        X->setReadOnly(true);
        D = new QLineEdit(centralWidget);
        D->setObjectName(QString::fromUtf8("D"));
        D->setGeometry(QRect(172, 375, 51, 20));
        D->setReadOnly(true);
        S = new QLineEdit(centralWidget);
        S->setObjectName(QString::fromUtf8("S"));
        S->setGeometry(QRect(289, 375, 51, 20));
        S->setReadOnly(true);
        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(32, 377, 21, 16));
        label_6 = new QLabel(centralWidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(150, 377, 21, 16));
        label_7 = new QLabel(centralWidget);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(265, 377, 21, 16));
        line_11 = new QFrame(centralWidget);
        line_11->setObjectName(QString::fromUtf8("line_11"));
        line_11->setGeometry(QRect(11, 392, 620, 16));
        line_11->setFrameShape(QFrame::HLine);
        line_11->setFrameShadow(QFrame::Sunken);
        line_12 = new QFrame(centralWidget);
        line_12->setObjectName(QString::fromUtf8("line_12"));
        line_12->setGeometry(QRect(2, 370, 20, 31));
        line_12->setFrameShape(QFrame::VLine);
        line_12->setFrameShadow(QFrame::Sunken);
        line_13 = new QFrame(centralWidget);
        line_13->setObjectName(QString::fromUtf8("line_13"));
        line_13->setGeometry(QRect(620, 370, 20, 31));
        line_13->setFrameShape(QFrame::VLine);
        line_13->setFrameShadow(QFrame::Sunken);
        line_14 = new QFrame(centralWidget);
        line_14->setObjectName(QString::fromUtf8("line_14"));
        line_14->setGeometry(QRect(120, 370, 20, 31));
        line_14->setFrameShape(QFrame::VLine);
        line_14->setFrameShadow(QFrame::Sunken);
        line_15 = new QFrame(centralWidget);
        line_15->setObjectName(QString::fromUtf8("line_15"));
        line_15->setGeometry(QRect(235, 370, 20, 31));
        line_15->setFrameShape(QFrame::VLine);
        line_15->setFrameShadow(QFrame::Sunken);
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setGeometry(QRect(11, 256, 621, 79));
        tabWidget_2->setTabShape(QTabWidget::Triangular);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        Table_2 = new QTableWidget(tab_3);
        Table_2->setObjectName(QString::fromUtf8("Table_2"));
        Table_2->setGeometry(QRect(8, 1, 600, 58));
        Table_2->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 255);"));
        Table_2->horizontalHeader()->setDefaultSectionSize(85);
        Table_2->verticalHeader()->setDefaultSectionSize(20);
        tabWidget_2->addTab(tab_3, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        Table_3 = new QTableWidget(tab_4);
        Table_3->setObjectName(QString::fromUtf8("Table_3"));
        Table_3->setGeometry(QRect(8, 1, 600, 58));
        Table_3->setStyleSheet(QString::fromUtf8("selection-color: rgb(0, 0, 0);\n"
"selection-background-color: rgb(255, 255, 255);"));
        Table_3->horizontalHeader()->setDefaultSectionSize(85);
        Table_3->verticalHeader()->setDefaultSectionSize(20);
        tabWidget_2->addTab(tab_4, QString());
        Create_Table_2 = new QPushButton(centralWidget);
        Create_Table_2->setObjectName(QString::fromUtf8("Create_Table_2"));
        Create_Table_2->setGeometry(QRect(20, 344, 140, 23));
        line_16 = new QFrame(centralWidget);
        line_16->setObjectName(QString::fromUtf8("line_16"));
        line_16->setGeometry(QRect(352, 370, 20, 31));
        line_16->setFrameShape(QFrame::VLine);
        line_16->setFrameShadow(QFrame::Sunken);
        A = new QLineEdit(centralWidget);
        A->setObjectName(QString::fromUtf8("A"));
        A->setGeometry(QRect(395, 375, 90, 20));
        A->setReadOnly(true);
        label_8 = new QLabel(centralWidget);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(369, 377, 21, 16));
        line_17 = new QFrame(centralWidget);
        line_17->setObjectName(QString::fromUtf8("line_17"));
        line_17->setGeometry(QRect(486, 370, 20, 31));
        line_17->setFrameShape(QFrame::VLine);
        line_17->setFrameShadow(QFrame::Sunken);
        Sigma = new QLineEdit(centralWidget);
        Sigma->setObjectName(QString::fromUtf8("Sigma"));
        Sigma->setGeometry(QRect(529, 375, 90, 20));
        Sigma->setReadOnly(true);
        label_9 = new QLabel(centralWidget);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(506, 377, 21, 16));
        Text_Task = new QPlainTextEdit(centralWidget);
        Text_Task->setObjectName(QString::fromUtf8("Text_Task"));
        Text_Task->setGeometry(QRect(12, 7, 618, 20));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(10);
        Text_Task->setFont(font);
        TerVer_Lab1Class->setCentralWidget(centralWidget);
        QWidget::setTabOrder(Table, Button);
        QWidget::setTabOrder(Button, Table_Width);
        QWidget::setTabOrder(Table_Width, Table_Height);
        QWidget::setTabOrder(Table_Height, Create_Table);
        QWidget::setTabOrder(Create_Table, tabWidget_2);
        QWidget::setTabOrder(tabWidget_2, Table_2);
        QWidget::setTabOrder(Table_2, Create_Table_2);
        QWidget::setTabOrder(Create_Table_2, Sum);
        QWidget::setTabOrder(Sum, k_widget);
        QWidget::setTabOrder(k_widget, Button_2);
        QWidget::setTabOrder(Button_2, X);
        QWidget::setTabOrder(X, D);
        QWidget::setTabOrder(D, S);
        QWidget::setTabOrder(S, A);
        QWidget::setTabOrder(A, Sigma);
        QWidget::setTabOrder(Sigma, tabWidget);
        QWidget::setTabOrder(tabWidget, Browser);
        QWidget::setTabOrder(Browser, Browser_2);
        QWidget::setTabOrder(Browser_2, Table_3);
        QWidget::setTabOrder(Table_3, Browser_3);
        QWidget::setTabOrder(Browser_3, Browser_4);

        retranslateUi(TerVer_Lab1Class);

        tabWidget->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(TerVer_Lab1Class);
    } // setupUi

    void retranslateUi(QMainWindow *TerVer_Lab1Class)
    {
        TerVer_Lab1Class->setWindowTitle(QApplication::translate("TerVer_Lab1Class", "TerVer_Lab1", 0, QApplication::UnicodeUTF8));
        Button->setText(QApplication::translate("TerVer_Lab1Class", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\270\320\267 \321\204\320\260\320\271\320\273\320\260", 0, QApplication::UnicodeUTF8));
        Button_2->setText(QApplication::translate("TerVer_Lab1Class", "\320\222\321\213\321\207\320\270\321\201\320\273\320\270\321\202\321\214", 0, QApplication::UnicodeUTF8));
        Create_Table->setText(QApplication::translate("TerVer_Lab1Class", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TerVer_Lab1Class", "\320\222\321\213\321\201\320\276\321\202\320\260 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TerVer_Lab1Class", "\320\250\320\270\321\200\320\270\320\275\320\260 \321\202\320\260\320\261\320\273\320\270\321\206\321\213", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TerVer_Lab1Class", "\320\232\320\276\320\273\320\270\321\207\320\265\321\201\321\202\320\262\320\276 \320\270\320\275\321\202\320\265\321\200\320\262\320\260\320\273\320\276\320\262 (K)", 0, QApplication::UnicodeUTF8));
        label_4->setText(QApplication::translate("TerVer_Lab1Class", "\320\241\321\203\320\274\320\274\320\260 \321\207\320\260\321\201\321\202\320\276\321\202 (N)", 0, QApplication::UnicodeUTF8));
        Zoom_Button_1->setText(QString());
        Zoom_Button_2->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("TerVer_Lab1Class", "\320\223\320\270\321\201\321\202\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\270 \320\277\320\276\320\273\320\270\320\263\320\276\320\275 \320\276\321\202\320\275\320\276\321\201\320\270\321\202\320\265\320\273\321\214\320\275\321\213\321\205 \321\207\320\260\321\201\321\202\320\276\321\202 (\321\207\320\260\321\201\321\202\320\276\321\201\321\202\320\265\320\271)", 0, QApplication::UnicodeUTF8));
        Zoom_Button_3->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("TerVer_Lab1Class", " \320\255\320\274\320\277\320\270\321\200\320\270\321\207\320\265\321\201\320\272\320\260\321\217 \321\204\321\203\320\275\320\272\321\206\320\270\321\217 \321\200\320\260\321\201\320\277\321\200\320\265\320\264\320\265\320\273\320\265\320\275\320\270\321\217 \320\270 \320\265\321\221 \320\263\321\200\320\260\321\204\320\270\320\272  ", 0, QApplication::UnicodeUTF8));
        label_5->setText(QApplication::translate("TerVer_Lab1Class", "X =", 0, QApplication::UnicodeUTF8));
        label_6->setText(QApplication::translate("TerVer_Lab1Class", "D =", 0, QApplication::UnicodeUTF8));
        label_7->setText(QApplication::translate("TerVer_Lab1Class", "S =", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_3), QApplication::translate("TerVer_Lab1Class", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273\321\214\320\275\321\213\320\271 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\200\321\217\320\264 \321\207\320\260\321\201\321\202\320\276\321\202", 0, QApplication::UnicodeUTF8));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_4), QApplication::translate("TerVer_Lab1Class", "\320\230\320\275\321\202\320\265\321\200\320\262\320\260\320\273\321\214\320\275\321\213\320\271 \321\201\321\202\320\260\321\202\320\270\321\201\321\202\320\270\321\207\320\265\321\201\320\272\320\270\320\271 \321\200\321\217\320\264 \321\207\320\260\321\201\321\202\320\276\321\201\321\202\320\265\320\271", 0, QApplication::UnicodeUTF8));
        Create_Table_2->setText(QApplication::translate("TerVer_Lab1Class", "\320\241\321\204\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\260\321\202\321\214 \321\202\320\260\320\261\320\273\320\270\321\206\321\203", 0, QApplication::UnicodeUTF8));
        label_8->setText(QApplication::translate("TerVer_Lab1Class", " \316\261 \317\265", 0, QApplication::UnicodeUTF8));
        label_9->setText(QApplication::translate("TerVer_Lab1Class", "\317\203 \317\265", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TerVer_Lab1Class: public Ui_TerVer_Lab1Class {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TERVER_LAB1_H
