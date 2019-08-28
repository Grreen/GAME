#ifndef MYGRAPHICSSCENE_H
#define MYGRAPHICSSCENE_H

#include <QGraphicsScene>
#include <QPointF>
#include <QGraphicsItem>

/**
 * @brief Переопределенный класс от QGraphicsScene
 * @details С помощью переопределенных функций можно выбирать
 * юнитов на сцене и прокладывать путь
 */
class MyGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
    QGraphicsScene *scene;              ///< указатель на графическую сцену
    int size_items;                     ///< размер объектов на сцене
    QList <QGraphicsItem*> line_group;  ///< группа линий (линии создаются при отрисовки пути)
    bool way_drow = false;              ///< нарисован ли путь
    QPointF coord_first;                ///< координаты в сцене полученные при последнем нажатии левой кнопки мыши на графическую сцену

/**
 * @brief Функция выбора замка
 * @details Убирается выделение юнита и отрисовка пути(если те имеются),
 * затем вызывается окно с покупкой юнитов
 */
    void chooseCastle();
/**
 * @brief Функция выбора юнита
 * @details Проверяется элемент находящийся на сцена под координатыми first_coord,
 * если там пусто или это вражеский юнит или заток, то юнит не выбирается, если союзный,
 * то производится выделение, затем можно перемещать юнита
 * @return true - если юнита выбран, fasle - если юнит не выбран
 */
    bool chooseUnit();
/**
 * @brief Функция поиска игрока, который ходит
 * @return Возвращает index игрока в списке игроков
 */
    int index_move_player();
/**
 * @brief Функция удаления нарисованного пути юнита
 */
    void delete_way();
/**
 * @brief Функция для получения указателя юнита, который был выбран ранее
 * @return Указатель на юнита
 */
    QGraphicsObject* GetUnitInst();
private:

    QPointF coord_second;                   ///< координаты в сцене полученные при последнем нажатии правой кнопки мыши на графическую сцену
    QGraphicsObject *unit_inst = 0;         ///< указатель на юнита, который был выбран до ранее
/**
 * @brief Функция обработки нажатия кнопки мыши
 * @details Осуществляется выбор юнита или замка, нажатием левой кнопки мыши
 * и отрисовка пути (если выбран юнит) при нажатии на правую кнопку мыши,
 * если нажатие было на пустое место, то выделение с юнита снимается(если то присутствовало)
 * @param QGraphicsSceneMouseEvent
 */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent  *event);
/**
 * @brief Функция обработки двойного нажатия кнопки мыши
 * @details Осуществляется перемещение юнита двойным нажатием на правую кнопку мыши
 * @param QGraphicsSceneMouseEvent
 */
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
private slots:
/**
 * @brief Функция удаляет первую линию отрисованного пути
 */
    void delete_first_line();
/**
 * @brief Функция удаляет все линии отрисованного пути
 */
    void delete_all_line();
/**
 * @brief Функция, которая делает главное окно неактивным
 */
    void enable_scene();
public slots:
/**
 * @brief Функция удаляет указатель на прелылубщего юнита
 */
    void delete_unit_inst();
};

#endif // MYGRAPHICSSCENE_H
