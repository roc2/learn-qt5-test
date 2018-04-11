#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPixmap>
#include <QScreen>
#include <QPushButton>
#include <QLabel>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>
#include <QPen>
#include <QDebug>
#include <QPoint>

#include "transpdlg.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void onBtnShotFullSC();
    void onBtnShotWind();
    void onBtnShotActive();

    void shot(QPoint p1, QPoint p2);
};

#endif // MAINWINDOW_H
