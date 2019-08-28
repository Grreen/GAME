#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H
#include <QGraphicsView>
#include "mygraphicsscene.h"

/**
 * @brief Переопределенный класс от QGraphicsView
 * @details Является графической оболочкой для графической сцены
 * с откличенными ScrollBar'ами и без каких либо взаимодействий с мышью
 */
class GraphicsView : public QGraphicsView
{
    Q_OBJECT
public:
/**
 * @brief Конструктор (без ScrollBar)
 * @param parent - родитель
 */
    explicit GraphicsView(QWidget *parent = 0);
/**
 * @brief Функция перемещения главного окна
 * @details Осуществляется перемещение
 * QHorizontalScrollBar и QVerticalScrollBar
 * от первой координаты ко второй по прямой
 * за определенное время
 * @param tim - таймер, который вызывается через определенный промежуток времени перемещение одного и обоих ScrollBar'ов
 * @param time - время за которое положение должно изменится от первого ко второму
 * @param first_point - первые координаты
 * @param second_point - вторые координаты
 */
    void move_scrollBar(QTimer *tim, float time, QPoint first_point, QPoint second_point);

private:
    QGraphicsView *View;        ///< ссылка на виджет для отображения графической сцены
/**
 * @brief Функция отслеживания действия мыши
 * @details Функция пустая, чтобы не происходило никаких действий
 * @param QWheelEvent
 */
    virtual void wheelEvent(QWheelEvent *event);
/**
 * @brief Функция отслеживания нажатия клавишь
 * @details Функция пустая, чтобы не происходило никаких действий
 * @param QKeyEvent
 */
    virtual void keyPressEvent(QKeyEvent* event);
private slots:
/**
 * @brief Функция перемещения QVerticalScrollBar к коордмнатам y_center
 * @param y_center - коордмната конца пути по оси Y
 */
    void move_vertical_scrollBar_center(int y_center);
/**
 * @brief Функция перемещения QHorizontalScrollBar к коордмнатам x_center
 * @param x_center - коордмната конца пути по оси X
 */
    void move_horizontal_scrollBar_center(int x_center);
};

#endif // GRAPHICSVIEW_H
