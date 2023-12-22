/********************************************************************************
** Form generated from reading UI file 'fivexfivegame.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIVEXFIVEGAME_H
#define UI_FIVEXFIVEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_FiveXFiveGame
{
public:

    void setupUi(QDialog *FiveXFiveGame)
    {
        if (FiveXFiveGame->objectName().isEmpty())
            FiveXFiveGame->setObjectName("FiveXFiveGame");
        FiveXFiveGame->resize(431, 257);

        retranslateUi(FiveXFiveGame);

        QMetaObject::connectSlotsByName(FiveXFiveGame);
    } // setupUi

    void retranslateUi(QDialog *FiveXFiveGame)
    {
        FiveXFiveGame->setWindowTitle(QCoreApplication::translate("FiveXFiveGame", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FiveXFiveGame: public Ui_FiveXFiveGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIVEXFIVEGAME_H
