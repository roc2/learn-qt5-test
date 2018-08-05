#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include "gameitem.h"
#include "globalflag.h"

#include <QDebug>
#include <time.h>
#include <stdlib.h>
#include <QTimer>

class MainScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit MainScene(QObject *parent = nullptr);

    void setTimerSeconds(int ms);

    void showMouse();
    void startShow();
    void pauseShow();

signals:
    void getingScore(int score);

public slots:

private:
    gameItem *m_items[4][4];

    QTimer *m_timer;
    int m_timerSecond;

private:
};

#endif // MAINSCENE_H
