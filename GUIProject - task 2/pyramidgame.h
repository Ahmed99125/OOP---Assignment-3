#ifndef PYRAMIDGAME_H
#define PYRAMIDGAME_H

#include <QDialog>

namespace Ui {
class PyramidGame;
}

class PyramidGame : public QDialog
{
    Q_OBJECT

public:
    explicit PyramidGame(QWidget *parent = nullptr);
    ~PyramidGame();

private:
    Ui::PyramidGame *ui;
};

#endif // PYRAMIDGAME_H
