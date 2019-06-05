#ifndef CASTLE_H
#define CASTLE_H
#include <QPixmap>
#include <QPoint>
#include <QGraphicsObject>

#include "mygraphicsscene.h"

class Castle : public QGraphicsObject
{
//    Q_OBJECT
public:
    int health;//Здоровье замка
    int max_health;

    explicit Castle(MyGraphicsScene *scene,QPoint coord_castle, QString id_image,QObject *parent = 0);
    void hit(int demage);

private:
    QPoint spawnPos;
    QString image_id;//изображение замкa
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // CASTLE_H
