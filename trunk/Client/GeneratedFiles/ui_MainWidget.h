/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Thu May 26 21:12:08 2011
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWIDGET_H
#define UI_MAINWIDGET_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QListView>
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *m_pUserTab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *m_pUserLayout;
    QListView *listView;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QWidget *m_pProductTab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *m_pUserLayout_2;
    QListView *listView_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QWidget *m_pFactoryTab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *m_pUserLayout_3;
    QListView *listView_3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_9;
    QPushButton *pushButton_10;
    QPushButton *pushButton_11;
    QPushButton *pushButton_12;
    QWidget *m_pPurchaseTab;
    QWidget *m_pReturnTab;
    QWidget *m_pSaleTab;

    void setupUi(QTabWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(628, 445);
        m_pUserTab = new QWidget();
        m_pUserTab->setObjectName(QString::fromUtf8("m_pUserTab"));
        verticalLayout_3 = new QVBoxLayout(m_pUserTab);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        m_pUserLayout = new QVBoxLayout();
        m_pUserLayout->setObjectName(QString::fromUtf8("m_pUserLayout"));
        listView = new QListView(m_pUserTab);
        listView->setObjectName(QString::fromUtf8("listView"));

        m_pUserLayout->addWidget(listView);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        pushButton_2 = new QPushButton(m_pUserTab);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(m_pUserTab);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(m_pUserTab);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        horizontalLayout_2->addWidget(pushButton_4);

        pushButton = new QPushButton(m_pUserTab);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        horizontalLayout_2->addWidget(pushButton);


        m_pUserLayout->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(m_pUserLayout);

        MainWidget->addTab(m_pUserTab, QString());
        m_pProductTab = new QWidget();
        m_pProductTab->setObjectName(QString::fromUtf8("m_pProductTab"));
        verticalLayout_2 = new QVBoxLayout(m_pProductTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_pUserLayout_2 = new QVBoxLayout();
        m_pUserLayout_2->setObjectName(QString::fromUtf8("m_pUserLayout_2"));
        listView_2 = new QListView(m_pProductTab);
        listView_2->setObjectName(QString::fromUtf8("listView_2"));

        m_pUserLayout_2->addWidget(listView_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        pushButton_5 = new QPushButton(m_pProductTab);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        horizontalLayout_3->addWidget(pushButton_5);

        pushButton_6 = new QPushButton(m_pProductTab);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        horizontalLayout_3->addWidget(pushButton_6);

        pushButton_7 = new QPushButton(m_pProductTab);
        pushButton_7->setObjectName(QString::fromUtf8("pushButton_7"));

        horizontalLayout_3->addWidget(pushButton_7);

        pushButton_8 = new QPushButton(m_pProductTab);
        pushButton_8->setObjectName(QString::fromUtf8("pushButton_8"));

        horizontalLayout_3->addWidget(pushButton_8);


        m_pUserLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_2->addLayout(m_pUserLayout_2);

        MainWidget->addTab(m_pProductTab, QString());
        m_pFactoryTab = new QWidget();
        m_pFactoryTab->setObjectName(QString::fromUtf8("m_pFactoryTab"));
        verticalLayout_4 = new QVBoxLayout(m_pFactoryTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_pUserLayout_3 = new QVBoxLayout();
        m_pUserLayout_3->setObjectName(QString::fromUtf8("m_pUserLayout_3"));
        listView_3 = new QListView(m_pFactoryTab);
        listView_3->setObjectName(QString::fromUtf8("listView_3"));

        m_pUserLayout_3->addWidget(listView_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        pushButton_9 = new QPushButton(m_pFactoryTab);
        pushButton_9->setObjectName(QString::fromUtf8("pushButton_9"));

        horizontalLayout_4->addWidget(pushButton_9);

        pushButton_10 = new QPushButton(m_pFactoryTab);
        pushButton_10->setObjectName(QString::fromUtf8("pushButton_10"));

        horizontalLayout_4->addWidget(pushButton_10);

        pushButton_11 = new QPushButton(m_pFactoryTab);
        pushButton_11->setObjectName(QString::fromUtf8("pushButton_11"));

        horizontalLayout_4->addWidget(pushButton_11);

        pushButton_12 = new QPushButton(m_pFactoryTab);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));

        horizontalLayout_4->addWidget(pushButton_12);


        m_pUserLayout_3->addLayout(horizontalLayout_4);


        verticalLayout_4->addLayout(m_pUserLayout_3);

        MainWidget->addTab(m_pFactoryTab, QString());
        m_pPurchaseTab = new QWidget();
        m_pPurchaseTab->setObjectName(QString::fromUtf8("m_pPurchaseTab"));
        MainWidget->addTab(m_pPurchaseTab, QString());
        m_pReturnTab = new QWidget();
        m_pReturnTab->setObjectName(QString::fromUtf8("m_pReturnTab"));
        MainWidget->addTab(m_pReturnTab, QString());
        m_pSaleTab = new QWidget();
        m_pSaleTab->setObjectName(QString::fromUtf8("m_pSaleTab"));
        MainWidget->addTab(m_pSaleTab, QString());

        retranslateUi(MainWidget);

        MainWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QTabWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        pushButton_2->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_3->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_4->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pUserTab), QApplication::translate("MainWidget", "\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        pushButton_5->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_6->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_7->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_8->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pProductTab), QApplication::translate("MainWidget", "\344\272\247\345\223\201", 0, QApplication::UnicodeUTF8));
        pushButton_9->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_10->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_11->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        pushButton_12->setText(QApplication::translate("MainWidget", "PushButton", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pFactoryTab), QApplication::translate("MainWidget", "\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pPurchaseTab), QApplication::translate("MainWidget", "\350\277\233\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pReturnTab), QApplication::translate("MainWidget", "\351\200\200\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pSaleTab), QApplication::translate("MainWidget", "\345\224\256\345\215\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
