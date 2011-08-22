#include "citem.h"

CItem::CItem(QObject *parent) :
    QObject(parent)
{
    m_imgItem = NULL;
    m_itemType = EMPTY;
}

CItem::~CItem()
{
    delete m_imgItem;
}

void CItem::SetItem(QString filename, int iPosX, int iPosY, int iZValue, Types itemType)
{
    m_imgItem = new QGraphicsPixmapItem;
    m_imgItem->setPixmap(QPixmap(filename));
    m_imgItem->setPos(iPosX, iPosY);
    m_imgItem->setZValue(iZValue);
    m_itemType = itemType;
    m_imgItem->setFlags(QGraphicsItem::ItemIsMovable);

    extern CScene *scene;
    scene->addItem(m_imgItem);
}
