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

    int GetPosX() { return iPosX; };
    int GetPosY() { return iPosY; };
    const QImage GetImage() { return *imgStalker; };
    void Walk(Side orientation);
    void Jump();

private:
    int iPosX;
    int iPosY;

    QImage *imgStalker;
    int iHealth;
    int iRadiation;
    short int bJump;
    int maxJump;

public slots:
    void HandleJump();
};

#endif // CSTALKER_H
