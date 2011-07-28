#ifndef CSTALKER_H
#define CSTALKER_H

#include <QtCore>
#include <QtGui>
#include <QObject>

enum State {LEFT, RIGHT, JUMP, CROUCH};

class CStalker : public QObject
{
   Q_OBJECT

public:
    explicit CStalker();
    ~CStalker();

    QGraphicsPixmapItem *GetImage();
    void Walk();

private:
    int m_iPosX;
    int m_iPosY;
    QGraphicsPixmapItem *m_imgStalker;
    int m_iHealth;
    int m_iRadiation;
    State m_actualState;
    QTimeLine *timer;
    QGraphicsItemAnimation *animation;

public slots:
};

#endif // CSTALKER_H
