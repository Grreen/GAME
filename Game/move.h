#ifndef MOVE_H
#define MOVE_H

#include "map.h"

#include <QList>
#include <QPoint>

#include <iostream>

/**
 * @brief Класс перемещения
 * @details С помощью данного класса происходит перемещение юнитов,
 * а также отрисовка пути от начальной точки до конечной
 */
class Move
{
public:
//    QList <QPoint> list_point; почему то, если его использлвать то крашится прога
/**
 * @brief Функция поиска
 * @details Функция с помощью волнового алгоритма поиска кратчайшего пути в двоичном массиве
 * находит минимальный путь от начала до конца и заносит координаты клеток пути в массивы way_x и way_y
 * @param scene - сцена, где отрисовывается путь
 * @param first_coord - координаты начала
 * @param second_coord - коордмнаты конца
 * @param width_map - ширина карты
 * @param height_map - высота карты
 * @param count_steps - количество допустимых шагов юнита
 * @return true - если путь можно проложить, fslse - если нельзя проложить путь
 */
    bool next_cell(MyGraphicsScene*scene,QPoint first_coord, QPoint second_coord, int width_map, int height_map/*, int **array*/, int count_steps);//Переходим из одной клетки в другую
/**
 * @brief Функция передвижения юнита
 * @details Осуществялется перемещение от начальных координат к конечным по клеткам,
 * если на конечных координатах находится вражеский юнит или вражеский замок, то юнит дохожит до
 * предпоследней клетки и атакует(его количество шагов обнуляется),
 * если же юнит или замок союзные, то юнит также даходит до предпоследней клетки,
 * но не атакует и его шагов отнимается лишь пройденный путь
 * @param scene - сцена, где происходит перемещение
 * @param count_steps - количество допустимых шагов юнита
 * @param type_movement - тип перемещения : move,ally, attac unit, attack castle
 */
    void movement(MyGraphicsScene *scene, int count_steps, QString type_movement = "move");
    int steps;      ///< количество шагов на весь путь
private:
    int *way_x, *way_y;
/**
 * @brief Функция отрисовки пути по клеткам от начальных координат к конечным
 * @details Функция рисует путь по клеткам, с помощью зеленых линий,
 * если же путь бульше чем количесвто шагов у юнита, то оставшийся путь рисуется красными линиями
 * @param scene - сцена, где происходит перемещение
 * @param length - длина пути
 * @param coord_x - массив координат пути по оси X
 * @param coord_y - массив координат пути по оси Y
 * @param count_steps - количество шагов у юнита
 */
    void draw_way(MyGraphicsScene *scene, int length, int *coord_x, int *coord_y, int count_steps);
};

#endif // MOVE_H
