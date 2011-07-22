#include "cstalker.h"

CStalker::CStalker()
{
    iPosX = 50;
    iPosY = 600;
    imgStalker = new QImage(":/images/online");
}

void CStalker::Walk(Side orientation)
{
    switch(orientation)
    {
    case LEFT:
        iPosX -= 5; break;
    case RIGHT:
        iPosX += 5; break;
    }
}
