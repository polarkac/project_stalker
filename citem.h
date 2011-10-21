#ifndef CITEM_H
#define CITEM_H

#include <QObject>
#include <QtCore>
#include <QtGui>
#include <QString>
#include "cscene.h"

enum Types {ITEM, EMPTY, BACKGROUND};

class CItem : public QObject
{
    Q_OBJECT
public:
    explicit CItem(QObject *parent = 0);
    ~CItem();
    void SetItem(QString filename, int iPosX, int iPosY, int iZValue, Types itemType = ITEM);

private:
    QGraphicsPixmapItem * m_imgItem;
    Types m_itemType;
};

#endif // CITEM_H
