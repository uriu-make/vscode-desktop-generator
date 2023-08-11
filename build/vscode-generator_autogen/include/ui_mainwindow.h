/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdd_New_Template;
    QAction *actionQuit;
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QLineEdit *workspace_file_path;
    QPushButton *Directory;
    QLineEdit *Generate_name;
    QPushButton *Generate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(404, 74);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(404, 74));
        MainWindow->setMaximumSize(QSize(404, 74));
        MainWindow->setAutoFillBackground(false);
        MainWindow->setUnifiedTitleAndToolBarOnMac(false);
        actionAdd_New_Template = new QAction(MainWindow);
        actionAdd_New_Template->setObjectName(QString::fromUtf8("actionAdd_New_Template"));
        actionQuit = new QAction(MainWindow);
        actionQuit->setObjectName(QString::fromUtf8("actionQuit"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        workspace_file_path = new QLineEdit(centralwidget);
        workspace_file_path->setObjectName(QString::fromUtf8("workspace_file_path"));
        workspace_file_path->setMinimumSize(QSize(300, 25));
        workspace_file_path->setMaximumSize(QSize(300, 25));

        gridLayout->addWidget(workspace_file_path, 0, 0, 1, 1);

        Directory = new QPushButton(centralwidget);
        Directory->setObjectName(QString::fromUtf8("Directory"));
        Directory->setMinimumSize(QSize(80, 20));
        Directory->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(Directory, 0, 1, 1, 1);

        Generate_name = new QLineEdit(centralwidget);
        Generate_name->setObjectName(QString::fromUtf8("Generate_name"));
        Generate_name->setMinimumSize(QSize(300, 25));
        Generate_name->setMaximumSize(QSize(300, 25));

        gridLayout->addWidget(Generate_name, 1, 0, 1, 1);

        Generate = new QPushButton(centralwidget);
        Generate->setObjectName(QString::fromUtf8("Generate"));
        Generate->setEnabled(true);
        Generate->setMinimumSize(QSize(80, 25));
        Generate->setMaximumSize(QSize(80, 25));

        gridLayout->addWidget(Generate, 1, 1, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "VSCode Desktop generator", nullptr));
        actionAdd_New_Template->setText(QCoreApplication::translate("MainWindow", "Add New Template", nullptr));
        actionQuit->setText(QCoreApplication::translate("MainWindow", "Quit", nullptr));
        workspace_file_path->setText(QString());
        workspace_file_path->setPlaceholderText(QCoreApplication::translate("MainWindow", "code-workspace's Path", nullptr));
        Directory->setText(QCoreApplication::translate("MainWindow", "Directory", nullptr));
        Generate_name->setInputMask(QString());
        Generate_name->setText(QString());
        Generate_name->setPlaceholderText(QCoreApplication::translate("MainWindow", "Desktop Name", nullptr));
        Generate->setText(QCoreApplication::translate("MainWindow", "Generate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
