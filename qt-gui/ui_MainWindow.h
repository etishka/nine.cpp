/********************************************************************************
** Form generated from reading ui file 'MainWindow.ui'
**
** Created: Mon Mar 3 17:42:13 2008
**      by: Qt User Interface Compiler version 4.3.2
**
** WARNING! All changes made in this file will be lost when recompiling ui file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QMainWindow>
#include <QtGui/QMenu>
#include <QtGui/QMenuBar>
#include <QtGui/QStatusBar>
#include <QtGui/QWidget>

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionExit;
    QAction *actionSwitch_cards;
    QAction *actionGame_settings;
    QAction *actionNine_handbook;
    QAction *actionWhat_s_this;
    QAction *actionAbout_Nine;
    QWidget *centralwidget;
    QMenuBar *menubar;
    QMenu *menuGame;
    QMenu *menuEdit;
    QMenu *menuSettings;
    QMenu *menuHelp;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
    if (MainWindow->objectName().isEmpty())
        MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
    MainWindow->resize(800, 600);
    actionNew = new QAction(MainWindow);
    actionNew->setObjectName(QString::fromUtf8("actionNew"));
    actionOpen = new QAction(MainWindow);
    actionOpen->setObjectName(QString::fromUtf8("actionOpen"));
    actionSave = new QAction(MainWindow);
    actionSave->setObjectName(QString::fromUtf8("actionSave"));
    actionExit = new QAction(MainWindow);
    actionExit->setObjectName(QString::fromUtf8("actionExit"));
    actionSwitch_cards = new QAction(MainWindow);
    actionSwitch_cards->setObjectName(QString::fromUtf8("actionSwitch_cards"));
    actionGame_settings = new QAction(MainWindow);
    actionGame_settings->setObjectName(QString::fromUtf8("actionGame_settings"));
    actionNine_handbook = new QAction(MainWindow);
    actionNine_handbook->setObjectName(QString::fromUtf8("actionNine_handbook"));
    actionWhat_s_this = new QAction(MainWindow);
    actionWhat_s_this->setObjectName(QString::fromUtf8("actionWhat_s_this"));
    actionAbout_Nine = new QAction(MainWindow);
    actionAbout_Nine->setObjectName(QString::fromUtf8("actionAbout_Nine"));
    centralwidget = new QWidget(MainWindow);
    centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
    MainWindow->setCentralWidget(centralwidget);
    menubar = new QMenuBar(MainWindow);
    menubar->setObjectName(QString::fromUtf8("menubar"));
    menubar->setGeometry(QRect(0, 0, 800, 29));
    menuGame = new QMenu(menubar);
    menuGame->setObjectName(QString::fromUtf8("menuGame"));
    menuEdit = new QMenu(menubar);
    menuEdit->setObjectName(QString::fromUtf8("menuEdit"));
    menuSettings = new QMenu(menubar);
    menuSettings->setObjectName(QString::fromUtf8("menuSettings"));
    menuHelp = new QMenu(menubar);
    menuHelp->setObjectName(QString::fromUtf8("menuHelp"));
    MainWindow->setMenuBar(menubar);
    statusbar = new QStatusBar(MainWindow);
    statusbar->setObjectName(QString::fromUtf8("statusbar"));
    MainWindow->setStatusBar(statusbar);

    menubar->addAction(menuGame->menuAction());
    menubar->addAction(menuEdit->menuAction());
    menubar->addAction(menuSettings->menuAction());
    menubar->addAction(menuHelp->menuAction());
    menuGame->addAction(actionNew);
    menuGame->addAction(actionOpen);
    menuGame->addAction(actionSave);
    menuGame->addSeparator();
    menuGame->addAction(actionExit);
    menuSettings->addAction(actionSwitch_cards);
    menuSettings->addAction(actionGame_settings);
    menuHelp->addAction(actionNine_handbook);
    menuHelp->addAction(actionWhat_s_this);
    menuHelp->addSeparator();
    menuHelp->addAction(actionAbout_Nine);

    retranslateUi(MainWindow);
    QObject::connect(MainWindow, SIGNAL(customContextMenuRequested(QPoint)), MainWindow, SLOT(update()));

    QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
    MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Nine game", 0, QApplication::UnicodeUTF8));
    actionNew->setText(QApplication::translate("MainWindow", "&New", 0, QApplication::UnicodeUTF8));
    actionOpen->setText(QApplication::translate("MainWindow", "&Open...", 0, QApplication::UnicodeUTF8));
    actionSave->setText(QApplication::translate("MainWindow", "Save &as...", 0, QApplication::UnicodeUTF8));
    actionExit->setText(QApplication::translate("MainWindow", "&Quit", 0, QApplication::UnicodeUTF8));
    actionSwitch_cards->setText(QApplication::translate("MainWindow", "Switch cards...", 0, QApplication::UnicodeUTF8));
    actionGame_settings->setText(QApplication::translate("MainWindow", "Game settings", 0, QApplication::UnicodeUTF8));
    actionNine_handbook->setText(QApplication::translate("MainWindow", "Nine Handbook", 0, QApplication::UnicodeUTF8));
    actionWhat_s_this->setText(QApplication::translate("MainWindow", "What's this?", 0, QApplication::UnicodeUTF8));
    actionAbout_Nine->setText(QApplication::translate("MainWindow", "About Nine...", 0, QApplication::UnicodeUTF8));
    menuGame->setTitle(QApplication::translate("MainWindow", "&Game", 0, QApplication::UnicodeUTF8));
    menuEdit->setTitle(QApplication::translate("MainWindow", "Edit", 0, QApplication::UnicodeUTF8));
    menuSettings->setTitle(QApplication::translate("MainWindow", "Settings", 0, QApplication::UnicodeUTF8));
    menuHelp->setTitle(QApplication::translate("MainWindow", "Help", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

#endif // UI_MAINWINDOW_H
