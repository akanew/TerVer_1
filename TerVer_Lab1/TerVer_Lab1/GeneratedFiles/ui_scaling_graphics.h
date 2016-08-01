/********************************************************************************
** Form generated from reading UI file 'scaling_graphics.ui'
**
** Created by: Qt User Interface Compiler version 4.8.5
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SCALING_GRAPHICS_H
#define UI_SCALING_GRAPHICS_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QGraphicsView>
#include <QtGui/QHeaderView>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Scaling_Graphics
{
public:
    QGraphicsView *graphicsView;

    void setupUi(QWidget *Scaling_Graphics)
    {
        if (Scaling_Graphics->objectName().isEmpty())
            Scaling_Graphics->setObjectName(QString::fromUtf8("Scaling_Graphics"));
        Scaling_Graphics->resize(621, 538);
        graphicsView = new QGraphicsView(Scaling_Graphics);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(10, 10, 600, 520));

        retranslateUi(Scaling_Graphics);

        QMetaObject::connectSlotsByName(Scaling_Graphics);
    } // setupUi

    void retranslateUi(QWidget *Scaling_Graphics)
    {
        Scaling_Graphics->setWindowTitle(QApplication::translate("Scaling_Graphics", "Scaling_Graphics", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Scaling_Graphics: public Ui_Scaling_Graphics {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SCALING_GRAPHICS_H
