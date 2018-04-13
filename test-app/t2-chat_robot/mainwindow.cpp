#include "mainwindow.h"
#include "ui_mainwindow.h"

static const QString TuLing_url = "http://www.tuling123.com/openapi/api";
static const QString TuLing_APIKEY = "***";
static const QString Baidu_url = "http://tsn.baidu.com/text2audio?";
static const QString Baidu_Token = "***";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->editSend->setClearButtonEnabled(true);

    player = new QMediaPlayer(this);

    connect(ui->btnSend, &QPushButton::clicked,
            this, &MainWindow::onBtnSend);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onBtnSend()
{
    QString strSend = ui->editSend->text();

    if(strSend.isEmpty()) {
        strSend = tr("你好");
    }
    QString strUrl = TuLing_url + "?key=" + TuLing_APIKEY + "&info=" + strSend;

    ui->editRecv->append(tr("我:") + strSend);

    QUrl url;
    url.setUrl(strUrl);
    QNetworkRequest request(url);
    QNetworkAccessManager *manger = new QNetworkAccessManager(this);
    manger->get(request);
    connect(manger, &QNetworkAccessManager::finished,
            this, &MainWindow::replyFinished);

}

QString MainWindow::getMac()
{
    QNetworkInterface inf;
    QString baidu_cuid;
    foreach(inf, QNetworkInterface::allInterfaces()) {
        baidu_cuid += "Interface:"+inf.hardwareAddress()+"\n";
        if(! (inf.flags() & QNetworkInterface::IsRunning) ) {
            baidu_cuid = inf.hardwareAddress();
            break;
        }
    }

    QStringList list = baidu_cuid.split(QRegExp(":"), QString::SkipEmptyParts);

    QString mac = list.at(0) + "-" + list.at(1)+"-" + list.at(2)+"-"
            +list.at(3) + "-" + list.at(4)+"-" + list.at(5);

    return mac;
}

void MainWindow::replyFinished(QNetworkReply *reply)
{
    QString data = reply->readAll();

    QScriptEngine engineText;
    QScriptValue jsonText = engineText.evaluate("value="+data);
    QScriptValueIterator iteratorText(jsonText);

    QString strText;

    while(iteratorText.hasNext()) {
        iteratorText.next();

        if(iteratorText.name() == "text") {
            strText = iteratorText.value().toString();
            ui->editRecv->append("robot:"+strText);

            QString  strMac = getMac();

            showSong(strText, "zh", Baidu_Token, "1", strMac,
                     "5", "5", "5", "0");//默认设置语音：中文，语速语调等为5，讲述人：0为女

            break;
        }
    }
}

void MainWindow::showSong(QString bai_tex, QString bai_lan, QString bai_tok,
                          QString bai_ctp, QString bai_cuid, QString bai_spd,
                          QString bai_pit, QString bai_vol, QString bai_per)
{
    QByteArray url= Baidu_url.toLatin1();
    url.append(QString("&lan=%1&cuid=%2&ctp=%3&tok=%4&spd=%5&pit=%6&vol=%7&per=%8")
               .arg(bai_lan).arg(bai_cuid).arg(bai_ctp).arg(bai_tok)
               .arg(bai_spd).arg(bai_pit).arg(bai_vol).arg(bai_per));
    url.append("&tex=");
    url.append(QUrl::toPercentEncoding(bai_tex));

    player->setMedia(QUrl::fromLocalFile(url));
    qDebug()<<"song:"<<url;
   //player->setMedia(QUrl::fromLocalFile(QString::fromLocal8Bit("D:/test.mp3")));

    player->play();
}
