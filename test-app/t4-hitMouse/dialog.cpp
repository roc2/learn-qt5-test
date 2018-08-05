#include "dialog.h"
#include "ui_dialog.h"
#include "mainscene.h"
#include "gameitem.h"
#include "globalflag.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    this->setFixedHeight(SC_GAME_HEIGHT+80);
    this->setFixedWidth(SC_GAME_WIDTH+200);

    MainScene *sc = new MainScene(this);

    ui->gameView->setFixedSize(SC_GAME_WIDTH+20, SC_GAME_HEIGHT+20);
    ui->gameView->setScene(sc);

    sc->setTimerSeconds(800);

    ui->lcdScore->setFixedHeight(80);

    connect(ui->btnStart, &QPushButton::clicked, sc, &MainScene::startShow);
    connect(ui->btnPause, &QPushButton::clicked, sc, &MainScene::pauseShow);

    connect(sc, &MainScene::getingScore, this, &Dialog::setGameScore);
}

void Dialog::setGameScore(int score)
{
    ui->lcdScore->display(score);

    qDebug()<<"score:"<<score;
}

Dialog::~Dialog()
{
    delete ui;
}
