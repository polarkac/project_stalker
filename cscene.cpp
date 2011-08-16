#include "cscene.h"

CScene::CScene(QObject *parent) :
    QGraphicsScene(parent)
{
    m_timer = new QTimer(this);
    m_timer->start(25);

    extern CStalker *hero;
    connect(m_timer, SIGNAL(timeout()), hero, SLOT(HandleWalk()));
    connect(m_timer, SIGNAL(timeout()), hero, SLOT(HandleJump()));

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
            hero->SetWalk(TRUE, RIGHT);
            m_actualKey.bRArrow = TRUE; break;
        case Qt::Key_Left:
            hero->SetWalk(TRUE, LEFT);
            m_actualKey.bLArrow = TRUE; break;
        case Qt::Key_Space:
            hero->SetJump();
    }
}

void CScene::keyReleaseEvent(QKeyEvent *event)
{
    extern CStalker *hero;
    switch(event->key())
    {
        case Qt::Key_Right:
            hero->SetWalk(FALSE);
            m_actualKey.bRArrow = FALSE; break;
        case Qt::Key_Left:
            hero->SetWalk(FALSE);
            m_actualKey.bLArrow = FALSE; break;
    }
}

KeyPress * CScene::GetKeyPressed()
{
    return &m_actualKey;
}
