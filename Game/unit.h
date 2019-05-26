#ifndef UNIT_H
#define UNIT_H
#include <QPixmap>
#include <QString>

#include <drow.h>
#include <move.h>

class Unit : public Drow, public Move
{
    int x,y;
    float health;
    float demage;

    QPixmap image;
    QString type;


    void attack();
};

#endif // UNIT_H
