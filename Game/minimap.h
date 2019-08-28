#ifndef MINIMAP_H
#define MINIMAP_H

#include <QGraphicsObject>
#include "drow.h"

/**
 * @brief Класс миникарты
 * @details Данный класс отрисовывает миникарту
 */
class MiniMap : public Drow
{
public:
    QGraphicsScene *scene;      ///< Указатель на графическую сцену
/**
 * @brief Конструктор
 * @details Осуществляет отрисовку карты в сцене (scene)
 * @param parent - родитель
 */
explicit MiniMap(QObject *parent = 0);
private:
    int **map_array;            ///< массив id клеток
    int width, height;          ///< ширина, высота карты
};

#endif // MINIMAP_H
