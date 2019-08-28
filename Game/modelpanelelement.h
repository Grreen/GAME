#ifndef MODELPANELELEMENT_H
#define MODELPANELELEMENT_H
#include <QGraphicsObject>

class ModelPanelElement : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit ModelPanelElement(QGraphicsObject *object);
private:
    QGraphicsObject *object;
    QString name_unit;
    virtual QRectF boundingRect() const;
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // MODELPANELELEMENT_H
