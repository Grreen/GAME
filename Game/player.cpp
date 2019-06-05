#include "player.h"
#include "unit.h"
#include <QProgressBar>
#include <QPoint>

#include <iostream>

void Player::addUnit(int x, int y, QString id_unit, MyGraphicsScene *scene)
{
    QPoint point(x-50,y-50);
    Unit *unit = new Unit(point, scene, id_unit);
    unit->type = id_unit;//переделать

    list_units.append(unit);
}
