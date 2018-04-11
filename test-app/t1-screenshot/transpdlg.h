#ifndef TRANSPDLG_H
#define TRANSPDLG_H

#include <QObject>
#include <QDialog>
#include <QPainter>
#include <QPen>
#include <QPoint>
#include <QDesktopWidget>
#include <QMouseEvent>
#include <QBrush>
#include <QApplication>

class TranspDlg : public QDialog
{
    Q_OBJECT
public:
    TranspDlg(QWidget* parent = 0);

protected:
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    void paintEvent(QPaintEvent *event);

signals:
    void finsh(QPoint p1, QPoint p2);
    void closef();

private:
    QPoint p1;
    QPoint p2;
    bool mousedown;

};

#endif // TRANSPDLG_H
