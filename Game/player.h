#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QPixmap>
#include <QGraphicsItem>
#include "unit.h"
#include "castle.h"

class Player : public Drow//Класс игрока
{
public:
    QString Name;//Имя игрока
    QPixmap image;//Картинка игрока
    int count_money = 1000;
    int nomber_player;

    QList <Unit*> list_units;//Список всех юнитов

    Castle *castle;//Замок

    bool live = true; //Жив ли игрок
    bool move = false; //Ход этого ли игрока

    void addUnit(int x, int y, QString id_unit, MyGraphicsScene *scene);
};

#endif // PLAYER_H
