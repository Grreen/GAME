#ifndef DATAGRAPHICSSCENE_H
#define DATAGRAPHICSSCENE_H

#include <QGraphicsScene>

#include "player.h"
#include "unit.h"

/**
 * @brief Класс отображения характиристики
 * и изобрадение выбранного юнита
 */
class DataGraphicsScene : public QGraphicsScene
{
    Q_OBJECT
public:
/**
 * @brief Конструктор
 * @details Создается графическая сцена,
 * а затем отображается на экране
 * @param parent - родитель
 */
    explicit DataGraphicsScene(QObject *parent =0);
/**
 * @brief Функция обновления сцены
 * @param player
 * @param type_object
 */
    void refresh_scene(Player *player, QString type_object = "unit");
private:

    QPixmap border_pixmap, attack_pixmap,heart_pixmap, money_pixmap, steps_pixmap; ///< картинки рамки, меча, сердца, монеты, ботинка
    QFont *font;                                                                   ///< шрифт
    Player *player = 0;                                                            ///< указатель на игрока, который ходит
    Castle *castle = 0;                                                            ///< указатель на замок игрока, который ходит
    QGraphicsScene *scene;                                                         ///< графическая сцена, на которой размещаются все объекты
/**
 * @brief Функция рисования фона
 * @details Рисуются все характеристики выбранного юнита и их иконки,
 * также рисуется изобрадение выбранного юнита
 * @param QPainter
 * @param QRectF
 */
    virtual void drawBackground(QPainter * painter, const QRectF & rect);
};

#endif // DATAGRAPHICSSCENE_H
