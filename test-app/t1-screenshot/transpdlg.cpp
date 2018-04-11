#include "transpdlg.h"

TranspDlg::TranspDlg(QWidget *parent)
    :QDialog(parent)
{
    p1 = QPoint(0,0);
    p2 = QPoint(0,0);
    mousedown = false;
    //create a transparent window, and no border
    this->setWindowFlags(Qt::FramelessWindowHint);
    this->setAttribute(Qt::WA_TranslucentBackground);

    QWidget *wind = QApplication::desktop()->screen();
    this->resize(wind->width(), wind->height());

    this->setMouseTracking(true);
}

void TranspDlg::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        p1.setX(event->x());
        p1.setY(event->y());
        mousedown = true;
    }
    if(event->button() == Qt::RightButton) {
        emit closef();
        this->close();
    }
}

void TranspDlg::mouseMoveEvent(QMouseEvent *event)
{
    if(mousedown) {
        p2.setX(event->x());
        p2.setY(event->y());
        update();
    }
}

void TranspDlg::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton) {
        p2.setX(event->x());
        p2.setY(event->y());
        mousedown = false;
        emit finsh(p1, p2);
    }
}

void TranspDlg::paintEvent(QPaintEvent *event)
{
    //set transparent
    int alpha = 1;
    QPainter paint(this);
    paint.fillRect(0,0, this->width(), this->height(), QColor(0,0,0,alpha));

    QPen pen(Qt::red, 2);
    paint.setPen(pen);
    paint.drawRect(p1.x(),p1.y(), p2.x()-p1.x(), p2.y()-p1.y());
}
