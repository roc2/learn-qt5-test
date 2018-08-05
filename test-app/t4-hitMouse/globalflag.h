#ifndef GLOBALFLAG_H
#define GLOBALFLAG_H

#include <QObject>

class GlobalFlag : public QObject
{
    Q_OBJECT
public:
    explicit GlobalFlag(QObject *parent = nullptr);

    static bool isGameStart();
    static void setGameStart(bool flag);
    static void addScore();
    static int getScore();

signals:

public slots:

private:
    static bool m_isGameStart;
    static int m_score;
};

#endif // GLOBALFLAG_H
