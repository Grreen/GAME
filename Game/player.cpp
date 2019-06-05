#include "player.h"
#include "unit.h"
#include <QProgressBar>
#include <QPoint>

#include <iostream>

void Player::addUnit(int x, int y, QString id_unit, MyGraphicsScene *scene, int **array_map)
{
    QPoint point(x-50,y-50);
    Unit *unit = new Unit(point, scene, id_unit);
    unit->type = id_unit;//переделать

    unit->array_map = new int*[10];
    for (int i=0;i<10;i++)
        unit->array_map[i] = new int[10];

    for(int i=0;i<10;i++)
    {
        for(int j=0;j<10;j++)
        {
            unit->array_map[i][j] = array_map[i][j];
        }
    }
    list_units.append(unit);
}
