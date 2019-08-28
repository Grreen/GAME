#include "drow.h"
#include <QGraphicsItem>
#include <QCursor>
#include <QPixmap>
#include <QGraphicsDropShadowEffect>
#include "game.h"

void Drow::drow(QGraphicsScene *scene, QString name_pixmap, int x, int y, int width_item)
{
    Game *game = Game::GetInstance();
    if(name_pixmap[0]!="0")
        name_pixmap = "0"+name_pixmap;
    QPixmap pixmap("../Game/"+name_pixmap+".png");
    pixmap = pixmap.scaled(width_item,width_item, Qt::IgnoreAspectRatio);
    QGraphicsPixmapItem *item = scene->addPixmap(pixmap);
    if(name_pixmap == "03")
    {
        item->setZValue(2);
        QGraphicsDropShadowEffect *bodyShadow = new QGraphicsDropShadowEffect;
        bodyShadow->setBlurRadius(10.0);
        bodyShadow->setColor(QColor(0, 0, 0, 160));
        bodyShadow->setYOffset(-2.0);
        bodyShadow->setXOffset(5.0);
        item->setGraphicsEffect(bodyShadow);

        QPixmap background_pixmap("../Game/01.png");
        background_pixmap = background_pixmap.scaled(width_item,width_item, Qt::IgnoreAspectRatio);
        QGraphicsPixmapItem *new_item = scene->addPixmap(background_pixmap);
        new_item->setPos(x,y);
        new_item->setEnabled(false);
    }
    item->setPos(x,y);
    item->setEnabled(false);
}

