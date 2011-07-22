#include "cstalker.h"

CStalker::CStalker()
{
    iPosX = 50;
    iPosY = 200;
    imgStalker = new QImage;
    imgStalker->load(":/images/online");
    bJump = FALSE;
}

CStalker::~CStalker()
{
    delete imgStalker;
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

void CStalker::HandleJump()
{
    if(bJump)
    {
        if(iPosY <= maxJump)
            bJump = 2;
        if(bJump == 1)
        {
            iPosY -= 5;
        }
        else if(bJump == 2)
        {
            iPosY += 5;
        }
        if(iPosY >= (maxJump + 100))
            bJump = 0;
    }
}

void CStalker::Jump()
{
    if(bJump > 0)
        return;
    maxJump = iPosY - 100;
    bJump = 1;
}
