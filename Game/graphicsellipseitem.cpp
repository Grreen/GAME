#include "graphicsellipseitem.h"

GraphicsEllipseItem::GraphicsEllipseItem(QGraphicsItem *parent)
    :QGraphicsEllipseItem (parent)
{

}

GraphicsEllipseItem::GraphicsEllipseItem(QRectF &rect, QGraphicsItem *parent):
    QGraphicsEllipseItem (rect, parent)
{

}

GraphicsEllipseItem::GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent):
    QGraphicsEllipseItem (x,y,width,height,parent)
{

}

GraphicsEllipseItem::~GraphicsEllipseItem()
{

}

QRectF GraphicsEllipseItem::boundingRect() const
{
    return QRectF(0,0,0,0);
}

void GraphicsEllipseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

}
