#include "globalflag.h"

bool GlobalFlag::m_isGameStart = false;
int GlobalFlag::m_score = 0;

GlobalFlag::GlobalFlag(QObject *parent) : QObject(parent)
{

}

void GlobalFlag::setGameStart(bool flag)
{
    GlobalFlag::m_isGameStart = flag;
}

bool GlobalFlag::isGameStart()
{
    return GlobalFlag::m_isGameStart;
}

void GlobalFlag::addScore()
{
    GlobalFlag::m_score += 1;


}

int GlobalFlag::getScore()
{
    return GlobalFlag::m_score;
}
