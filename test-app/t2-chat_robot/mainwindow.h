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

    //Q
};

#endif // MAINWINDOW_H
