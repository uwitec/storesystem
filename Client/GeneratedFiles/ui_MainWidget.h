/********************************************************************************
** Form generated from reading UI file 'MainWidget.ui'
**
** Created: Tue Jun 7 01:30:56 2011
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
#include <QtGui/QLabel>
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
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *m_pPurchaseLayout;
    QVBoxLayout *m_pPurchaseCVLayout;
    QTreeView *m_pPurchaseCView;
    QHBoxLayout *m_pPurchaseCHLayout;
    QPushButton *m_pPurchaseCAddBtn;
    QPushButton *m_pPurchaseCSelBtn;
    QPushButton *m_pPurchaseCUpdBtn;
    QPushButton *m_pPurchaseCDelBtn;
    QLabel *m_pArrowLabel;
    QVBoxLayout *m_pPurchaseSVLayout;
    QTreeView *m_pPurchaseSView;
    QHBoxLayout *m_pPurchaseSHLayout;
    QPushButton *m_pPurchaseSAddBtn;
    QPushButton *m_pPurchaseSSelBtn;
    QPushButton *m_pPurchaseSUpdBtn;
    QPushButton *m_pPurchaseSDelBtn;
    QWidget *m_pReturnTab;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTreeView *m_pReturnView;
    QLabel *label;
    QTreeView *treeView;
    QWidget *layoutWidget;
    QVBoxLayout *m_pReturnLayout;
    QHBoxLayout *m_pReturnHLayout;
    QPushButton *m_pReturnAddBtn;
    QPushButton *m_pReturnSelBtn;
    QPushButton *m_pReturnUpdBtn;
    QPushButton *m_pReturnDelBtn;
    QWidget *m_pSaleTab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *m_pSaleLayout;
    QVBoxLayout *m_pSaleCVLayout;
    QTreeView *m_pSaleCView;
    QHBoxLayout *m_pSaleCHLayout;
    QPushButton *m_pSaleCAddBtn;
    QPushButton *m_pSaleCSelBtn;
    QPushButton *m_pSaleCUpdBtn;
    QPushButton *m_pSaleCDelBtn;
    QLabel *m_pSaleArrowLabel;
    QVBoxLayout *m_pSaleSVLayout;
    QTreeView *m_pSaleSView;
    QHBoxLayout *m_pSaleSHLayout;
    QPushButton *m_pSaleSAddBtn;
    QPushButton *m_pSaleSSelBtn;
    QPushButton *m_pSaleSUpdBtn;
    QPushButton *m_pSaleSDelBtn;

    void setupUi(QTabWidget *MainWidget)
    {
        if (MainWidget->objectName().isEmpty())
            MainWidget->setObjectName(QString::fromUtf8("MainWidget"));
        MainWidget->resize(694, 432);
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
        horizontalLayout_3 = new QHBoxLayout(m_pPurchaseTab);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        m_pPurchaseLayout = new QHBoxLayout();
        m_pPurchaseLayout->setObjectName(QString::fromUtf8("m_pPurchaseLayout"));
        m_pPurchaseCVLayout = new QVBoxLayout();
        m_pPurchaseCVLayout->setObjectName(QString::fromUtf8("m_pPurchaseCVLayout"));
        m_pPurchaseCView = new QTreeView(m_pPurchaseTab);
        m_pPurchaseCView->setObjectName(QString::fromUtf8("m_pPurchaseCView"));

        m_pPurchaseCVLayout->addWidget(m_pPurchaseCView);

        m_pPurchaseCHLayout = new QHBoxLayout();
        m_pPurchaseCHLayout->setObjectName(QString::fromUtf8("m_pPurchaseCHLayout"));
        m_pPurchaseCAddBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseCAddBtn->setObjectName(QString::fromUtf8("m_pPurchaseCAddBtn"));

        m_pPurchaseCHLayout->addWidget(m_pPurchaseCAddBtn);

        m_pPurchaseCSelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseCSelBtn->setObjectName(QString::fromUtf8("m_pPurchaseCSelBtn"));

        m_pPurchaseCHLayout->addWidget(m_pPurchaseCSelBtn);

        m_pPurchaseCUpdBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseCUpdBtn->setObjectName(QString::fromUtf8("m_pPurchaseCUpdBtn"));

        m_pPurchaseCHLayout->addWidget(m_pPurchaseCUpdBtn);

        m_pPurchaseCDelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseCDelBtn->setObjectName(QString::fromUtf8("m_pPurchaseCDelBtn"));

        m_pPurchaseCHLayout->addWidget(m_pPurchaseCDelBtn);


        m_pPurchaseCVLayout->addLayout(m_pPurchaseCHLayout);


        m_pPurchaseLayout->addLayout(m_pPurchaseCVLayout);

        m_pArrowLabel = new QLabel(m_pPurchaseTab);
        m_pArrowLabel->setObjectName(QString::fromUtf8("m_pArrowLabel"));

        m_pPurchaseLayout->addWidget(m_pArrowLabel);

        m_pPurchaseSVLayout = new QVBoxLayout();
        m_pPurchaseSVLayout->setObjectName(QString::fromUtf8("m_pPurchaseSVLayout"));
        m_pPurchaseSView = new QTreeView(m_pPurchaseTab);
        m_pPurchaseSView->setObjectName(QString::fromUtf8("m_pPurchaseSView"));

        m_pPurchaseSVLayout->addWidget(m_pPurchaseSView);

        m_pPurchaseSHLayout = new QHBoxLayout();
        m_pPurchaseSHLayout->setObjectName(QString::fromUtf8("m_pPurchaseSHLayout"));
        m_pPurchaseSAddBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseSAddBtn->setObjectName(QString::fromUtf8("m_pPurchaseSAddBtn"));

        m_pPurchaseSHLayout->addWidget(m_pPurchaseSAddBtn);

        m_pPurchaseSSelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseSSelBtn->setObjectName(QString::fromUtf8("m_pPurchaseSSelBtn"));

        m_pPurchaseSHLayout->addWidget(m_pPurchaseSSelBtn);

        m_pPurchaseSUpdBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseSUpdBtn->setObjectName(QString::fromUtf8("m_pPurchaseSUpdBtn"));

        m_pPurchaseSHLayout->addWidget(m_pPurchaseSUpdBtn);

        m_pPurchaseSDelBtn = new QPushButton(m_pPurchaseTab);
        m_pPurchaseSDelBtn->setObjectName(QString::fromUtf8("m_pPurchaseSDelBtn"));

        m_pPurchaseSHLayout->addWidget(m_pPurchaseSDelBtn);


        m_pPurchaseSVLayout->addLayout(m_pPurchaseSHLayout);


        m_pPurchaseLayout->addLayout(m_pPurchaseSVLayout);


        horizontalLayout_3->addLayout(m_pPurchaseLayout);

        MainWidget->addTab(m_pPurchaseTab, QString());
        m_pReturnTab = new QWidget();
        m_pReturnTab->setObjectName(QString::fromUtf8("m_pReturnTab"));
        horizontalLayoutWidget = new QWidget(m_pReturnTab);
        horizontalLayoutWidget->setObjectName(QString::fromUtf8("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(290, 280, 192, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        m_pReturnView = new QTreeView(horizontalLayoutWidget);
        m_pReturnView->setObjectName(QString::fromUtf8("m_pReturnView"));

        horizontalLayout->addWidget(m_pReturnView);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        treeView = new QTreeView(horizontalLayoutWidget);
        treeView->setObjectName(QString::fromUtf8("treeView"));

        horizontalLayout->addWidget(treeView);

        layoutWidget = new QWidget(m_pReturnTab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 322, 30));
        m_pReturnLayout = new QVBoxLayout(layoutWidget);
        m_pReturnLayout->setObjectName(QString::fromUtf8("m_pReturnLayout"));
        m_pReturnLayout->setContentsMargins(0, 0, 0, 0);
        m_pReturnHLayout = new QHBoxLayout();
        m_pReturnHLayout->setObjectName(QString::fromUtf8("m_pReturnHLayout"));
        m_pReturnAddBtn = new QPushButton(layoutWidget);
        m_pReturnAddBtn->setObjectName(QString::fromUtf8("m_pReturnAddBtn"));

        m_pReturnHLayout->addWidget(m_pReturnAddBtn);

        m_pReturnSelBtn = new QPushButton(layoutWidget);
        m_pReturnSelBtn->setObjectName(QString::fromUtf8("m_pReturnSelBtn"));

        m_pReturnHLayout->addWidget(m_pReturnSelBtn);

        m_pReturnUpdBtn = new QPushButton(layoutWidget);
        m_pReturnUpdBtn->setObjectName(QString::fromUtf8("m_pReturnUpdBtn"));

        m_pReturnHLayout->addWidget(m_pReturnUpdBtn);

        m_pReturnDelBtn = new QPushButton(layoutWidget);
        m_pReturnDelBtn->setObjectName(QString::fromUtf8("m_pReturnDelBtn"));

        m_pReturnHLayout->addWidget(m_pReturnDelBtn);


        m_pReturnLayout->addLayout(m_pReturnHLayout);

        MainWidget->addTab(m_pReturnTab, QString());
        m_pSaleTab = new QWidget();
        m_pSaleTab->setObjectName(QString::fromUtf8("m_pSaleTab"));
        verticalLayout = new QVBoxLayout(m_pSaleTab);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        m_pSaleLayout = new QHBoxLayout();
        m_pSaleLayout->setObjectName(QString::fromUtf8("m_pSaleLayout"));
        m_pSaleCVLayout = new QVBoxLayout();
        m_pSaleCVLayout->setObjectName(QString::fromUtf8("m_pSaleCVLayout"));
        m_pSaleCView = new QTreeView(m_pSaleTab);
        m_pSaleCView->setObjectName(QString::fromUtf8("m_pSaleCView"));

        m_pSaleCVLayout->addWidget(m_pSaleCView);

        m_pSaleCHLayout = new QHBoxLayout();
        m_pSaleCHLayout->setObjectName(QString::fromUtf8("m_pSaleCHLayout"));
        m_pSaleCAddBtn = new QPushButton(m_pSaleTab);
        m_pSaleCAddBtn->setObjectName(QString::fromUtf8("m_pSaleCAddBtn"));

        m_pSaleCHLayout->addWidget(m_pSaleCAddBtn);

        m_pSaleCSelBtn = new QPushButton(m_pSaleTab);
        m_pSaleCSelBtn->setObjectName(QString::fromUtf8("m_pSaleCSelBtn"));

        m_pSaleCHLayout->addWidget(m_pSaleCSelBtn);

        m_pSaleCUpdBtn = new QPushButton(m_pSaleTab);
        m_pSaleCUpdBtn->setObjectName(QString::fromUtf8("m_pSaleCUpdBtn"));

        m_pSaleCHLayout->addWidget(m_pSaleCUpdBtn);

        m_pSaleCDelBtn = new QPushButton(m_pSaleTab);
        m_pSaleCDelBtn->setObjectName(QString::fromUtf8("m_pSaleCDelBtn"));

        m_pSaleCHLayout->addWidget(m_pSaleCDelBtn);


        m_pSaleCVLayout->addLayout(m_pSaleCHLayout);


        m_pSaleLayout->addLayout(m_pSaleCVLayout);

        m_pSaleArrowLabel = new QLabel(m_pSaleTab);
        m_pSaleArrowLabel->setObjectName(QString::fromUtf8("m_pSaleArrowLabel"));

        m_pSaleLayout->addWidget(m_pSaleArrowLabel);

        m_pSaleSVLayout = new QVBoxLayout();
        m_pSaleSVLayout->setObjectName(QString::fromUtf8("m_pSaleSVLayout"));
        m_pSaleSView = new QTreeView(m_pSaleTab);
        m_pSaleSView->setObjectName(QString::fromUtf8("m_pSaleSView"));

        m_pSaleSVLayout->addWidget(m_pSaleSView);

        m_pSaleSHLayout = new QHBoxLayout();
        m_pSaleSHLayout->setObjectName(QString::fromUtf8("m_pSaleSHLayout"));
        m_pSaleSAddBtn = new QPushButton(m_pSaleTab);
        m_pSaleSAddBtn->setObjectName(QString::fromUtf8("m_pSaleSAddBtn"));

        m_pSaleSHLayout->addWidget(m_pSaleSAddBtn);

        m_pSaleSSelBtn = new QPushButton(m_pSaleTab);
        m_pSaleSSelBtn->setObjectName(QString::fromUtf8("m_pSaleSSelBtn"));

        m_pSaleSHLayout->addWidget(m_pSaleSSelBtn);

        m_pSaleSUpdBtn = new QPushButton(m_pSaleTab);
        m_pSaleSUpdBtn->setObjectName(QString::fromUtf8("m_pSaleSUpdBtn"));

        m_pSaleSHLayout->addWidget(m_pSaleSUpdBtn);

        m_pSaleSDelBtn = new QPushButton(m_pSaleTab);
        m_pSaleSDelBtn->setObjectName(QString::fromUtf8("m_pSaleSDelBtn"));

        m_pSaleSHLayout->addWidget(m_pSaleSDelBtn);


        m_pSaleSVLayout->addLayout(m_pSaleSHLayout);


        m_pSaleLayout->addLayout(m_pSaleSVLayout);


        verticalLayout->addLayout(m_pSaleLayout);

        MainWidget->addTab(m_pSaleTab, QString());

        retranslateUi(MainWidget);

        MainWidget->setCurrentIndex(5);


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
        m_pPurchaseCAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pPurchaseCSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pPurchaseCUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pPurchaseCDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        m_pArrowLabel->setText(QApplication::translate("MainWidget", "=>", 0, QApplication::UnicodeUTF8));
        m_pPurchaseSAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pPurchaseSSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pPurchaseSUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pPurchaseSDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pPurchaseTab), QApplication::translate("MainWidget", "\350\277\233\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("MainWidget", "=>", 0, QApplication::UnicodeUTF8));
        m_pReturnAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pReturnSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pReturnUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pReturnDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pReturnTab), QApplication::translate("MainWidget", "\351\200\200\350\264\247\345\215\225", 0, QApplication::UnicodeUTF8));
        m_pSaleCAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pSaleCSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pSaleCUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pSaleCDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        m_pSaleArrowLabel->setText(QApplication::translate("MainWidget", "=>", 0, QApplication::UnicodeUTF8));
        m_pSaleSAddBtn->setText(QApplication::translate("MainWidget", "\346\267\273\345\212\240", 0, QApplication::UnicodeUTF8));
        m_pSaleSSelBtn->setText(QApplication::translate("MainWidget", "\346\237\245\350\257\242", 0, QApplication::UnicodeUTF8));
        m_pSaleSUpdBtn->setText(QApplication::translate("MainWidget", "\346\233\264\346\226\260", 0, QApplication::UnicodeUTF8));
        m_pSaleSDelBtn->setText(QApplication::translate("MainWidget", "\345\210\240\351\231\244", 0, QApplication::UnicodeUTF8));
        MainWidget->setTabText(MainWidget->indexOf(m_pSaleTab), QApplication::translate("MainWidget", "\345\224\256\345\215\225", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWidget: public Ui_MainWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWIDGET_H
