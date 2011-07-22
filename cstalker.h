#ifndef CSTALKER_H
#define CSTALKER_H

#include <QtCore>
#include <QtGui>
#include <QObject>

enum Side {LEFT, RIGHT};

class CStalker : public QObject
{
   Q_OBJECT

public:
    explicit CStalker();
    ~CStalker();

    int GetPosX() { return m_iPosX; };
    int GetPosY() { return m_iPosY; };
    int GetWalk() { return m_iWalk; }
    const QImage GetImage() { return *m_imgStalker; };

    void Jump();
    void SetWalk(int iNewWalk);


private:
    int m_iPosX;
    int m_iPosY;

    QImage *m_imgStalker;
    int m_iHealth;
    int m_iRadiation;
    short int m_iJump;
    short int m_iWalk;
    int m_maxJump;

public slots:
    void HandleJump();
    void Walk();
};

#endif // CSTALKER_H
