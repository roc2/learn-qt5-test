#ifndef GAMEITEM_H
#define GAMEITEM_H

#include <QObject>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

#include "globalflag.h"

#define GAME_ITEM_WIDTH    146
#define GAME_ITEM_HEIGHT   154

#define ITEM_W_COUNT        4
#define ITEM_H_COUNT        4

class gameItem : public QGraphicsPixmapItem
{
public:
    explicit gameItem();

    void setPic(QString pic);

    void setMousePressed(bool flag);
    void setGameStart(bool flag);

private:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    bool m_isMousePressed;
    bool m_isGameStart;
};

#endif // GAMEITEM_H
