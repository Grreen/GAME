#ifndef CASTLE_H
#define CASTLE_H
#include <QPixmap>
#include <QPoint>
#include <QGraphicsObject>

#include "mygraphicsscene.h"

/**
 * @brief Класс замка
 * @details Данный класс является графическим объектом (Замком),
 * с котором возможны некоторые действия
 */
class Castle : public QGraphicsObject
{
    Q_OBJECT
public:
    int health;         ///< Текущее здоровье замка
    int max_health;     ///< Максимальное здоровье замка
    QPoint coord;       ///< Координаты замка
    QString image_id;   ///< Индентификатор изображение замкa

/**
 * @brief Конструктор
 * @details Создается замок со своими коордмнатами и со своими характеристиками
 * @param scene - графическая сцена, на которую будет добавлен замок
 * @param coord_castle - координаты замка на сцене
 * @param id_image - индентификатор изображение замкa
 * @param parent - родитель
 */
    explicit Castle(MyGraphicsScene *scene,QPoint coord_castle, QString id_image,QObject *parent = 0);
private:
    int size_object;    ///< размер замка на сцене
/**
 * @brief Функция, которая устанавливает размер поля взаимодействия с замком
 * @return QRectF - прямоугольник
 */
    QRectF boundingRect() const;
/**
 * @brief Функция отрисовки замка на сцене с полоской жизни
 * @param QPainter
 * @param const QStyleOptionGraphicsItem
 * @param QWidget
 */
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
public slots:
/**
 * @brief Функция изменения размеров замка
 * @param size - будующий размер
 */
    void resize(int size);
/**
 * @brief Функция атаки
 * @details Вызывается, если был атакован замок,
 * после вызова уменьшает количество здоровья
 * (зависит от того какой урон у аттакующего юнита),
 * если здоровье <= 0, то замок уничтожается
 */
    void hit();
};

#endif // CASTLE_H
