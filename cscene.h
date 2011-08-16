#ifndef CSCENE_H
#define CSCENE_H

#include <QGraphicsScene>
#include "cstalker.h"

struct KeyPress
{
    bool bLArrow;
    bool bRArrow;
    bool bLCtrl;
};

class CScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit CScene(QObject *parent = 0);

    KeyPress * GetKeyPressed();
    QTimer * GetTimer() { return m_timer; };

protected:
    void keyPressEvent(QKeyEvent *event);
    void keyReleaseEvent(QKeyEvent *event);

private:
    QTimer *m_timer;
    KeyPress m_actualKey;


signals:

public slots:

};

#endif // CSCENE_H
