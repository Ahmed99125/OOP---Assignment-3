/********************************************************************************
** Form generated from reading UI file 'connectfourgame.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTFOURGAME_H
#define UI_CONNECTFOURGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_ConnectFourGame
{
public:

    void setupUi(QDialog *ConnectFourGame)
    {
        if (ConnectFourGame->objectName().isEmpty())
            ConnectFourGame->setObjectName("ConnectFourGame");
        ConnectFourGame->setEnabled(true);
        ConnectFourGame->resize(605, 291);

        retranslateUi(ConnectFourGame);

        QMetaObject::connectSlotsByName(ConnectFourGame);
    } // setupUi

    void retranslateUi(QDialog *ConnectFourGame)
    {
        ConnectFourGame->setWindowTitle(QCoreApplication::translate("ConnectFourGame", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ConnectFourGame: public Ui_ConnectFourGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTFOURGAME_H
