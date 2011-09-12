#include "cscene.h"

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
            hero->SetWalk(RIGHT); break;
        case Qt::Key_Left:
            hero->SetWalk(LEFT); break;
        case Qt::Key_Space:
            hero->SetJump(); break;
    }
}

void CScene::keyReleaseEvent(QKeyEvent *event)
{
    extern CStalker *hero;
    switch(event->key())
    {
        case Qt::Key_Right:
            hero->StopWalk(RIGHT); break;
        case Qt::Key_Left:
            hero->StopWalk(LEFT); break;
    }
}

KeyPress * CScene::GetKeyPressed()
{
    return &m_actualKey;
}
