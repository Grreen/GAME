#ifndef DROW_H
#define DROW_H

#include <QGraphicsScene>
#include <QString>

class Drow//Класс отрисовки
{
public:
    void drow(QGraphicsScene *scene , QString name_pixmap, int x, int y, int width_item);//рисуем объект на сцене
//    void drow(Unit unit);
};

#endif // DROW_H
