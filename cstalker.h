#ifndef CSTALKER_H
#define CSTALKER_H

#include <QtCore>
#include <QtGui>
#include <QObject>
#include "cscene.h"
#include "mainwindow.h"

enum State {STAND, WALK};
enum Direction {LEFT, RIGHT};
enum Jump {NOTHING, JUMPING, FALLING};

class CStalker : public QObject
{
   Q_OBJECT

public:
    explicit CStalker();
    ~CStalker();

    QGraphicsPixmapItem *GetImage();
    void SetWalk(bool bWalk, Direction side = RIGHT);
    void SetJump();
    int GetPosX() { return m_iPosX; };

private:
    int m_iPosX;
    int m_iPosY;
    QGraphicsPixmapItem *m_imgStalker;
    int m_iHealth;
    int m_iRadiation;
    State m_actualState;
    Direction m_actualSide;
    Jump m_actualJump;
    int m_iMaxJump;

public slots:
    void HandleWalk();
    void HandleJump();
};

#endif // CSTALKER_H
