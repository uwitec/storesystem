/********************************************************************************
** Form generated from reading UI file 'StoreSystem.ui'
**
** Created: Thu May 26 21:12:08 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STORESYSTEM_H
#define UI_STORESYSTEM_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHeaderView>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QToolBar>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StoreSystemClass
{
public:
    QAction *action;
    QWidget *centralWidget;
    QMenuBar *menuBar;
    QMenu *menu;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *StoreSystemClass)
    {
        if (StoreSystemClass->objectName().isEmpty())
            StoreSystemClass->setObjectName(QString::fromUtf8("StoreSystemClass"));
        StoreSystemClass->resize(600, 400);
        action = new QAction(StoreSystemClass);
        action->setObjectName(QString::fromUtf8("action"));
        centralWidget = new QWidget(StoreSystemClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        StoreSystemClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(StoreSystemClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QString::fromUtf8("menu"));
        StoreSystemClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(StoreSystemClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        StoreSystemClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(StoreSystemClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        StoreSystemClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menu->addAction(action);

        retranslateUi(StoreSystemClass);

        QMetaObject::connectSlotsByName(StoreSystemClass);
    } // setupUi

    void retranslateUi(QMainWindow *StoreSystemClass)
    {
        StoreSystemClass->setWindowTitle(QApplication::translate("StoreSystemClass", "StoreSystem", 0, QApplication::UnicodeUTF8));
        action->setText(QApplication::translate("StoreSystemClass", "\345\205\263\351\227\255", 0, QApplication::UnicodeUTF8));
        menu->setTitle(QApplication::translate("StoreSystemClass", "\346\226\207\344\273\266", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class StoreSystemClass: public Ui_StoreSystemClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STORESYSTEM_H