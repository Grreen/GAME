#ifndef DROW_H
#define DROW_H

#include <QGraphicsScene>
#include <QString>

/**
 * @brief Класс отрисовки на сцене объекта
 * @details С помощью класса отрисовывается элемент на сцене,
 * использую коордмнаты и имя картинки, а также размер будущего изображения
 */
class Drow//Класс отрисовки
{
public:
/**
 * @brief Функция отрисовки объекта
 * @param scene - графическая сцена, на которой будет нартсован объект
 * @param name_pixmap - имя картинки
 * @param x - координата по оси Х
 * @param y - координаты по оси Y
 * @param width_item - размер, будущего объекта
 */
    void drow(QGraphicsScene *scene , QString name_pixmap, int x, int y, int width_item);//рисуем объект на сцене
};

#endif // DROW_H
