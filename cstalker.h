#ifndef CSTALKER_H
#define CSTALKER_H

#include <QtCore>
#include <QtGui>

enum Side {LEFT, RIGHT};

class CStalker
{
public:
    CStalker();
    ~CStalker();

    int GetPosX() { return iPosX; };
    int GetPosY() { return iPosY; };
    const QImage GetImage() { return *imgStalker; };
    void Walk(Side orientation);
    void Jump() {};

private:
    int iPosX;
    int iPosY;

    QImage *imgStalker;
    int iHealth;
    int iRadiation;
};

#endif // CSTALKER_H
