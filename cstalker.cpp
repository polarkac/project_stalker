#include "cstalker.h"

CStalker::CStalker()
{
    m_iPosX = 0;
    m_iPosY = 300;
    m_actualState = JUMP;
    m_imgStalker = new QGraphicsPixmapItem[4];

    m_imgStalker[LEFT].setPixmap(QPixmap(":/images/online"));
    m_imgStalker[LEFT].setPos(m_iPosX, m_iPosY);

    m_imgStalker[RIGHT].setPixmap(QPixmap(":/images/busy"));
    m_imgStalker[RIGHT].setPos(m_iPosX, m_iPosY);

    m_imgStalker[JUMP].setPixmap(QPixmap(":/images/offline"));
    m_imgStalker[JUMP].setPos(m_iPosX, m_iPosY);

    m_imgStalker[CROUCH].setPixmap(QPixmap(":/images/busy"));
    m_imgStalker[CROUCH].setPos(m_iPosX, m_iPosY);

    timer = new QTimeLine(200);
    animation = new QGraphicsItemAnimation();
}

CStalker::~CStalker()
{
    delete [] m_imgStalker;
}

QGraphicsPixmapItem *CStalker::GetImage()
{
    QGraphicsPixmapItem *imgStalker;

    switch(m_actualState)
    {
    case LEFT:
        imgStalker = &m_imgStalker[LEFT]; break;
    case RIGHT:
        imgStalker = &m_imgStalker[RIGHT]; break;
    case JUMP:
        imgStalker = &m_imgStalker[JUMP]; break;
    case CROUCH:
        imgStalker = &m_imgStalker[CROUCH]; break;
    default:
        imgStalker = &m_imgStalker[RIGHT];
    }

    return imgStalker;
}

void CStalker::Walk()
{
    if(timer->state() == QTimeLine::Running)
        return;

    animation->setItem(&m_imgStalker[m_actualState]);
    animation->setTimeLine(timer);

    animation->setPosAt(1, QPointF(m_iPosX += 20, m_iPosY));

    timer->start();
}

