#include "cstalker.h"
#include "cscene.h"

CStalker::CStalker(QObject *parent) :
    QObject(parent)
{
    m_actualState = WALKING;
    m_imgStalker = new QGraphicsPixmapItem;
    m_imgStalker->setPixmap(QPixmap(":/images/online"));
    m_imgStalker->setPos(0, 310);
    m_imgStalker->setZValue(3);
    m_iWalkSpeed = 0;
    m_iJumpSpeed = 0;

    extern CScene *scene;
    scene->addItem(m_imgStalker);

    connect(scene->GetTimer(), SIGNAL(timeout()), this, SLOT(HandleWalk()));
    connect(scene->GetTimer(), SIGNAL(timeout()), this, SLOT(HandleJump()));
}

CStalker::~CStalker()
{
    delete m_imgStalker;
}

QGraphicsPixmapItem *CStalker::GetImage()
{
    // this method return actual loaded image
    return m_imgStalker;
}

void CStalker::SetWalk(int iSpeed, Direction side)
{
    m_iWalkSpeed = iSpeed;
    if(m_actualState != JUMPING || m_actualState != FALLING)
        m_actualState = WALKING;
}

void CStalker::SetJump(int iSpeed)
{
    if(m_actualState == JUMPING || m_actualState == FALLING)
        return;
    m_iJumpSpeed = iSpeed;
    m_actualState = JUMPING;
    m_iMaxJump = m_imgStalker->pos().y() - 50;
}

void CStalker::HandleWalk()
{
    extern CScene *scene;
    // if statements to not go behind the scene
    if((m_imgStalker->pos().x() + m_imgStalker->pixmap().width()) >= scene->width())
        m_imgStalker->setPos(scene->width() - m_imgStalker->pixmap().width(), m_imgStalker->pos().y());
    else if(m_imgStalker->pos().x() <= 0)
        m_imgStalker->setPos(0, m_imgStalker->pos().y());

    if(m_iWalkSpeed != 0)
    {
        QPointF prevPos = m_imgStalker->pos();
        m_imgStalker->moveBy(m_iWalkSpeed, 0);
        if(!scene->collidingItems(m_imgStalker).isEmpty())
            m_imgStalker->setPos(prevPos);
    }

//    if(m_actualState != JUMPING || m_actualState != FALLING)
//    {
//        int iPrevJumpSpeed = m_iJumpSpeed;
//        State prevState = m_actualState;
//        m_actualState = FALLING;
//        m_iJumpSpeed = 6;
//        HandleJump();
//        m_actualState = prevState;
//        m_iJumpSpeed = iPrevJumpSpeed;
//    }
}

void CStalker::HandleJump()
{
    if(m_iJumpSpeed != 0)
    {
        QPointF prevPos = m_imgStalker->pos();
        extern CScene *scene;
        if(m_actualState == JUMPING)
        {
            if(m_imgStalker->pos().y() <= m_iMaxJump)
            {
                m_actualState = FALLING;
                return;
            }
            m_imgStalker->moveBy(0, -m_iJumpSpeed);
            if(!scene->collidingItems(m_imgStalker).isEmpty())
            {
                m_imgStalker->setPos(prevPos);
                m_actualState = FALLING;
            }
        }
        else if(m_actualState == FALLING || m_actualState == WALKING)
        {
            m_imgStalker->moveBy(0, m_iJumpSpeed);
            if(!scene->collidingItems(m_imgStalker).isEmpty())
            {
                m_imgStalker->setPos(prevPos);
                m_actualState = STANDING;
            }
        }
    }
}
