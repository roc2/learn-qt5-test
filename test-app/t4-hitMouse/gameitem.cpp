#include "gameitem.h"

gameItem::gameItem()
{
    this->m_isGameStart = false;
    this->m_isMousePressed = false;
}

void gameItem::setPic(QString pic)
{
    this->setPixmap(QPixmap(pic));
}

void gameItem::setMousePressed(bool flag)
{
    this->m_isMousePressed = flag;
}

void gameItem::setGameStart(bool flag)
{
    this->m_isGameStart = flag;
}

void gameItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    this->setCursor(QCursor(QPixmap(":/pic/hammer_down")));
    if(GlobalFlag::isGameStart()){
        if(this->m_isMousePressed){
            qDebug()<<"mouse clicked";
            this->setPic(":/pic/mouse_hited");
            this->setPos(this->pos().x(), this->pos().y()+30);

            GlobalFlag::addScore();

//            qDebug()<<"score:"<<GlobalFlag::getScore();
        }else{
            qDebug()<<"mouse not clicked";

        }
    }else{
        qDebug()<<"game is not start";
    }
}

void gameItem::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    //this->setPic(":/pic/emptyhole");

    this->setCursor(QCursor(QPixmap(":/pic/hammer_up")));
}
