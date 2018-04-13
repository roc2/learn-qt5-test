#include "mainwindow.h"
#include "ui_mainwindow.h"

static const QString TuLing_url = "http://www.tuling123.com/openapi/api";
static const QString TuLing_APIKEY = "597916f6e30a493ea6b53ed893e1b7fe";
static const QString Baudu_url = "http://tsn.baidu.com/text2audio?";
static const QString Baudu_Token = "24.62ae5fa98d2bf32c53ff0bb258cce224.2592000.1526219198.282335-11097484";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editSend->setClearButtonEnabled(true);



}

MainWindow::~MainWindow()
{
    delete ui;
}
