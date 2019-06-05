#ifndef MAP_H
#define MAP_H
#include "cell.h"

#include <QPointF>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "mygraphicsscene.h"

class Map//Класс карты
{
public:
    int width;//Количество клеток в ширину
    int height;//Количество клеток в высоту

    int **map;

    QList <Cell> list_cells;//Список всех клеток

    MyGraphicsScene *scene;//Главная сцена

    void drow_map();//функция рисования карты
public slots:
};

#endif // MAP_H
