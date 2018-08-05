#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QLCDNumber>
#include <QDebug>

#define SC_GAME_WIDTH       GAME_ITEM_WIDTH*ITEM_W_COUNT
#define SC_GAME_HEIGHT      GAME_ITEM_HEIGHT*ITEM_H_COUNT

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

private:
    Ui::Dialog *ui;

private slots:
    void setGameScore(int score);
};

#endif // DIALOG_H
