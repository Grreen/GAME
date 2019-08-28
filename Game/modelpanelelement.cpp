#include "modelpanelelement.h"
#include "castle.h"
#include "unit.h"


ModelPanelElement::ModelPanelElement(QGraphicsObject *object):
    QGraphicsObject ()
{
    this->object = object;
    if(dynamic_cast<Castle*>(object))
        name_unit = "castle";
    else if(dynamic_cast<Unit*>(object))
        name_unit = "unit";
}

QRectF ModelPanelElement::boundingRect() const
{

}

void ModelPanelElement::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    if(name_unit == "castle")
    {
        Castle *castle = dynamic_cast<Castle*>(object);
        QPixmap pixmap = QPixmap("../Game/"+""+".png").scaled(size_object,size_object);
    }
}
