#ifndef CELL_H
#define CELL_H
#include <QPixmap>
#include <QGraphicsScene>

#include <QGraphicsItem>
#include <iostream>

#include "drow.h"

class Cell : public Drow//Класс клетки
{
public:
    int x_center, y_center;//Координаты центра клетки
    int width;//Ширина клетки

    bool enemy = false;//Есть ли противник в клетке
};

#endif // CELL_H
