#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QPixmap>
#include <QGraphicsItem>
#include "unit.h"
#include "castle.h"


/**
 * @brief Класс игрока
 * @details В классе находится список указателей на всех юнитов игрока,
 * а также указатель на замок игрока, имя, картинку, количество монет и номер игрока
 */
class Player
{
public:
    QString Name;               ///< имя игрока
    QPixmap image;              ///< картинка игрока
    int count_money;            ///< количество монет у игрока
    int nomber_player;          ///< номер игрока

    QList <Unit*> list_units;   ///< спиосок указателей на всех юнитов игрока

    Castle *castle;             ///< указатель на замок игрока

    bool live = true;           ///< жив ли игрок
    bool move = false;          ///< ходит ли данный игрок

/**
 * @brief Функция добавления юнита в list_units
 * @details Осуществляется добавления бнита со своими параметрами (зависят от id_unit)
 * на определенный координаты на графической сцене
 * @param x - координата по оси X
 * @param y - координата по оси Y
 * @param id_unit - индентификатор юнита
 * @param scene - граифческая сцена, на которой будет размещен юнит
 */
    void addUnit(int x, int y, int id_unit, MyGraphicsScene *scene);
/**
 * @brief Функция обновляетс все данные юнита
 */
    void refreshUnits();
/**
 * @brief Функция поиска юнита, который ходит
 * @return Указатель на юнита
 */
    Unit* move_unit();
};

#endif // PLAYER_H
