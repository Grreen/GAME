#ifndef CASTLE_H
#define CASTLE_H
#include <QPixmap>

#include "drow.h"

class Castle : public Drow
{
    int x_min, x_max;
    int y_min, y_max;
    float health;
    QPixmap image;


    void drow_castle();
};

#endif // CASTLE_H
