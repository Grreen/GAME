#ifndef TRIANGLE_H
#define TRIANGLE_H


#include <QObject>
#include <QTimer>
#include <QGraphicsObject>

#define GO true
#define STOP false

class Triangle : public QGraphicsObject
{
    Q_OBJECT
public:
    explicit Triangle();

signals:

private:
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);


private:
    QTimer *gameTimer;      // Игровой таймер
    QPointF target;         // Положение курсора
    bool state;             // Статус идти/стоять

private slots:
    void slotGameTimer();   // Игровой слот
};

#endif // TRIANGLE_H
