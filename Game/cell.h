#ifndef CELL_H
#define CELL_H
#include <QPixmap>
#include <QGraphicsScene>

#include "drow.h";

class Cell : public Drow
{
public:
    int x_center;
    int y_center;
    int width;

//    QPixmap image;

    bool enemy = false;//Есть ли противник в клетке
};

#endif // CELL_H
