#include "cstalker.h"

CStalker::CStalker()
{
    m_iPosX = 0;
    m_iPosY = 300;
    m_actualState = STAND;
    m_actualSide = RIGHT;
    m_actualJump = NOTHING;
    m_imgStalker = new QGraphicsPixmapItem;
    m_imgStalker->setPixmap(QPixmap(":/images/online"));
    m_imgStalker->setPos(m_iPosX, m_iPosY);

}

CStalker::~CStalker()
{
    delete m_imgStalker;
}

QGraphicsPixmapItem *CStalker::GetImage()
{
    return m_imgStalker;
}

void CStalker::SetWalk(bool bWalk, Direction side)
{
    if(bWalk)
    {
        m_actualState = WALK;
        m_actualSide = side;
    }
    else
    {
        m_actualState = STAND;
    }
}

void CStalker::SetJump()
{
    if(m_actualJump == JUMPING || m_actualJump == FALLING)
        return;
    m_actualJump = JUMPING;
    m_iMaxJump = m_iPosY - 50;
}

void CStalker::HandleWalk()
{
    extern CScene *scene;
    if(m_actualState == WALK && (scene->GetKeyPressed()->bLArrow || scene->GetKeyPressed()->bRArrow))
    {
        switch(m_actualSide)
        {
        case LEFT:
            m_imgStalker->setPos(m_iPosX -= 6, m_iPosY); break;
        case RIGHT:
            m_imgStalker->setPos(m_iPosX += 6, m_iPosY); break;
        }
    }
}

void CStalker::HandleJump()
{
    if(m_actualJump == JUMPING)
    {
        if(m_iPosY <= m_iMaxJump)
        {
            m_actualJump = FALLING;
        }
        else
        {
            m_imgStalker->setPos(m_iPosX, m_iPosY -= 6);
        }
    }
    else if(m_actualJump == FALLING)
    {
        m_imgStalker->setPos(m_iPosX, m_iPosY += 6);
    }
}

