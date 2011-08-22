#include "cscene.h"

#define WALK_SPEED 6
#define JUMP_SPEED 6

CScene::CScene(QObject *parent) :
    QGraphicsScene(parent)
{
    m_timer = new QTimer(this);
    m_timer->start(25);

    m_actualKey.bLArrow = FALSE;
    m_actualKey.bRArrow = FALSE;
    m_actualKey.bLCtrl = FALSE;
}

void CScene::keyPressEvent(QKeyEvent *event)
{
    extern CStalker *hero;
    switch(event->key())
    {
        case Qt::Key_Right:
            hero->SetWalk(WALK_SPEED, RIGHT); break;
        case Qt::Key_Left:
            hero->SetWalk(-WALK_SPEED, LEFT); break;
        case Qt::Key_Space:
            hero->SetJump(JUMP_SPEED); break;
    }
}

void CScene::keyReleaseEvent(QKeyEvent *event)
{
    extern CStalker *hero;
    switch(event->key())
    {
        case Qt::Key_Right:
            hero->SetWalk(0, RIGHT); break;
        case Qt::Key_Left:
            hero->SetWalk(0, LEFT); break;
    }
}

KeyPress * CScene::GetKeyPressed()
{
    return &m_actualKey;
}
