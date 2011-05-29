/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Sun May 29 00:08:43 2011
**      by: Qt User Interface Compiler version 4.7.3
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
#include <QtGui/QPushButton>
#include <QtGui/QTabWidget>
#include <QtGui/QTreeView>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWidget
{
public:
    QWidget *m_pUserTab;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *m_pUserLayout;
    QTreeView *m_pUserView;
    QHBoxLayout *m_pUserHLayout;
    QPushButton *m_pUserAddBtn;
    QPushButton *m_pUserSelBtn;
    QPushButton *m_pUserUpdBtn;
    QPushButton *m_pUserDelBtn;
    QWidget *m_pProductTab;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *m_pProductLayout;
    QTreeView *m_pProductView;
    QHBoxLayout *m_pProductHLayout;
    QPushButton *m_pProductAddBtn;
    QPushButton *m_pProductSelBtn;
    QPushButton *m_pProductUpdBtn;
    QPushButton *m_pProductDelBtn;
    QWidget *m_pFactoryTab;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *m_pFactoryLayout;
    QTreeView *m_pFactoryView;
    QHBoxLayout *m_pFactoryHLayout;
    QPushButton *m_pFactoryAddBtn;
    QPushButton *m_pFactorySelBtn;
    QPushButton *m_pFactoryUpdBtn;
    QPushButton *m_pFactoryDelBtn;
    QWidget *m_pPurchaseTab;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *m_pPurchaseLayout;
    QTreeView *m_pPurchaseView;
    QHBoxLayout *m_pPurchaseHLayout;
    QPushButton *m_pPurchaseAddBtn;
    QPushButton *m_pPurchaseSelBtn;
    QPushButton *m_pPurchaseUpdBtn;
    QPushButton *m_pPurchaseDelBtn;
    QWidget *m_pReturnTab;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *m_pReturnLayout;
    QTreeView *m_pReturnView;
    QHBoxLayout *m_pReturnHLayout;
    QPushButton *m_pReturnAddBtn;
    QPushButton *m_pReturnSelBtn;
    QPushButton *m_pReturnUpdBtn;
    QPushButton *m_pReturnDelBtn;
    QWidget *m_pSaleTab;
    QVBoxLayout *verticalLayout_6;
    QVBoxLayout *m_pSaleLayout;
    QTreeView *m_pSaleView;
    QHBoxLayout *m_pSaleHLayout;
    QPushButton *m_pSaleAddBtn;
    QPushButton *m_pSaleSelBtn;
    QPushButton *m_pSaleUpdBtn;
    QPushButton *m_pSaleDelBtn;

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
        m_pUserView = new QTreeView(m_pUserTab);
        m_pUserView->setObjectName(QString::fromUtf8("m_pUserView"));

        m_pUserLayout->addWidget(m_pUserView);

        m_pUserHLayout = new QHBoxLayout();
        m_pUserHLayout->setObjectName(QString::fromUtf8("m_pUserHLayout"));
        m_pUserAddBtn = new QPushButton(m_pUserTab);
        m_pUserAddBtn->setObjectName(QString::fromUtf8("m_pUserAddBtn"));

        m_pUserHLayout->addWidget(m_pUserAddBtn);

        m_pUserSelBtn = new QPushButton(m_pUserTab);
        m_pUserSelBtn->setObjectName(QString::fromUtf8("m_pUserSelBtn"));

        m_pUserHLayout->addWidget(m_pUserSelBtn);

        m_pUserUpdBtn = new QPushButton(m_pUserTab);
        m_pUserUpdBtn->setObjectName(QString::fromUtf8("m_pUserUpdBtn"));

        m_pUserHLayout->addWidget(m_pUserUpdBtn);

        m_pUserDelBtn = new QPushButton(m_pUserTab);
        m_pUserDelBtn->setObjectName(QString::fromUtf8("m_pUserDelBtn"));

        m_pUserHLayout->addWidget(m_pUserDelBtn);


        m_pUserLayout->addLayout(m_pUserHLayout);


        verticalLayout_3->addLayout(m_pUserLayout);

        MainWidget->addTab(m_pUserTab, QString());
        m_pProductTab = new QWidget();
        m_pProductTab->setObjectName(QString::fromUtf8("m_pProductTab"));
        verticalLayout_2 = new QVBoxLayout(m_pProductTab);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        m_pProductLayout = new QVBoxLayout();
        m_pProductLayout->setObjectName(QString::fromUtf8("m_pProductLayout"));
        m_pProductView = new QTreeView(m_pProductTab);
        m_pProductView->setObjectName(QString::fromUtf8("m_pProductView"));

        m_pProductLayout->addWidget(m_pProductView);

        m_pProductHLayout = new QHBoxLayout();
        m_pProductHLayout->setObjectName(QString::fromUtf8("m_pProductHLayout"));
        m_pProductAddBtn = new QPushButton(m_pProductTab);
        m_pProductAddBtn->setObjectName(QString::fromUtf8("m_pProductAddBtn"));

        m_pProductHLayout->addWidget(m_pProductAddBtn);

        m_pProductSelBtn = new QPushButton(m_pProductTab);
        m_pProductSelBtn->setObjectName(QString::fromUtf8("m_pProductSelBtn"));

        m_pProductHLayout->addWidget(m_pProductSelBtn);

        m_pProductUpdBtn = new QPushButton(m_pProductTab);
        m_pProductUpdBtn->setObjectName(QString::fromUtf8("m_pProductUpdBtn"));

        m_pProductHLayout->addWidget(m_pProductUpdBtn);

        m_pProductDelBtn = new QPushButton(m_pProductTab);
        m_pProductDelBtn->setObjectName(QString::fromUtf8("m_pProductDelBtn"));

        m_pProductHLayout->addWidget(m_pProductDelBtn);


        m_pProductLayout->addLayout(m_pProductHLayout);


        verticalLayout_2->addLayout(m_pProductLayout);

        MainWidget->addTab(m_pProductTab, QString());
        m_pFactoryTab = new QWidget();
        m_pFactoryTab->setObjectName(QString::fromUtf8("m_pFactoryTab"));
        verticalLayout_4 = new QVBoxLayout(m_pFactoryTab);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        m_pFactoryLayout = new QVBoxLayout();
        m_pFactoryLayout->setObjectName(QString::fromUtf8("m_pFactoryLayout"));
        m_pFactoryView = new QTreeView(m_pFactoryTab);
        m_pFactoryView->setObjectName(QString::fromUtf8("m_pFactoryView"));

        m_pFactoryLayout->addWidget(m_pFactoryView);

        m_pFactoryHLayout = new QHBoxLayout();
        m_pFactoryHLayout->setObjectName(QString::fromUtf8("m_pFactoryHLayout"));
        m_pFactoryAddBtn = new QPushButton(m_pFactoryTab);
        m_pFactoryAddBtn->setObjectName(QString::fromUtf8("m_pFactoryAddBtn"));

        m_pFactoryHLayout->addWidget(m_pFactoryAddBtn);

        m_pFactorySelBtn = new QPushButton(m_pFactoryTab);
        m_pFactorySelBtn->setObjectName(QString::fromUtf8("m_pFactorySelBtn"));

        m_pFactoryHLayout->addWidget(m_pFactorySelBtn);

        m_pFactoryUpdBtn = new QPushButton(m_pFactoryTab);
        m_pFactoryUpdBtn->setObjectName(QString::fromUtf8("m_pFactoryUpdBtn"));

        m_pFactoryHLayout->addWidget(m_pFactoryUpdBtn);

        m_pFactoryDelBtn = new QPushButton(m_pFactoryTab);
        m_pFactoryDelBtn->setObjectName(QString::fromUtf8("m_pFactoryDelBtn"));

        m_pFactoryHLayout->addWidget(m_pFactoryDelBtn);


        m_pFactoryLayout->addLayout(m_pFactoryHLayout);


        verticalLayout_4->addLayout(m_pFactoryLayout);

        MainWidget->addTab(m_pFactoryTab, QString());
        m_pPurchaseTab = new QWidget();
        m_pPurchaseTab->setObjectName(QString::fromUtf8("m_pPurchaseTab"));
        verticalLayout = new QVBoxLayout(m_pPurchaseTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_pPurchaseLayout = new QVBoxLayout();
        m_pPurchaseLayout->setObjectName(QString::fromUtf8("m_pPurchaseLayout"));
        m_pPurchaseView = new QTreeView(m_pPurchaseTab);
        m_pPurchaseView->setObjectName(QString::fromUtf8("m_pPurchaseView"));

        m_pPurchaseLayout->addWidget(m_pPurchaseView);

        m_pPurchaseHLayout = new QHBoxLayout();
        m_pPurchaseHLayout->setObjectName(QString::fromUtf8("m_pPurchaseHLayout"));
        m_pPurchaseAddBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseAddBtn->setObjectName(QString::fromUtf8("m_pPurchaseAddBtn"));

        m_pPurchaseHLayout->addWidget(m_pPurchaseAddBtn);

        m_pPurchaseSelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseSelBtn->setObjectName(QString::fromUtf8("m_pPurchaseSelBtn"));

        m_pPurchaseHLayout->addWidget(m_pPurchaseSelBtn);

        m_pPurchaseUpdBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseUpdBtn->setObjectName(QString::fromUtf8("m_pPurchaseUpdBtn"));

        m_pPurchaseHLayout->addWidget(m_pPurchaseUpdBtn);

        m_pPurchaseDelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseDelBtn->setObjectName(QString::fromUtf8("m_pPurchaseDelBtn"));

        m_pPurchaseHLayout->addWidget(m_pPurchaseDelBtn);


        m_pPurchaseLayout->addLayout(m_pPurchaseHLayout);


        verticalLayout->addLayout(m_pPurchaseLayout);

        MainWidget->addTab(m_pPurchaseTab, QString());
        m_pReturnTab = new QWidget();
        m_pReturnTab->setObjectName(QString::fromUtf8("m_pReturnTab"));
        verticalLayout_5 = new QVBoxLayout(m_pReturnTab);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        m_pReturnLayout = new QVBoxLayout();
        m_pReturnLayout->setObjectName(QString::fromUtf8("m_pReturnLayout"));
        m_pReturnView = new QTreeView(m_pReturnTab);
        m_pReturnView->setObjectName(QString::fromUtf8("m_pReturnView"));

        m_pReturnLayout->addWidget(m_pReturnView);

        m_pReturnHLayout = new QHBoxLayout();
        m_pReturnHLayout->setObjectName(QString::fromUtf8("m_pReturnHLayout"));
        m_pReturnAddBtn = new QPushButton(m_pReturnTab);
        m_pReturnAddBtn->setObjectName(QString::fromUtf8("m_pReturnAddBtn"));

        m_pReturnHLayout->addWidget(m_pReturnAddBtn);

        m_pReturnSelBtn = new QPushButton(m_pReturnTab);
        m_pReturnSelBtn->setObjectName(QString::fromUtf8("m_pReturnSelBtn"));

        m_pReturnHLayout->addWidget(m_pReturnSelBtn);

        m_pReturnUpdBtn = new QPushButton(m_pReturnTab);
        m_pReturnUpdBtn->setObjectName(QString::fromUtf8("m_pReturnUpdBtn"));

        m_pReturnHLayout->addWidget(m_pReturnUpdBtn);

        m_pReturnDelBtn = new QPushButton(m_pReturnTab);
        m_pReturnDelBtn->setObjectName(QString::fromUtf8("m_pReturnDelBtn"));

        m_pReturnHLayout->addWidget(m_pReturnDelBtn);


        m_pReturnLayout->addLayout(m_pReturnHLayout);


        verticalLayout_5->addLayout(m_pReturnLayout);

        MainWidget->addTab(m_pReturnTab, QString());
        m_pSaleTab = new QWidget();
        m_pSaleTab->setObjectName(QString::fromUtf8("m_pSaleTab"));
        verticalLayout_6 = new QVBoxLayout(m_pSaleTab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        m_pSaleLayout = new QVBoxLayout();
        m_pSaleLayout->setObjectName(QString::fromUtf8("m_pSaleLayout"));
        m_pSaleView = new QTreeView(m_pSaleTab);
        m_pSaleView->setObjectName(QString::fromUtf8("m_pSaleView"));

        m_pSaleLayout->addWidget(m_pSaleView);

        m_pSaleHLayout = new QHBoxLayout();
        m_pSaleHLayout->setObjectName(QString::fromUtf8("m_pSaleHLayout"));
        m_pSaleAddBtn = new QPushButton(m_pSaleTab);
        m_pSaleAddBtn->setObjectName(QString::fromUtf8("m_pSaleAddBtn"));

        m_pSaleHLayout->addWidget(m_pSaleAddBtn);

        m_pSaleSelBtn = new QPushButton(m_pSaleTab);
        m_pSaleSelBtn->setObjectName(QString::fromUtf8("m_pSaleSelBtn"));

        m_pSaleHLayout->addWidget(m_pSaleSelBtn);

        m_pSaleUpdBtn = new QPushButton(m_pSaleTab);
        m_pSaleUpdBtn->setObjectName(QString::fromUtf8("m_pSaleUpdBtn"));

        m_pSaleHLayout->addWidget(m_pSaleUpdBtn);

        m_pSaleDelBtn = new QPushButton(m_pSaleTab);
        m_pSaleDelBtn->setObjectName(QString::fromUtf8("m_pSaleDelBtn"));

        m_pSaleHLayout->addWidget(m_pSaleDelBtn);


        m_pSaleLayout->addLayout(m_pSaleHLayout);


        verticalLayout_6->addLayout(m_pSaleLayout);

        MainWidget->addTab(m_pSaleTab, QString());

        retranslateUi(MainWidget);

        MainWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWidget);
    } // setupUi

    void retranslateUi(QTabWidget *MainWidget)
    {
        MainWidget->setWindowTitle(QApplication::translate("MainWidget", "MainWidget", 0, QApplication::UnicodeUTF8));
        m_pUserAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pUserSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pUserUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pUserDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pUserTab), QApplication::translate("MainWidget", "\347\224\250\346\210\267", 0, QApplication::UnicodeUTF8));
        m_pProductAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pProductSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pProductUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pProductDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pProductTab), QApplication::translate("MainWidget", "\344\272\247\345\223\201", 0, QApplication::UnicodeUTF8));
        m_pFactoryAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pFactorySelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pFactoryUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pFactoryDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pFactoryTab), QApplication::translate("MainWidget", "\345\216\202\345\225\206", 0, QApplication::UnicodeUTF8));
        m_pPurchaseAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pPurchaseSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pPurchaseUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pPurchaseDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pPurchaseTab), QApplication::translate("MainWidget", "\350\277\233\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        m_pReturnAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pReturnSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pReturnUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pReturnDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pReturnTab), QApplication::translate("MainWidget", "\351\200\200\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        m_pSaleAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pSaleSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pSaleUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pSaleDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pSaleTab), QApplication::translate("MainWidget", "\345\224\256\345\215\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
