#ifndef CSTALKER_H
#define CSTALKER_H

#include <QtCore>
#include <QtGui>
#include <QObject>

enum State {STANDING, WALKING, JUMPING, FALLING};
enum Direction {LEFT, RIGHT};

class CStalker : public QObject
{
   Q_OBJECT

public:
    explicit CStalker(QObject *parent = 0);
    ~CStalker();

    QGraphicsPixmapItem *GetImage();
    void SetWalk(int iSpeed = 6, Direction side = RIGHT);
    void SetJump(int iSpeed = 6);


private:
    QGraphicsPixmapItem *m_imgStalker;  // actual image, loaded from sprite file
    int m_iHealth;
    int m_iRadiation;
    State m_actualState;
    int m_iWalkSpeed;
    int m_iJumpSpeed;
    int m_iMaxJump;

public slots:
    void HandleWalk();
    void HandleJump();
};

#endif // CSTALKER_H
