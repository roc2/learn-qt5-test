#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->setFixedHeight(500);
    this->setFixedWidth(800);

    ui->labelShow->setFixedWidth(700);

    this->setWindowTitle(tr("Screenshot Tools v0.1"));

    ui->btnshotactive->setToolTip("screenshot the current active window!");
    ui->btnshotfull->setToolTip("screenshot the full screen of window!");
    ui->btnshotwind->setToolTip("screenshot selected area by mouse, start with mouse left click, and stop with mouse right clicked!");

    connect(ui->btnshotfull, SIGNAL(clicked(bool)),
            this, SLOT(onBtnShotFullSC()));

    connect(ui->btnshotwind, SIGNAL(clicked(bool)),
            this, SLOT(onBtnShotWind()));

    connect(ui->btnshotactive,SIGNAL(clicked(bool)),
            this, SLOT(onBtnShotActive()));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnShotFullSC()
{
    //method 1, used in qt4
    //QPixmap::grabWindow(QApplication::desktop()->winId()).save("untitled.jpg", "jpg");

    //method 2, recommend, used in qt5
    QScreen *sc = QGuiApplication::primaryScreen();
    QPixmap pic = sc->grabWindow(0);

    ui->labelShow->setPixmap(pic.scaled(ui->labelShow->size()));
}

void MainWindow::shot(QPoint p1, QPoint p2)
{
    QPixmap pic;
    QScreen *sc = QGuiApplication::primaryScreen();
    pic = sc->grabWindow(QApplication::desktop()->winId(), p1.x(), p1.y(),
                              p2.x()-p1.x(),p2.y()-p1.y());
    ui->labelShow->setPixmap(pic.scaled(ui->labelShow->size()));
}
void MainWindow::onBtnShotWind()
{
    TranspDlg *dlg = new TranspDlg;

    connect(dlg, SIGNAL(finsh(QPoint,QPoint)),
            this, SLOT(shot(QPoint,QPoint)));
    connect(dlg, SIGNAL(closef()),
            this, SLOT(show()));

    this->hide();

    dlg->exec();
}

//only can grab the window of this app
void MainWindow::onBtnShotActive()
{
    if(QApplication::activeWindow()) {

        QScreen *sc = QGuiApplication::primaryScreen();
        QWidget *w = QApplication::activeWindow();
        QPixmap pic =  sc->grabWindow(w->winId(), 0, 0, w->width(), w->height());

        ui->labelShow->setPixmap(pic.scaled(ui->labelShow->size()));
    }
}
