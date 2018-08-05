#include "mainscene.h"

MainScene::MainScene(QObject *parent) : QGraphicsScene(parent)
{
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            m_items[i][j] = new gameItem;
            m_items[i][j]->setPic(":/pic/emptyhole");
            m_items[i][j]->setPos(i*GAME_ITEM_WIDTH, j*GAME_ITEM_HEIGHT);

            this->addItem(m_items[i][j]);

            //qDebug()<<"item pos:"<<i*GAME_ITEM_WIDTH<<", "<<j*GAME_ITEM_HEIGHT;
        }
    }

    GlobalFlag::setGameStart(false);

    //初始化随机种子
    srand((unsigned int)(time(NULL)));

    m_timer = new QTimer;
    connect(m_timer, &QTimer::timeout, this, &MainScene::showMouse);
}

void MainScene::setTimerSeconds(int ms)
{
    this->m_timerSecond = ms;
}

void MainScene::startShow()
{
    GlobalFlag::setGameStart(true);

    m_timer->start(this->m_timerSecond);

    qDebug()<<"开始游戏了";
}

void MainScene::pauseShow()
{
    GlobalFlag::setGameStart(false);
    m_timer->stop();

    qDebug()<<"暂停游戏？";
}

void MainScene::showMouse()
{
    //显示背景
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            m_items[i][j] = new gameItem;
            m_items[i][j]->setPic(":/pic/emptyhole");
            m_items[i][j]->setPos(i*GAME_ITEM_WIDTH, j*GAME_ITEM_HEIGHT);
            this->addItem(m_items[i][j]);

            m_items[i][j]->setMousePressed(false);
        }
    }

    //开始显示老鼠
    int mouse_count = rand()%3+1;
    for(int i=0; i<mouse_count; i++){

        int x = rand()%4;
        int y = rand()%4;
        //qDebug()<<"position:"<<x<<", "<<y;
        m_items[x][y]->setPic(":/pic/mouse_show");
        m_items[x][y]->setPos(x*GAME_ITEM_WIDTH+30, y*GAME_ITEM_HEIGHT+38);
        m_items[x][y]->setMousePressed(true);

        int score = GlobalFlag::getScore();

//        qDebug()<<"sc, score:"<<score;

        emit getingScore(score);
    }

//    m_items[x][y]->setPic(":/pic/mouse_hited");
//    m_items[x][y]->setPos(x*GAME_ITEM_WIDTH+30, y*GAME_ITEM_HEIGHT+68);

}
