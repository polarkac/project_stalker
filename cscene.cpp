#include "cscene.h"

CScene::CScene(QObject *parent) :
    QGraphicsScene(parent)
{
    m_timer = new QTimer(this);
    m_timer->start(25);

    // LArrow and RArrow for smooth change between right and left walk
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
            hero->SetWalk(RIGHT);
            m_actualKey.bRArrow = TRUE;
            break;
        case Qt::Key_Left:
            hero->SetWalk(LEFT);
            m_actualKey.bLArrow = TRUE;
            break;
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
            if(m_actualKey.bLArrow)
            {
                m_actualKey.bRArrow = FALSE;
                break;
            }
            hero->StopWalk(RIGHT);
            m_actualKey.bRArrow = FALSE;
            break;
        case Qt::Key_Left:
            if(m_actualKey.bRArrow)
            {
                m_actualKey.bLArrow = FALSE;
                break;
            }
            hero->StopWalk(LEFT);
            m_actualKey.bLArrow = FALSE;
            break;
    }
}

KeyPress * CScene::GetKeyPressed()
{
    return &m_actualKey;
}
