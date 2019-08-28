#ifndef GRAPHICSUNIT_H
#define GRAPHICSUNIT_H

#include <QGraphicsObject>
#include "unit.h"
#include "unitsgraphicsscene.h"

class GraphicsUnit : public QGraphicsObject
{
public:
    explicit GraphicsUnit(Unit *unit, UnitsGraphicsScene *scene, int number,QObject *parent = 0);
//сделать обновление через функцию
private:
    Unit *unit;
    UnitsGraphicsScene *scene;
    int number;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // GRAPHICSUNIT_H
