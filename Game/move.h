#ifndef MOVE_H
#define MOVE_H

#include "map.h"

#include <QList>
#include <QPoint>

#include <iostream>
class Move//Класс перемещения
{
public:
//    QList <QPoint> list_point; почему то, если его использлвать то крашится прога
    bool next_cell(MyGraphicsScene*scene,QPoint first_coord, QPoint second_coord, int width_map, int height_map, int **array, int count_steps);//Переходим из одной клетки в другую
    void movement(MyGraphicsScene *scene, int count_steps, QString type_movement = "move");
    void movement_attack(MyGraphicsScene *scene, int count_steps);
    int steps;
private:
    int *way_x, *way_y;
    void draw_way(MyGraphicsScene *scene, int length, int *coord_x, int *coord_y, int count_steps);//Отрисовка пути по клеткам
};

#endif // MOVE_H
