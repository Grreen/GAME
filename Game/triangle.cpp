#include "triangle.h"

Triangle::Triangle()
    : QGraphicsObject()
{
    setRotation(0);

    state = STOP;

    gameTimer = new QTimer();   // Инициализируем игровой таймер
    // Подключаем сигнал от таймера и слоту обработки игрового таймера
    connect(gameTimer, &QTimer::timeout, this, &Triangle::slotGameTimer);
    gameTimer->start(5);   // Стартуем таймер
}

QRectF Triangle::boundingRect() const
{
    return QRectF(-12,-15,24,30);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    // Отрисовка треугольника
    QPolygon polygon;
    polygon << QPoint(0,-15) << QPoint(12,15) << QPoint(-12,15);

    Q_UNUSED(option);    Q_UNUSED(widget);
}
