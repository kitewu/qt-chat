/********************************************************************************
** Form generated from reading UI file 'userlistwindow.ui'
**
** Created: Tue Jun 6 16:32:56 2017
**      by: Qt User Interface Compiler version 4.8.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERLISTWINDOW_H
#define UI_USERLISTWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QMainWindow>
#include <QtGui/QMenuBar>
#include <QtGui/QSpacerItem>
#include <QtGui/QTableWidget>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserListWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *userlist;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_3;
    QLabel *onlineuser;
    QSpacerItem *horizontalSpacer_2;
    QLabel *account;
    QLabel *label_2;
    QLabel *uname;
    QMenuBar *menubar;

    void setupUi(QMainWindow *UserListWindow)
    {
        if (UserListWindow->objectName().isEmpty())
            UserListWindow->setObjectName(QString::fromUtf8("UserListWindow"));
        UserListWindow->resize(305, 562);
        centralwidget = new QWidget(UserListWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        userlist = new QTableWidget(centralwidget);
        if (userlist->columnCount() < 3)
            userlist->setColumnCount(3);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/image/User.png"), QSize(), QIcon::Normal, QIcon::On);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setIcon(icon);
        userlist->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        userlist->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        userlist->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        userlist->setObjectName(QString::fromUtf8("userlist"));
        userlist->setGeometry(QRect(0, 30, 301, 471));
        userlist->setFrameShape(QFrame::StyledPanel);
        userlist->setEditTriggers(QAbstractItemView::NoEditTriggers);
        userlist->setSelectionMode(QAbstractItemView::SingleSelection);
        userlist->setSelectionBehavior(QAbstractItemView::SelectRows);
        userlist->setShowGrid(false);
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 510, 301, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        onlineuser = new QLabel(layoutWidget);
        onlineuser->setObjectName(QString::fromUtf8("onlineuser"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(onlineuser->sizePolicy().hasHeightForWidth());
        onlineuser->setSizePolicy(sizePolicy);

        horizontalLayout_3->addWidget(onlineuser);

        horizontalSpacer_2 = new QSpacerItem(30, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        account = new QLabel(centralwidget);
        account->setObjectName(QString::fromUtf8("account"));
        account->setGeometry(QRect(0, 0, 91, 21));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(270, 0, 31, 31));
        uname = new QLabel(centralwidget);
        uname->setObjectName(QString::fromUtf8("uname"));
        uname->setGeometry(QRect(120, 0, 121, 21));
        UserListWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(UserListWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 305, 25));
        UserListWindow->setMenuBar(menubar);

        retranslateUi(UserListWindow);

        QMetaObject::connectSlotsByName(UserListWindow);
    } // setupUi

    void retranslateUi(QMainWindow *UserListWindow)
    {
        UserListWindow->setWindowTitle(QApplication::translate("UserListWindow", "MainWindow", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem = userlist->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("UserListWindow", "\345\270\220\345\217\267", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem1 = userlist->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("UserListWindow", "\345\220\215\345\255\227", 0, QApplication::UnicodeUTF8));
        QTableWidgetItem *___qtablewidgetitem2 = userlist->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("UserListWindow", "\346\266\210\346\201\257", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        userlist->setToolTip(QApplication::translate("UserListWindow", "\345\234\250\347\272\277\347\224\250\346\210\267\344\277\241\346\201\257\345\210\227\350\241\250", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        onlineuser->setText(QApplication::translate("UserListWindow", "\345\234\250\347\272\277\347\224\250\346\210\267\357\274\2320\344\272\272", 0, QApplication::UnicodeUTF8));
        account->setText(QApplication::translate("UserListWindow", "123", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("UserListWindow", "\345\234\250\347\272\277", 0, QApplication::UnicodeUTF8));
        uname->setText(QApplication::translate("UserListWindow", "123", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class UserListWindow: public Ui_UserListWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERLISTWINDOW_H
