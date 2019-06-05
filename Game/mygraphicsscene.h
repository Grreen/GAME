#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsItem>
#include <QObject>

#include <iostream>

class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsScene *scene;
    int size_items;
    QGraphicsItemGroup *group_line = NULL;
    QList <QGraphicsItem*> line_group;
    bool way_drow = false;
    QPointF coord_first; //выбранные первые координаты
private:

    QPointF coord_second;//Вторые координаты
    QGraphicsObject *unit_inst;

    virtual void mousePressEvent(QGraphicsSceneMouseEvent  *event);
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
    bool chooseUnit();
    bool chooseCastle(QGraphicsObject *castle);
private slots:
    void delete_first_line();
    void delete_all_line();
    void enable_scene();
};

#endif // MYGRAPHICSSCENE_H
