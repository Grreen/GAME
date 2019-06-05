#ifndef UNIT_H
#define UNIT_H
#include <QPixmap>
#include <QString>
#include <QProgressBar>
#include <QGraphicsObject>

#include "move.h"

class Unit :public QGraphicsObject, public Move
{
    Q_OBJECT
public:
    QPoint coord;//Координаты юнита
    int health;//Здоровье юнита
    int max_health;//Максимальное здоровье юнита
    int demage;//Урон юнита
    int max_count_steps;//Количество клеток за ход
    int count_steps;//Количество оставшихся клеток за ход
    int choose_count_steps;//длина выбранного пути

    QPixmap image;//Картинка юнита
    QString type;//Тип юнита (ближний или дальний)

    bool choose_unit;//выбран ли юнит

    explicit Unit(QPoint point,QGraphicsScene *scene, QString id_unit,QObject *parent = 0);

//    void hit(int at_demage);//Функция атаки юнита

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

public slots:
    void hit();

};

#endif // UNIT_H
