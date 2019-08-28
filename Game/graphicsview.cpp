#include <QScrollBar>
#include <QTimer>
#include <QThread>

#include "graphicsview.h"
#include "mainwindow.h"
#include "game.h"

GraphicsView::GraphicsView(QWidget *parent):
    QGraphicsView (parent)
{
    View = new QGraphicsView(parent);
//    this->setOptimizationFlag(QGraphicsView::DontAdjustForAntialiasing);
//    this->setViewportUpdateMode(QGraphicsView::SmartViewportUpdate);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
}

void GraphicsView::move_scrollBar(QTimer *tim, float time, QPoint first_point, QPoint second_point)
{
    int x = second_point.x()-first_point.x();
    if(x>0)
        for (int x_i=0;x_i<=x;x_i++)
            tim->singleShot(x_i*(float)(time/(float)x),[this,first_point,x_i](){this->move_horizontal_scrollBar_center(first_point.x()+x_i);});
    else if(x<0)
        for(int x_i=0;x_i<=x*(-1);x_i++)
            tim->singleShot(x_i*(float)(time/(float)(x*(-1))),[this,first_point,x_i](){this->move_horizontal_scrollBar_center(first_point.x()-x_i);});

    int y = second_point.y()-first_point.y();
    if(y>0)
        for(int y_i=0;y_i<=y;y_i++)
            tim->singleShot(y_i*(float)(time/(float)y),[this,first_point,y_i](){this->move_vertical_scrollBar_center(first_point.y()+y_i);});
    else if(y<0)
        for(int y_i=0;y_i<=y*(-1);y_i++)
            tim->singleShot(y_i*(float)(time/(float)y*(-1)),[this,first_point,y_i](){this->move_vertical_scrollBar_center(first_point.y()-y_i);});
}

void GraphicsView::move_horizontal_scrollBar_center(int x_center)
{
    this->horizontalScrollBar()->setSliderPosition(x_center+Game::GetInstance()->map.scene->size_items/2-this->width()/2);
}

void GraphicsView::move_vertical_scrollBar_center(int y_center)
{
    this->verticalScrollBar()->setSliderPosition(y_center+Game::GetInstance()->map.scene->size_items/2-this->height()/2);
}

void GraphicsView::wheelEvent(QWheelEvent *event)
{
}

void GraphicsView::keyPressEvent(QKeyEvent* event)
{
}
