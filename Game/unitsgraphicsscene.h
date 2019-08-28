#ifndef UNITSGRAPHICSSCENE_H
#define UNITSGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <unit.h>

class UnitsGraphicsScene : public QGraphicsScene
{
public:
    void refreshScene();
    explicit UnitsGraphicsScene(QObject *parent = 0);
private:
    QGraphicsScene *scene;
    virtual void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // UNITSGRAPHICSSCENE_H
