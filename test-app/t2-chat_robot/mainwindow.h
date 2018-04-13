#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLineEdit>
#include <QTextEdit>
#include <QPushButton>
#include <QtMultimedia/QAudio>
#include <QDebug>

#include <QJsonParseError>
#include <QJsonDocument>
#include <QtScript/QScriptEngine>
#include <QtScript/QScriptValue>
#include <QtScript>
#include <QtScript/QScriptValueIterator>

#include <QMediaPlayer>
#include <QtNetwork>
#include <QRegExp>

#include <QTimer>
#include <QTime>

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

    QMediaPlayer *player;

private:
    QString getMac();
    void showSong(QString bai_tex,QString bai_lan,QString bai_tok,
                  QString bai_ctp,QString bai_cuid,QString bai_spd,
                  QString bai_pit,QString bai_vol,QString bai_per);

private slots:
    void onBtnSend();
    void replyFinished(QNetworkReply *reply);
};

#endif // MAINWINDOW_H
