#ifndef MOVE_H
#define MOVE_H
#include <QPoint>

class Move
{
    void next_cell(QPoint first_coord, QPoint second_coord);
    void drow_way(QPoint first_coord, QPoint second_coord);
};

#endif // MOVE_H
