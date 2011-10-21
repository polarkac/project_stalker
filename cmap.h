#ifndef CMAP_H
#define CMAP_H

#include <QtGui>

class cMap
{
public:
    cMap();
    bool loadMap(QString path);
    bool mapToScene();

private:
    QString m_mapPath, m_mapName, m_sceneWidth, m_info, m_bgPath;
    QList <QGraphicsItem *> m_items;
    QList <QString> m_itemsPath;
    QList <int> m_itemsX, m_itemsY,m_itemsZ;
    bool m_bgRepeat;



};

#endif // CMAP_H
