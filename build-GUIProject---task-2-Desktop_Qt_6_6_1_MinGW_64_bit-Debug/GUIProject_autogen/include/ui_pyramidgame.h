/********************************************************************************
** Form generated from reading UI file 'pyramidgame.ui'
**
** Created by: Qt User Interface Compiler version 6.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PYRAMIDGAME_H
#define UI_PYRAMIDGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_PyramidGame
{
public:

    void setupUi(QDialog *PyramidGame)
    {
        if (PyramidGame->objectName().isEmpty())
            PyramidGame->setObjectName("PyramidGame");
        PyramidGame->resize(386, 262);

        retranslateUi(PyramidGame);

        QMetaObject::connectSlotsByName(PyramidGame);
    } // setupUi

    void retranslateUi(QDialog *PyramidGame)
    {
        PyramidGame->setWindowTitle(QCoreApplication::translate("PyramidGame", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PyramidGame: public Ui_PyramidGame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PYRAMIDGAME_H
