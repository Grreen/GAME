#ifndef PLAYER_H
#define PLAYER_H
#include <QString>
#include <QImage>
#include "unit.h"
#include "castle.h"

class Player : public Drow
{
    QString Name;
    QImage image;

    QList <Unit> list_units;//Список всех юнитов

    Castle castle;//Замок

    bool live = true; //Жив ли игрок
};

#endif // PLAYER_H
