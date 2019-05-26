#ifndef MAP_H
#define MAP_H
#include "cell.h"
#include <QGraphicsScene>

class Map
{
public:
    int coint_in_width;
    int count_in_height;

    QList <Cell> list_cells;

    QGraphicsScene *scene = new QGraphicsScene;

    void drow_map();
};

#endif // MAP_H
