#ifndef GRAPHICSELLIPSEITEM_H
#define GRAPHICSELLIPSEITEM_H
#include <QGraphicsEllipseItem>

class GraphicsEllipseItem  : public QGraphicsEllipseItem
{
public:
    GraphicsEllipseItem(QGraphicsItem *parent = 0);
    GraphicsEllipseItem(QRectF &rect, QGraphicsItem *parent = 0);
    GraphicsEllipseItem(qreal x, qreal y, qreal width, qreal height, QGraphicsItem *parent = 0);
    ~GraphicsEllipseItem();
private:
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GRAPHICSELLIPSEITEM_H
