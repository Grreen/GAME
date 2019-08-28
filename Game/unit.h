#ifndef UNIT_H
#define UNIT_H
#include <QPixmap>
#include <QString>
#include <QProgressBar>
#include <QGraphicsObject>
#include <QGraphicsDropShadowEffect>

#include "move.h"

/**
 * @brief Класс юнита
 * @details В кдассе хранятся все данные юнита:
 * здоровье, урое, количесво шагов, координаты, ...
 */
class Unit :public QGraphicsObject, public Move
{
    Q_OBJECT
public:
    QPoint coord;               ///< координаты юнита
    int health;                 ///< здоровье юнита
    int max_health;             ///< максимальное здоровье юнита
    int demage;                 ///< урон юнита
    int max_count_steps;        ///< количество клеток за ход
    int count_steps;            ///< количество оставшихся клеток за ход
    int choose_count_steps;     ///< длина выбранного пути
    int id_unit;                ///< индентификатор юнита
    int nomber_unit;            ///< номер юнита

    QPixmap image;              ///< картинка юнита


    bool choose_unit;           ///< выбран ли юнит
/**
 * @brief Конструктор
 * @details Осуществляется создание юнита с определенными хараетеристиками,
 * которые зависят от id_unit
 * @param point - координаты, где будет создан юнит
 * @param scene - графическая сцена, на которой будет создан юнит
 * @param id_unit - индентификатор юнита
 * @param parent - родитель
 */
    explicit Unit(QPoint point,MyGraphicsScene *scene, int id_unit,QObject *parent = 0);


private:
    int size_object;            ///< размер юнита
/**
* @brief Функция, которая устанавливает размер поля взаимодействия с юнитом
* @return QRectF - прямоугольник
 */
    virtual QRectF boundingRect() const;
/**
* @brief Функция отрисовки замка на сцене с полоской жизни
* @param QPainter
* @param const QStyleOptionGraphicsItem
* @param QWidget
*/
virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
/**
 * @brief Функция атаки
 * @details Вызывается, если был атакован юнит,
 * после вызова уменьшает количество здоровья
 * (зависит от того какой урон у аттакующего юнита),
 * если здоровье <= 0, то юнит уничтожается
 */
    void hit();
/**
 * @brief Функция изменения размеров юнита
 * @param size - будующий размер
 */
    void resize(int size);

};

#endif // UNIT_H
