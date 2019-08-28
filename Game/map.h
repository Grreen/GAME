#ifndef MAP_H
#define MAP_H

#include <QPointF>
#include <QList>
#include <QGraphicsScene>
#include <QGraphicsSceneMouseEvent>
#include "mygraphicsscene.h"
#include "drow.h"


/**
 * @brief Класс карты
 * @details С помощью класса рисуется карта,
 * также она хранит массив свободный и занятых клеток
 */
class Map : public Drow
{
public:
    int width;              ///< количество клеток в ширину
    int height;             ///< количество клеток в высоту

    int **map;

    MyGraphicsScene *scene; ///< главная сцена

/**
 * @brief Функция отрисовки карты
 * @details Функция сначала читает файл, в которм содержатся id клеток,
 * затем рисует карту по id(напрример: 01 - земля, 02 - вода),
 * также в массив map заносятся значения:
 * -1 (нельзя пройти по данной клетке)
 * -2 (можно пройти по данной клетке)
 * -3 (в данной клетке юнит)
 */
    void drow_map();
public slots:
};

#endif // MAP_H
