/********************************************************************************
** Form generated from reading UI file 'normalgame.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NORMALGAME_H
#define UI_NORMALGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_NormalGame
{
public:

    void setupUi(QDialog *NormalGame)
    {
        if (NormalGame->objectName().isEmpty())
            NormalGame->setObjectName("NormalGame");
        NormalGame->resize(400, 300);

        retranslateUi(NormalGame);

        QMetaObject::connectSlotsByName(NormalGame);
    } // setupUi

    void retranslateUi(QDialog *NormalGame)
    {
        NormalGame->setWindowTitle(QCoreApplication::translate("NormalGame", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NormalGame: public Ui_NormalGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NORMALGAME_H
