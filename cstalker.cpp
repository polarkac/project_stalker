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

void CStalker::SetWalk(Direction side)
{
    switch(side)
    {
    case RIGHT:
        m_iWalkSpeed = WALK_SPEED; break;
    case LEFT:
        m_iWalkSpeed = -WALK_SPEED; break;
    }

    if(m_actualState != JUMPING && m_actualState != FALLING)
        m_actualState = WALKING;
}

void CStalker::StopWalk(Direction side)
{
    m_iWalkSpeed = 0;
    if(m_actualState != JUMPING && m_actualState != FALLING)
        m_actualState = STANDING;
}

void CStalker::SetJump()
{
    if(m_actualState == JUMPING || m_actualState == FALLING)
        return;
    m_iJumpSpeed = JUMP_SPEED;
    m_actualState = JUMPING;
    m_iMaxJump = m_imgStalker->pos().y() - 60;
}

void CStalker::HandleWalk()
{
    extern CScene *scene;
    // if statements to not go behind the scene
    if((m_imgStalker->pos().x() + m_imgStalker->pixmap().width()) >= scene->width())
    {
        m_imgStalker->setPos(scene->width() - m_imgStalker->pixmap().width(), m_imgStalker->pos().y());
        if(m_iWalkSpeed > 0)
            return;
    }
    else if(m_imgStalker->pos().x() <= 0)
    {
        m_imgStalker->setPos(0, m_imgStalker->pos().y());
        if(m_iWalkSpeed < 0)
            return;
    }

    // ready to walk?
    if(m_iWalkSpeed != 0)
    {
        QPointF prevPos = m_imgStalker->pos();
        m_imgStalker->moveBy(m_iWalkSpeed, 0);

        // collide item on new location? back to old one
        if(!scene->collidingItems(m_imgStalker).isEmpty())
            m_imgStalker->setPos(prevPos);
    }

    // "fake" gravity when walk in progress
    if(m_actualState != JUMPING && m_actualState != FALLING)
    {
        int iPrevJumpSpeed = m_iJumpSpeed;
        State prevState = m_actualState;
        m_actualState = FALLING;
        m_iJumpSpeed = JUMP_SPEED;
        HandleJump();
        m_actualState = prevState;
        m_iJumpSpeed = iPrevJumpSpeed;
    }
}



void CStalker::HandleJump()
{
    // ready to jump?
    if(m_iJumpSpeed != 0)
    {
        QPointF prevPos = m_imgStalker->pos();
        extern CScene *scene;
        if(m_actualState == JUMPING) // jumping handler
        {
            if(m_imgStalker->pos().y() <= m_iMaxJump) // hero reached max height
            {
                m_actualState = FALLING;
                return;
            }
            m_imgStalker->moveBy(0, -m_iJumpSpeed);
            if(!scene->collidingItems(m_imgStalker).isEmpty())
            {
                QList<QGraphicsItem *> colidList = scene->collidingItems(m_imgStalker);
                m_imgStalker->setPos(m_imgStalker->pos().x(), colidList[0]->pos().y() + colidList[0]->boundingRect().height() + 1);
                m_actualState = FALLING;
            }
        }
        else if(m_actualState == FALLING || m_actualState == WALKING) // falling handler
        {
            m_imgStalker->moveBy(0, m_iJumpSpeed * 1.4);
            if(!scene->collidingItems(m_imgStalker).isEmpty())
            {
                QList<QGraphicsItem *> colidList = scene->collidingItems(m_imgStalker);
                m_imgStalker->setPos(m_imgStalker->pos().x(), colidList[0]->pos().y() - m_imgStalker->pixmap().height() - 1);
                m_actualState = STANDING;
                m_iJumpSpeed = 0;
                m_iMaxJump = 0;
            }
        }
    }
}
