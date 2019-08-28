#include "unitsgraphicsscene.h"

UnitsGraphicsScene::UnitsGraphicsScene(QObject *parent) :
    QGraphicsScene ()
{
    scene = new QGraphicsScene(parent);
}

void UnitsGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event)
{

}

void UnitsGraphicsScene::mouseDoubleClickEvent(QGraphicsSceneMouseEvent *mouseEvent)
{
//сделать отображение юнитов в отдельом месте
}

void UnitsGraphicsScene::refreshScene()
{

}
