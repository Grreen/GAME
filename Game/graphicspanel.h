#ifndef GRAPHICSPANEL_H
#define GRAPHICSPANEL_H
#include <QGraphicsScene>
#include "player.h"
#include "castle.h"
#include "unit.h"

/**
 * @brief Переопределенный класс от QGraphicsScene
 * @details Класс создает виджет для отображения сцены,
 * на которой размещены миниатюры всех юнитов игрока,
 * который ходит
 */
class GraphicsPanel : public QGraphicsScene
{
    Q_OBJECT
public:
/**
 * @brief Конструктор
 * @param parent - родитель
 */
    explicit GraphicsPanel(QObject *parent = 0);
/**
 * @brief Функция обновляет данны в сцене для игрока
 * @details Осуществляется отображение в сцене всех юнитов
 * и их здоровья на графической сцене
 * @param player - ссылка на игрока, который ходит
 */
    void refresh_panel(Player *player);
/**
 * @brief Функция обновляет данные выбранного юнита
 * @param unit - ссылка на выбранного юнита
 */
    void refresh_data(Unit *unit);
private:
    QList <QGraphicsObject*> list_objects;  ///< список всех объектов на сцене
    QGraphicsScene *scene;                  ///< ссылка на графическую сцену
/**
 * @brief Функция обработки нажатия на кнопку мыши
 * @details Если на объект нажали один раз левой кнопкой мыши, то камера переместится к объекту(на главной сцене)
 * @param QGraphicsSceneMouseEvent
 */
    virtual void mousePressEvent(QGraphicsSceneMouseEvent  *event);
/**
 * @brief mouseDoubleClickEvent
 * @details Eсли на объект был произведен double click лувой кнопки мыши,
 * то произойдёт выделение объекта(на главной сцене), если это юнит,
 * а если это замок, то откроется окно покупки юнитов
 * @param QGraphicsSceneMouseEvent
 */
    virtual void mouseDoubleClickEvent (QGraphicsSceneMouseEvent * mouseEvent);
};

#endif // GRAPHICSPANEL_H
