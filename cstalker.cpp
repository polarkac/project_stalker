#include "cstalker.h"

CStalker::CStalker()
{
    m_iPosX = 100;
    m_iPosY = 400;
    m_imgStalker = new QImage;
    m_imgStalker->load(":/images/online");
    m_iJump = 0;
    m_iWalk = 0;
}

CStalker::~CStalker()
{
    delete m_imgStalker;
}

void CStalker::SetWalk(int iNewWalk)
{
    m_iWalk = iNewWalk;
}

void CStalker::Walk()
{
    if(m_iWalk<0)
    {
        m_iPosX -= 3;
    }
    else if(m_iWalk>0)
    {
        m_iPosX += 3;
    }
}



void CStalker::HandleJump()
{
    if(m_iJump)
    {
        if(m_iPosY <= m_maxJump)
            m_iJump = 2;
        if(m_iJump == 1)
        {
            m_iPosY -= 5;
        }
        else if(m_iJump == 2)
        {
            m_iPosY += 5;
        }
        if(m_iPosY >= (m_maxJump + 100))
            m_iJump = 0;
    }
}

void CStalker::Jump()
{
    if(m_iJump > 0)
        return;
    m_maxJump = m_iPosY - 100;
    m_iJump = 1;
}
