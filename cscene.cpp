#include "cscene.h"

CScene::CScene(QObject *parent) :
    QGraphicsScene(parent)
{

}

void CScene::keyPressEvent(QKeyEvent *event)
{
    extern CStalker *hero;
    if(event->key() == Qt::Key_Right)
    {
        hero->Walk();
    }
}
