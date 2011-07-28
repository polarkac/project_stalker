#ifndef CSCENE_H
#define CSCENE_H

#include <QGraphicsScene>
#include "cstalker.h"

class CScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CScene(QObject *parent = 0);

protected:
    void keyPressEvent(QKeyEvent *event);

signals:

public slots:

};

#endif // CSCENE_H
