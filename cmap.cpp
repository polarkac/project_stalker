#include "cmap.h"
#include <QtGui>
#include "citem.h"

cMap::cMap()
{
}

bool cMap::loadMap(QString path){
   m_mapPath = path;

   //load file
   //file structure:
       // name;info;width;backround;item_1;item_2;...item_n;
   QFile file(m_mapPath);
   int i;
   QList <QString> itemsInStr, members, bgInStr,membersInItems;
   QString data, filePath;

   //control if can work with file
   if(!file.open(QFile::ReadOnly | QFile::Text))
       return false;

   data = file.readAll();

   file.close();

   members = data.split(";");

   //control basics
   if(members[0] == "")
       return false;
   m_mapName = members[0];
   m_info = members[1];

   //width
   bool ok;
   m_sceneWidth = members[2].toInt(&ok , 10);
   if(!ok)
       return false;

   //background
   bgInStr = members[3].split(",");
   m_bgPath = bgInStr[0];
   m_bgRepeat = bgInStr[1].toInt(&ok, 10);


   //get all items
   i = 4;
   while(members[i] != ""){
       itemsInStr.append(members[i++]);
   }
   m_itemsPath.clear();

   for(i = 0 ; i < itemsInStr.count() ; i++){
       membersInItems = itemsInStr[i].split(",");
       m_itemsPath.append(membersInItems[0]);

       m_itemsX.append(membersInItems[1].toInt(&ok, 10));
       m_itemsY.append(membersInItems[2].toInt(&ok, 10));
       m_itemsZ.append(membersInItems[3].toInt(&ok, 10));
   }
   filePath = m_mapPath;
   QString imageFolderPath = filePath.remove(".map",Qt::CaseSensitive);
   imageFolderPath.append("_images/");
   QDir imageFolder;
   filePath.remove(filePath.split("/").last());
   filePath = filePath.left(filePath.count()-1);
   if(imageFolder.cd(imageFolderPath)){
       if(!m_bgPath.startsWith(":/images/",Qt::CaseSensitive)){
           m_bgPath = filePath + m_bgPath;
       }
       for(i = 0; i < m_itemsPath.count(); i++ ){
           if(!m_itemsPath[i].startsWith(":/images/",Qt::CaseSensitive)){
               m_itemsPath[i] = filePath + m_itemsPath[i];
           }
       }
   }

   return true;

}

bool cMap::mapToScene(){
    extern CScene *scene;
    QPixmap bg;
    bg.load(m_bgPath);
    int bgWidth = bg.width(), sceneWidth = scene->width(), bgRepeatCount = 0;
    //***************************
    //Tohle je zakomentované z důvodu kolize Hero s ostatnímy objekty na mapě
    //Nutnost zabezpečit kolizi pouze s objekty v stejné Z hodnotě
    //Kvůli pozadí pak hero zmizí ze scény  úplně až se vyřeší kolize může se
    //pozadí zobrazit odkomentováním téhle části
    //***************************
    /*for(int i = 0; i < sceneWidth; i+= bgWidth)
        bgRepeatCount++;
    CItem *background;
    background = new CItem[bgRepeatCount];
    if(m_bgRepeat == true){
        for(int i = 0, ii = 0; i < sceneWidth; i+= bgWidth, ii++)
            background[ii].SetItem(m_bgPath, i, 0, 1,BACKGROUND);
    }
    else
        background[0].SetItem(m_bgPath, 0, 0, 1, BACKGROUND);*/
    const int itemsCount = m_itemsPath.count();
    CItem *item;
    item = new CItem[itemsCount];
    for(int i = 0; i < itemsCount; i++)
        item[i].SetItem(m_itemsPath[i], m_itemsX[i], m_itemsY[i],m_itemsZ[i]);
}

